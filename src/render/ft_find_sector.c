#include "engine.h"

static int	ft_if_intersect(float x, float y, t_xy p0, t_xy p1)
{
	float	a;
	float	b;
	float	c;
	float	res;

	a = p0.y - p1.y;
	b = p1.x - p0.x;
	c = p0.x * p1.y - p1.x * p0.y;
	if (a != 0)
	{
		res = (-b * y - c) / a;
		if (p0.x > p1.x)
			ft_swap(&p0, &p1, sizeof(t_xy));
		if (((res >= p0.x && res <= p1.x) || (fabs(p0.x - res) < 0.00000000001f)) &&
			(y >= p0.y && y <= p1.y ) && res > x)
			{
				// printf("%f %f\n", res, y);
			return (1);
			}
	}
	return (0);
}

int		ft_which_sector(t_engine *e, float x, float y)
{
	double	res;
	int		i;
	int		j;
	t_xy	fir;
	t_xy	sec;

	i = -1;

	while (++i < e->num_sectors)
	{
		j = -1;
		res = 0;
		while (++j < e->sectors[i].npoints)
		{
			//printf("x y (%f,%f),j+1 (%f, %f),  pl (%f, %f)\n", e->sectors[i].vertex[j].x, e->sectors[i].vertex[j].y,e->sectors[i].vertex[j + 1].x, e->sectors[i].vertex[j + 1].y,  e->player.where.x,e->player.where.y);
			//printf("fir (%f, %f), sec (%f, %f)\n", fir.x, fir.y, sec.x, sec.y);
			fir.x = e->sectors[i].vertex[j].x - x;
			fir.y = e->sectors[i].vertex[j].y - y;
			sec.x = e->sectors[i].vertex[j + 1].x - x;
			sec.y = e->sectors[i].vertex[j + 1].y - y;
			// printf("%f\n", ft_cross_product(fir.x, fir.y, sec.x, sec.y));
			res += (ft_cross_product(fir.x, fir.y, sec.x, sec.y) > 0) ?
				(ft_angle_vectors(fir.x, fir.y, sec.x, sec.y)) :
				(-ft_angle_vectors(fir.x, fir.y, sec.x, sec.y));
			// printf("%f\n", res);
		}

		 if (fabs(res) > 3.141592653589793238462643)
		 {
			 //printf("rez %f\n", fabs(res));
			// printf("plyer wich---------->%f %f %f %u %f\n", e->player.where.x,e->player.where.y, e->player.angle,  e->player.sector, e->player.where.z);
		 	return (i);
		 }
	}
	//printf("rez %f\n", fabs(res));
	//printf("plyer wich---------->%f %f %f %u %f\n", e->player.where.x,e->player.where.y, e->player.angle,  e->player.sector, e->player.where.z);
	// exit (1);
	return (-1);
}