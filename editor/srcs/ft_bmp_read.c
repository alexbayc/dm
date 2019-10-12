#include "doom.h"

static void	ft_load_bmp_to_surface(int fd, t_bmp b, SDL_Surface *sur)
{
	int		x;
	int		y;
	int		res;
	char	*tmp;

	y = -1;
	while (++y < b.bi_height)
	{
		x = -1;
		while (++x < b.bi_width)
		{
			read(fd, &res, b.bi_bit_count / 8);
			ft_surface_set_pixel(sur, b.bi_width - x,
				b.bi_height - y, res);
		}
	}
}

static void	ft_read_header_values(int fd, t_bmp *b)
{
	int		*tmp;
	read(fd, &(b->bf_type), 2);
	read(fd, &(b->bf_size), 4);
	read(fd, &(b->bf_reserved), 4);
	read(fd, &(b->bf_off_bits), 4);
	read(fd, &(b->bi_size), 4);
	read(fd, &(b->bi_width), 4);
	read(fd, &(b->bi_height), 4);
	read(fd, &(b->bi_planes), 2);
	read(fd, &(b->bi_bit_count), 2);
	read(fd, &(b->bi_compression), 4);
	read(fd, &(b->bi_size_image), 4);
	read(fd, &(b->bi_x_pels_per_meter), 4);
	read(fd, &(b->bi_y_pels_per_meter), 4);
	read(fd, &(b->bi_color_used), 4);
	read(fd, &(b->bi_color_important), 4);
	tmp = ft_memalloc(sizeof(int) * (b->bf_off_bits - 54));
	read(fd, tmp, b->bf_off_bits - 54);
	free(tmp);
}

SDL_Surface		*ft_bmp_read(t_doom *d, char *file)
{
	t_bmp	b;
	int		fd;
	int		res;
	SDL_Surface *surface;

	fd = open(file, O_RDONLY);
	ft_read_header_values(fd, &b);
	// printf("%x %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", b.bf_type, b.bf_size, b.bf_reserved, b.bf_off_bits, b.bi_size, b.bi_width, b.bi_height, b.bi_planes, b.bi_bit_count, b.bi_compression, b.bi_size_image,
	// 	b.bi_x_pels_per_meter, b.bi_y_pels_per_meter, b.bi_color_used, b.bi_color_important);
	if ((b.bf_type != 0x4d42 && b.bf_type != 0x4349 && b.bf_type != 0x5450) ||
		b.bf_reserved != 0 || b.bi_planes != 1 ||
		(b.bi_size != 40 && b.bi_size != 108 && b.bi_size != 124) ||
		b.bf_off_bits != 14 + b.bi_size ||
		b.bi_width < 1 || b.bi_width > 10000 ||
		b.bi_height < 1 || b.bi_height > 10000)
		ft_return("can't read BMP file");
	// printf("%d\n", b.bi_bit_count);
	surface = SDL_CreateRGBSurface(0, b.bi_width, b.bi_height,
		32, 0, 0, 0, 0);
	ft_load_bmp_to_surface(fd, b, surface);
	return (surface);
}
