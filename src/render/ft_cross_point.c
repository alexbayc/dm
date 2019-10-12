#include "engine.h"
#include "for_norm_structs.h"

t_xy		*ft_cross_point(t_xy p0, t_xy p1, t_xy pr)
{
	t_xy	*a;
	double	p;
	double	q;

	if ((pr.x * p1.x + (-pr.y) * p1.y) * (pr.x * p0.x + (-pr.y) * p0.y) > 0)
		return (NULL);
	a = (t_xy *)ft_memalloc(sizeof(t_xy));
	p = p1.x - p0.x;
	q = p1.y - p0.y;
	if (!p)
	{
		a->x = p1.x;
		a->y = (pr.x * a->x) / pr.y;
		return (a);
	}
	else if (!q)
	{
		a->y = p0.y;
		a->x = (pr.y * a->y) / pr.x;
		return (a);
	}
	a->x = (-1 * p1.x * q + p1.y * p) / (p * (pr.x / pr.y - q / p));
	a->y = a->x * (pr.x / pr.y);
	return (a);
}
/*
	p - x координата направляющего вектора стены/портала
	q - у координата направляющего вектора стены/портала
*/
