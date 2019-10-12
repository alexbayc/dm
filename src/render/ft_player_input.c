#include "engine.h"


void	ft_rotate(t_engine *e, int x, int y)
{
	e->player.angle = e->player.angle + (x * 0.1f);
	if (e->player.angle >= 360)
		e->player.angle = 0;
}

void	ft_horizon(t_engine *e, int x, int y)
{
	e->player.h_l = e->player.h_l + (-y * 0.3f);
	if (e->player.h_l > H / 2)
		e->player.h_l = H / 2;
	else if (e->player.h_l < -(H / 2))
		e->player.h_l = -H / 2 + 1;

}


void	ft_mouse_game(t_engine *e)
{
	int	x;
	int	y;
	int	mask;
	static int i;

	mask = SDL_GetRelativeMouseState(&x, &y);
	if (e->mouse_iter == 0)
	{
		x = 0;
		y = 0;
	}
	ft_horizon(e, x, y);
	ft_rotate(e, x, y);
	e->mouse_iter++;
	if (e->mouse_iter == 2147483646)
		e->mouse_iter = 1;
}
