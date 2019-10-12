
#include "doom.h"

int				ft_area_sec(t_points *a, t_points *b, t_points *c)
{
	return ((b->x - a->x) * (c->y - a->y) - (b->y - a->y) * (c->x - a->x));
}

int				ft_area(t_vector a, t_vector b, t_vector c)
{
	return ((b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x));
}

static int				ft_check_inter_lol(float a, float b, float c, float d)
{
	a += (fabs(b - a) / (b - a)) * 0.3f;
	b -= (fabs(b - a) / (b - a)) * 0.3f;
	if (a > b)
		ft_swap(&a, &b, sizeof(a));
	if (c > d)
		ft_swap(&c, &d, sizeof(c));
	return (fmax(a, c) < fmin(b, d));
}

int				ft_check_inter(int a, int b, int c, int d)
{
	if (a > b)
		ft_swap(&a, &b, sizeof(a));
	if (c > d)
		ft_swap(&c, &d, sizeof(c));
	return (fmax(a, c) <= fmin(b, d));
}

static int		ft_check_start_end(t_vector a, t_vector b, t_vector c,
							t_vector d)
{
	if (((a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y)) &&
		((b.x == c.x && b.y == c.y) || (b.x == d.x && b.y == d.y)))
		return (2);
	if (((a.x == c.x && a.y == c.y) || (a.x == d.x && a.y == d.y)) ||
		((b.x == c.x && b.y == c.y) || (b.x == d.x && b.y == d.y)))
		return (1);
	return (0);
}

static int		ft_if_intersect(t_vector a, t_vector b, t_vector c, t_vector d)
{
	int		contin;
	double	d1;
	double	d2;

	d1 = fabs((double)(a.x - b.x) / (a.y - b.y));
	d2 = fabs((double)(c.x - d.x) / (c.y - d.y));
	contin = 1;
	if (d1 == d2)
		if (ft_check_start_end(a, b, c, d) && (ft_check_inter_lol(a.x, b.x, c.x, d.x) || a.x - b.x == 0) && (ft_check_inter_lol(a.y, b.y, c.y, d.y) || a.y - b.y == 0) &&
			((((c.x - d.x) >> 31) ^ ((c.y - d.y) >> 31)) == (((a.x - b.x) >> 31) ^ ((a.y - b.y) >> 31)) || (a.x - b.x == 0) || (a.y - b.y == 0)))
				return (1);
		contin++;
	if (!((ft_area(a, b, c) * ft_area(a, b, d) > 0) ||
		(ft_area(c, d, a) * ft_area(c, d, b) > 0)))
	{
		if ((ft_area(a, b, c) * ft_area(a, b, d) < 0) &&
			(ft_area(c, d, a) * ft_area(c, d, b) < 0))
			return (1);
		else if ((ft_check_inter(a.x, b.x, c.x, d.x)
				&& ft_check_inter(a.y, b.y, c.y, d.y))
				&& (!(((ft_area(c, d, a) == 0) + (ft_area(c, d, b) == 0) +
					(ft_area(a, b, c) == 0) + (ft_area(a, b, d) == 0) <=
						2 * contin) && ft_check_start_end(a, b, c, d) >= 1)))
			return (1);
	}
	return (0);
}

int				ft_intersect(t_doom *f)
{
	t_line		*tmp;
	t_vector	a;
	t_vector	b;
	t_vector	c;
	t_vector	d;

	a.x = (int)(f->x_s / (int)(f->c * f->scale));
	b.x = (int)(f->x_e / (int)(f->c * f->scale));
	a.y = (int)(f->y_s / (int)(f->c * f->scale));
	b.y = (int)(f->y_e / (int)(f->c * f->scale));
	tmp = f->lines;
	while (tmp)
	{
		c.x = tmp->x_s;
		c.y = tmp->y_s;
		d.x = tmp->x_e;
		d.y = tmp->y_e;
		if (ft_if_intersect(a, b, c, d))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
