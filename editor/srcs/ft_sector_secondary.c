#include "doom.h"

int		ft_check_line_points_repeat(t_doom *d)
{
	t_line	*last;
	t_line	*tmp;
	int		start;
	int		end;

	start = -1;
	end = -1;
	last = d->lines;
	while (last->next)
		last = last->next;
	tmp = d->lines;
	while (tmp)
	{
		if ((last->x_s == tmp->x_s && last->y_s == tmp->y_s) ||
			(last->x_s == tmp->x_e && last->y_s == tmp->y_e))
			start++;
		if ((last->x_e == tmp->x_s && last->y_e == tmp->y_s) ||
			(last->x_e == tmp->x_e && last->y_e == tmp->y_e))
			end++;
		tmp = tmp->next;
	}
	return (start < end ? start : end);
}

void	ft_points_lst_rev(t_sector_lst *sec)
{
	t_points	*prev;
	t_points	*cur;
	t_points	*next;

	prev = NULL;
	cur = sec->head;
	while (cur)
	{
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	sec->head = prev;
}

double	ft_is_sector_clockwise(t_sector_lst *sec)
{
	t_points	*cur;
	t_points	*next;
	int			len;
	double		res;

	res = 0;
	len = ft_sec_length(sec);
	cur = sec->head;
	next = sec->head->next;
	while (next->next)
	{
		if (ft_vector_product(next->x - cur->x, next->y - cur->y, next->next->x - next->x, next->next->y - next->y) > 0)
			res += ft_angle_vectors(next->x - cur->x, next->y - cur->y, next->next->x - next->x, next->next->y - next->y);
		else
			res -= ft_angle_vectors(next->x - cur->x, next->y - cur->y, next->next->x - next->x, next->next->y - next->y);
		cur = cur->next;
		next = cur->next;
	}
	if (ft_vector_product(next->x - cur->x, next->y - cur->y, sec->head->x - next->x, sec->head->y - next->y) > 0)
		res += ft_angle_vectors(next->x - cur->x, next->y - cur->y, sec->head->x - next->x, sec->head->y - next->y);
	else
		res -= ft_angle_vectors(next->x - cur->x, next->y - cur->y, sec->head->x - next->x, sec->head->y - next->y);
	return (res);
}

void	ft_add_point_to_lst(t_points **p, int x, int y)
{
	t_points	*tail;

	if (!*p)
	{
		*p = (t_points *)ft_memalloc(sizeof(t_points));
		(*p)->x = x;
		(*p)->y = y;
	}
	else
	{
		tail = *p;
		while (tail->next)
			tail = tail->next;
		tail->next = (t_points *)ft_memalloc(sizeof(t_points));
		tail->next->x = x;
		tail->next->y = y;
	}
}

t_sector_lst	*ft_create_last_sec(t_sector_lst **head)
{
	t_sector_lst	*tail;

	if (!*head)
	{
		*head = (t_sector_lst *)ft_memalloc(sizeof(t_sector_lst));
		return (*head);
	}
	else
	{
		tail = *head;
		while (tail->next)
			tail = tail->next;
		tail->next = (t_sector_lst *)ft_memalloc(sizeof(t_sector_lst));
		return (tail->next);
	}
	return (NULL);
}

t_points		ft_get_point_with_number(t_points *p, int num)
{
	int			i;

	i = 0;
	while (i < num)
	{
		i++;
		p = p->next;
	}
	return (*p);
}