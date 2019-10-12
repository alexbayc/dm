#include "engine.h"

void	ft_print_t_xy_lst(t_xy *print, t_engine *e)
{
	int		i;
	double	angl;

	i = -1;
	while (++i <= e->sectors[e->draw_in.sector].npoints)
	{
		angl = acos((float)print[i].x /
			sqrt(pow((print[i].y), 2) + pow((e->vert_new[i].x), 2)));
		printf("x->%f y->%f, angl->%f\n", print[i].x, print[i].y, print[i].y < 0 ? -ft_rad_to_dig(angl) : ft_rad_to_dig(angl));
	}
}
