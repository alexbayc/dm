#include "doom.h"

int ft_where_point(int p, t_doom *f)
{
	int	x = p;
	int	r;
	int	l;
	int razl = 0;
	int razr = 0;

	l = 0;
	r = 0;
	if (x % (int)(f->c * f->scale) == 0)
		return (x);
	l = x / (int)(f->c * f->scale);
	r = l + 1;
	razl = x - (int)(f->c * f->scale) * l;
	razr = (int)(f->c * f->scale) * r - x;
	if (razl >= razr)
		x = r * (int)(f->c * f->scale);
	else
		x = l * (int)(f->c * f->scale);
	return (x);
}

int		ft_put_point(t_doom *f)
{
	int len;
	len = 0;
	if (f->x_s == f->x_e && f->y_e == f->y_s)
		return (1);

	f->x_s = ft_where_point(f->x_s, f);
	f->x_e = ft_where_point(f->x_e, f);

	f->y_s = ft_where_point(f->y_s, f);
	f->y_e = ft_where_point(f->y_e, f);
	if (ft_intersect(f))
		return (1);
	// printf("put point: x_s->%d, y_s->%d, x_e->%d, y_e->%d\n",f->x_s, f->y_s, f->x_e, f->y_e);
	if (f->x_s == f->x_e && f->y_e == f->y_s)
		return (1);
	ft_create_nodes(&(f->lines), f);
	printf("tail: x_s->%d, y_s->%d, x_e->%d, y_e->%d\n",f->tail->x_s, f->tail->y_s, f->tail->x_e, f->tail->y_e);
	fprintf(f->log_fd, "tail: x_s->%d, y_s->%d, x_e->%d, y_e->%d\n",f->tail->x_s, f->tail->y_s, f->tail->x_e, f->tail->y_e);
	len = ft_lst_len(f->lines);
	fprintf(f->log_fd, "lst len -> %d\n", len);
	ft_brasenham(f, 'N', 0);
	ft_draw_start_end(f, f->frame_size);
	return (0);
}
