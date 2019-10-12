#include "engine.h"

float	ft_modul(float x)
{
	if (x < 0)
		x = x * (-1);
	return (x);
}

void	ft_reverse_mas(double **ray, t_engine *e)
{
	int	i;
	double	*ray_new;

	i = 0;
	ray_new = (double *)ft_memalloc(sizeof(double) * (e->draw_in.w));
	if (!ray_new)
		ft_return("error: malloc");
		// printf("IN REVERSE\n\n");
	while (i < e->draw_in.w)
	{
		ray_new[e->draw_in.w - 1 - i] = (*ray)[i];
		// printf("ray_new i->%d, wall->%f, ray_old->%f\n", e->draw_in.w - 1 - i, ray_new[e->draw_in.w - 1 - i], (*ray)[i]);
		i++;
	}
	free(*ray);
	(*ray) = ray_new;
}



void	ft_printf(char *str, t_engine *e, int i)
{
	printf("%s\n", str);
	printf("pont (%f,  %f)\n",e->vert_new[i].x, e->vert_new[i].y);
	printf("angl->(%f, %f)\n", ft_rad_to_dig(e->draw_in.left),ft_rad_to_dig(e->draw_in.right));

}
