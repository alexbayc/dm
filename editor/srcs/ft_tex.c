#include "doom.h"

static void		ft_change_wall_texture(t_doom *d, int x, int y)
{
	t_line		*wall;
	t_button	but;
	t_line		*res;

	wall = d->lines;
	res = NULL;
	if (d->nb_tex_set < d->nb_tex)
	{
		while (wall)
		{
			but = wall->but;
			if (x > but.x && x < but.x + but.x_len && y > but.y &&
				y < but.y + but.y_len)
				res = wall;
			wall = wall->next;
		}
	}
	if (res)
	{
		if (d->nb_tex_set < d->nb_tex - 1)
			res->texture = d->nb_tex_set;
		else
			res->portal = (res->portal + 1) % 2;
	}
}

void			ft_pick_texture(t_doom *d)
{
	int			i;
	int			x;
	int			y;
	t_button	but;

	x = d->sdl.event.button.x;
	y = d->sdl.event.button.y;
	i = -1;
	while (++i < 3)
	{
		but = d->tex_but[i];
		if (x > but.x && x < but.x + but.x_len
			&& y > but.y && y < but.y + but.y_len)
		{
			d->nb_tex_set = (i + d->nb_tex_off) % d->nb_tex;
			return ;
		}
	}
	ft_change_wall_texture(d, x, y);
}

void			ft_wall_texture(t_doom *d, int size, t_line *wall)
{
	int			i;
	int			j;
	SDL_Surface	*sur;

	sur = d->textures[wall->texture];
	wall->but.x = d->x_s + (d->x_e - d->x_s) / 2 - size / 2;
	wall->but.y = d->y_s + (d->y_e - d->y_s) / 2 - size / 2;
	wall->but.x_len = size;
	wall->but.y_len = size;
	d->x_e = d->x_s + size;
	d->y_e = d->y_s + size;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			
			if (!(wall->portal == 1 && i >= size / 3 && i <= size * 2 / 3))
				ft_surface_set_pixel(d->sdl.sur_ptr, j + wall->but.x,
					i + wall->but.y, ft_surface_get_pixel(sur,
						j * sur->w / size, i * sur->h / size));
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
				ft_surface_set_pixel(d->sdl.sur_ptr, j + wall->but.x, i + wall->but.y, (255 << 16 | 123 << 8 | 123));
		}
	}
}

static void		ft_draw_tex(t_doom *d, SDL_Surface *sur, int off_x, int off_y)
{
	int		x;
	int		y;
	int		height;
	int		width;

	height = off_y + d->height * 200 / 1300;
	width = off_x + (d->img.menu.width - d->width * 65 / 2500) / 3;
	y = off_y;
	while (++y < height)
	{
		x = off_x;
		while (++x < width)
		{
			if (x < width - 2)
				ft_surface_set_pixel(d->sdl.sur_ptr, x, y,
					ft_surface_get_pixel(sur, ((x - off_x) * sur->w / (width -
					off_x)), ((y - off_y) * sur->h / (height - off_y))));
			else
				ft_surface_set_pixel(d->sdl.sur_ptr, x, y, 0xFF5050);
		}
	}
}

void	ft_put_textures_to_menu(t_doom *d)
{
	int		i;
	int		off_x;
	int		off_y;

	i = -1;
	while (++i < 3)
	{
		off_x = d->img.net.width + d->width * 65 / 2500 / 2 +
			(d->img.menu.width - d->width * 65 / 2500) * i / 3;
		off_y = d->img.menu.height / 3 + d->height * 19 / 1300;
		d->tex_but[i].x = off_x;
		d->tex_but[i].y = off_y;
		d->tex_but[i].x_len = (d->img.menu.width - d->width * 65 / 2500) / 3;
		d->tex_but[i].y_len = d->height * 200 / 1300;
		ft_draw_tex(d, d->textures[(i + d->nb_tex_off) %
			d->nb_tex], off_x, off_y);
	}
}
