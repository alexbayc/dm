#include "doom.h"

void			ft_nb_tex(t_doom *d)
{
	int		fo;
	char	*nb;
	int		rez;

	fo = 0;
	rez = 0;
	if (system("sh editor/scripts/count_tex.sh") == -1)
		ft_return("error: cannot open script");
	if (system("sh editor/scripts/get_tex_name.sh") == -1)
		ft_return("error: cannot open script");
	fo = open("editor/script_rez/nb_tex", O_RDONLY);
	if (fo < 0)
		ft_return("error: can't open tex file");
	rez = get_next_line(fo, &nb);
	if (rez < 0)
		ft_return("error: incorrect tex file");
	d->nb_tex = ft_atoi(nb) + 1;
	printf("tex->%d\n", d->nb_tex);
	d->nb_tex_cost = 0;
	rez = get_next_line(fo, &nb);
	if (rez != 0)
		ft_return("error: incorrect tex file");
	free(nb);
	if (d->nb_tex <= 0)
		ft_return("error: i need textures");
	if (close(fo) == -1)
		ft_return("error: close fd");

}

static SDL_Surface	*ft_transform_bmp__to_texture(t_doom *d, SDL_Surface *bmp)
{
	int			i;
	int			j;
	int			scale;
	SDL_Surface	*tex;

	scale = bmp->w / d->tex_size;
	tex = SDL_CreateRGBSurface(0, d->tex_size, d->tex_size, 32, 0, 0, 0, 0);
	i = -1;
	while (++i < d->tex_size)
	{
		j = -1;
		while (++j < d->tex_size)
			ft_surface_set_pixel(tex, j, i, ft_texture_get_pixel(bmp, j * bmp->w / d->tex_size,
				i * bmp->h / d->tex_size, scale));
	}
	return (tex);
}

void			ft_read_textures(t_doom *d)
{
	int		i;
	char	*line;
	int		fo;
	int		rez;
	char	*to_free;

	fo = 0;
	i = -1;
	fo = open("editor/script_rez/name_tex", O_RDONLY);
	if (fo < 0)
		ft_return("error: can't open tex file");
	ft_putendl("Started reading textures\n");
	while (++i < d->nb_tex - 1)
	{
		rez = get_next_line(fo, &line);
		if (rez < 0)
			ft_return("error: incorrect tex file");
		ft_putstr(line);
		ft_putstr("        ");
		d->bmps[i] = ft_bmp_read(d, line);
		d->textures[i] = ft_transform_bmp__to_texture(d, d->bmps[i]);
		ft_putendl("finished");
		if (line)
			free(line);
		line = NULL;
	}
	d->bmps[i] = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);
	ft_surface_set_pixel(d->bmps[i], 0, 0, 0);
	d->textures[i] = d->bmps[i];
	if (close(fo) == -1)
		ft_return("error: close fd");
	free(line);
	ft_putendl("\nFinished reading textures");
}
