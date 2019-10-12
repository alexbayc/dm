#include "engine.h"

static void	ft_shot(t_engine *e)
{
	if (e->player.shoot >= 0 && e->player.shoot < 3)
	{
		e->player.shoot++;
		e->player.shot = 1;
	}
	else if (e->player.shoot > 2 && e->player.shoot < 5)
	{
		e->player.shoot++;
		e->player.shot = 2;
	}
	else if (e->player.shoot > 4 && e->player.shoot < 8)
	{
		e->player.shoot++;
		e->player.shot = 3;
	}
	else if (e->player.shoot > 7)
	{
		e->player.shot = 0;
		e->player.ammo--;
		e->player.shoot = 0;
		if (e->mus.shot != NULL)
			Mix_PlayChannel(-1, e->mus.shot, 0);
	}
}

void		ft_shotgun(t_engine *e)
{
	int				x;
	int				y;
	unsigned char	*c;

	y = -1;
	if (e->player.ammo <= 0)
		e->player.shot = 0;
	while (++y < e->shotgun[e->player.shot]->h)
	{
		x = -1;
		while (++x < e->shotgun[e->player.shot]->w)
		{
			c = (unsigned char *)&e->shotgun[e->player.shot]->
				img[x + y * e->shotgun[e->player.shot]->w];
			if (c[3] > 50)
			{
				ft_surface_set_pixel(e->sdl.sur_ptr, x + 570,
					e->shotgun[e->player.shot]->h - y - 1 + 580,
					e->shotgun[e->player.shot]->
						img[x + y * e->shotgun[e->player.shot]->w]);
			}
		}
	}
	if (e->player.shot)
		ft_shot(e);
}
