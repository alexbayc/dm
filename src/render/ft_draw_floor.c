#include "engine.h"

void	ft_draw_floor(t_engine *e, double *ray)
{
	int	i;
	int	j;
	int	k;
	int		height;

	k = 0;
	i = e->draw_in.x_s;
	while (k < e->draw_in.w)
	{
		j = (int)(e->bot[i]);
		height = (e->draw_in.half + ray[k] / 2);
		while (j >= height && e->bot[i] != e->top[i])
		{
			ft_surface_set_pixel(e->sdl.sur_ptr, i, j, 0xE5FB71<<e->draw_in.sector);
			j--;
			e->bot[i]--;
		}
		k++;
		i++;
	}
}
