#include "doom.h"

void		ft_place_player(t_doom *d)
{
	if (d->sdl.event.button.x > d->img.net.width || d->sdl.event.button.y < 0 ||
		d->sdl.event.button.y > d->height || d->sdl.event.button.y < 0)
		{
			d->flags &= ~(1 << 3);
			ft_flag_draw(d);
			return ;
		}
	d->player->pos.x = ft_where_point(d->sdl.event.button.x, d) / (int)(d->c * d->scale);
	d->player->pos.y = ft_where_point(d->sdl.event.button.y, d) / (int)(d->c * d->scale);
	d->player->but.x_len = 6;
	d->player->but.y_len = 6;
	d->player->is = 1;
}

void		ft_change_player_angle(t_doom *d)
{
	d->player->angle += (d->sdl.event.button.x - d->mouse.x) / 10.f;
	d->mouse.x = d->sdl.event.button.x;
	d->mouse.y = d->sdl.event.button.y;
	ft_redraw(d);
}