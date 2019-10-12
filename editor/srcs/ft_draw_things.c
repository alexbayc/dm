#include "doom.h"

void	ft_draw_cursor_tex(t_doom *d, int size)
{
	SDL_Surface	*sur;
	int			i;
	int			j;
	int			x;
	int			y;

	if (!(d->flags & 1))
		return ;
	sur = d->textures[d->nb_tex_set];
	SDL_GetMouseState(&x, &y);
	x += 10;
	y += 10;
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_surface_set_pixel(d->sdl.sur_ptr, x + j, y + i, ft_texture_get_pixel(sur,
				j * sur->w / size, i * sur->h / size, 4));
	}
}

static void	ft_draw_last_line_help(t_doom *d)
{
	d->x_s = ft_where_point(d->x_s, d);
	d->x_e = ft_where_point(d->x_e, d);

	d->y_s = ft_where_point(d->y_s, d);
	d->y_e = ft_where_point(d->y_e, d);
	if (ft_intersect(d))
		ft_brasenham(d, 'M', 0xFF5555);
	else
		ft_brasenham(d, 'M', 0x55FF55);
}

void	ft_draw_last_line(t_doom *d)
{
	int x;
	int	y;

	d->x_s = d->line_x;
	d->y_s = d->line_y;
	if (!(d->flags & (1 << 1)))
		return ;
	x = d->sdl.event.button.x;
	y = d->sdl.event.button.y;
	if (x >= d->border)
		x = d->border;
	else if (x <= 0)
		x = 0;
	if (y >= d->height)
		y = d->height;
	else if (y <= 0)
		y = 0;
	d->x_e = x;
	d->y_e = y;
	ft_draw_last_line_help(d);
}

static void	ft_draw_player_fov(t_doom *d)
{
	float		rad;
	t_button	but;

	d->x_s = d->player->pos.x * (int)(d->c * d->scale);
	d->y_s = d->player->pos.y * (int)(d->c * d->scale);
	d->x_e = d->x_s + d->img.net.width * cos(ft_dig_to_rad(d->player->angle + D_FOV));
	d->y_e = d->y_s + d->img.net.width * sin(ft_dig_to_rad(d->player->angle + D_FOV));
	ft_coord_brasenham(d, 'M', 0x666666);
	d->x_e = d->x_s + d->img.net.width * cos(ft_dig_to_rad(d->player->angle - D_FOV));
	d->y_e = d->y_s + d->img.net.width * sin(ft_dig_to_rad(d->player->angle - D_FOV));
	ft_coord_brasenham(d, 'M', 0x666666);
	d->x_e = d->x_s + d->img.net.width * cos(ft_dig_to_rad(d->player->angle));
	d->y_e = d->y_s + d->img.net.width * sin(ft_dig_to_rad(d->player->angle));
	ft_coord_brasenham(d, 'M', 0xFF5555);
	d->x_e = d->x_s + d->img.net.width * cos(ft_dig_to_rad(d->player->angle + 90));
	d->y_e = d->y_s + d->img.net.width * sin(ft_dig_to_rad(d->player->angle + 90));
	ft_coord_brasenham(d, 'M', 0xFF5555);
	d->x_e = d->x_s + d->img.net.width * cos(ft_dig_to_rad(d->player->angle + 180));
	d->y_e = d->y_s + d->img.net.width * sin(ft_dig_to_rad(d->player->angle + 180));
	ft_coord_brasenham(d, 'M', 0xFF5555);
	d->x_e = d->x_s + d->img.net.width * cos(ft_dig_to_rad(d->player->angle + 270));
	d->y_e = d->y_s + d->img.net.width * sin(ft_dig_to_rad(d->player->angle + 270));
	ft_coord_brasenham(d, 'M', 0xFF5555);
}

void	ft_draw_player(t_doom *d)
{
	int		i;
	int		j;
	int		size;

	if (d->player->is == 0)
		return ;
	size = d->player->but.x_len;
	i = -1;
	j = -1;
	d->player->but.x = d->player->pos.x * (int)(d->c * d->scale) - d->player->but.x_len / 2;
	d->player->but.y = d->player->pos.y * (int)(d->c * d->scale) - d->player->but.y_len / 2;
	ft_draw_player_fov(d);
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1)
				ft_surface_set_pixel(d->sdl.sur_ptr, d->player->but.x + j, d->player->but.y + i, 0x5588FF);
			else
				ft_surface_set_pixel(d->sdl.sur_ptr, d->player->but.x + j, d->player->but.y + i, 0x000000);
		}
	}
}