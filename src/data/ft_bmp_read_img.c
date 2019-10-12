#include "engine.h"

static void	ft_load_bmp_to_surface(int fd, t_bmp b, t_img *img)
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
			img->img[x + y * b.bi_width] = res;
		}
	}
}

static void	ft_read_header_values(int fd, t_bmp *b)
{
	int		*tmp;

	read(fd, &(b->bf_type), 2);
	read(fd, &(b->bf_size), 4);
	read(fd, &(b->bf_reserved), 04);
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
	tmp = NULL;
}

t_img		*ft_bmp_read_img(char *file)
{
	t_bmp	b;
	int		fd;
	int		res;
	t_img	*img;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_return("error: img open");
	ft_read_header_values(fd, &b);
	if ((b.bf_type != 0x4d42 && b.bf_type != 0x4349 && b.bf_type != 0x5450) ||
		b.bf_reserved != 0 || b.bi_planes != 1 ||
		(b.bi_size != 40 && b.bi_size != 108 && b.bi_size != 124) ||
		b.bf_off_bits != 14 + b.bi_size ||
		b.bi_width < 1 || b.bi_width > 10000 ||
		b.bi_height < 1 || b.bi_height > 10000)
		ft_return("can't read BMP file");

	img = ft_memalloc(sizeof(t_img));
	img->h = b.bi_height;
	img->w = b.bi_width;
	img->img = (unsigned int *)ft_memalloc(sizeof(unsigned int)
		* (b.bi_width * b.bi_height));
	ft_load_bmp_to_surface(fd, b, img);
	return (img);
}
