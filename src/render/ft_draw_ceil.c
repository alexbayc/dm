#include "engine.h"

void	ft_draw_ceil(t_engine *e, double *ray)
{
	int		i;
	int		j;
	int		k;
	int		height;
	int		half;

	half = H / 2 + e->player.h_l;
	// half = (e->bot[e->draw_in.x_s] + e->top[e->draw_in.x_s]) / 2 + e->player.h_l;
	k = 0;
	i = e->draw_in.x_s;
	while (k < e->draw_in.w)
	{
		height = (half - ray[k] / 2);
		j = (int)(e->top[i]);
		while (j < height && e->bot[i] != e->top[i])
		{
			ft_surface_set_pixel(e->sdl.sur_ptr, i, j, 0x63ADD0<<e->draw_in.sector);
			j++;
			e->top[i]++;
		}
		i++;
		k++;
	}
}