#include "doom.h"

void	ft_change_net_scale(t_doom *d)
{
	if (d->sdl.event.wheel.y > 0)
		d->scale *= 1.1f;
	else if (d->sdl.event.wheel.y < 0)
		d->scale /= 1.1f;
}

void	ft_clear_net(t_doom *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->height)
	{
		x = 0;
		while (x < d->img.net.width)
		{
			if (x <= d->border)
				ft_surface_set_pixel(d->sdl.sur_ptr, x, y, 0);
			x++;
		}
		y++;
	}
	ft_net(d);
}

/* draw net */
void	ft_net(t_doom *d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < d->height)
	{
		x = 0;
		while (x < d->img.net.width)
		{
			if (x <= d->border)
			{
				if (((x % (int)(d->c * d->scale)) == 0))
					ft_surface_set_pixel(d->sdl.sur_ptr, x, y, d->color.set);
				if (((y % (int)(d->c * d->scale)) == 0))
					ft_surface_set_pixel(d->sdl.sur_ptr, x, y, d->color.set);
			}
			x++;
		}
		y++;
	}
}
