#include "engine.h"


void		ft_draw_portal_wall(t_engine *e, double *ray, int *walls, t_ijk ijk)
{
	int		lim;
	int		half;
	double s_h = ray[ijk.k];
	double w_h = e->sectors[e->draw_in.sector].ceil - e->sectors[e->draw_in.sector].floor;
	double k = s_h /  w_h;

	// half = (e->bot[ijk.i] + e->top[ijk.i]) / 2 + e->player.h_l;
	half = H / 2 + e->player.h_l;
	lim = lim > e->bot[ijk.i] ? e->bot[ijk.i] : lim;
	int razn_top = e->sectors[e->draw_in.sector].ceil - e->sectors[(int)walls[ijk.k]].ceil;
	int razn_bot = e->sectors[e->draw_in.sector].floor - e->sectors[(int)walls[ijk.k]].floor;
	if (razn_top > 0 || razn_bot < 0)
	{
		if (razn_bot < 0)
		{
			ijk.j = half + ray[ijk.k] / 2 + (razn_bot * k);
			lim = e->bot[ijk.i];
			while (ijk.j < lim && e->top[ijk.i] < e->bot[ijk.i])
			{
				ft_surface_set_pixel(e->sdl.sur_ptr, ijk.i, ijk.j,  0x111122<<(e->draw_in.sector * 10));
				ijk.j++;
				(e->bot[ijk.i])--;
			}
		}
		if (razn_top > 0)
		{
			ijk.j = e->top[ijk.i];
			lim = half - ray[ijk.k] / 2 + (razn_top * k);
			while (ijk.j < lim && e->top[ijk.i] < e->bot[ijk.i])
			{
				ft_surface_set_pixel(e->sdl.sur_ptr, ijk.i, ijk.j, 0x111122<<(e->draw_in.sector * 10));
				(e->top[ijk.i])++;
				ijk.j++;
			}
		}
	}
}
