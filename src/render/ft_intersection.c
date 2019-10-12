#include "engine.h"

static int	ft_area(t_xy a, t_xy b, t_xy c)
{
	return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

static int	ft_check_inter(double a, double b, double c, double d)
{
	if (a > b)
		ft_swap(&a, &b, sizeof(a));
	if (c > d)
		ft_swap(&c, &d, sizeof(c));
	return (fmax(a, c) <= fmin(b, d));
}

int			ft_intersect(t_xy a, t_xy b, t_xy c, t_xy d)
{
	return (ft_check_inter(a.x, b.x, c.x, d.x) &&
			ft_check_inter(a.y, b.y, c.y, d.y) &&
			ft_area(a, b, c) * ft_area(a, b ,d) <= 0 &&
			ft_area(c, d ,a) * ft_area(c, d, b) <= 0);
}
