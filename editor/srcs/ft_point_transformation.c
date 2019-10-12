#include "doom.h"

void			ft_free_point_lst(t_points **head)
{
	t_points	*tmp;
	t_points	*next;

	tmp = *head;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*head = NULL;
}

static int		ft_check_point_lst(t_points **res, t_line *tmp, t_doom *d)
{
	int		ret;

	if (!(*res))
	{
		d->point_lst = ft_memalloc(sizeof(t_points));
		d->point_lst->x = tmp->x_s;
		d->point_lst->y = tmp->y_s;
		*res = d->point_lst;
		return (2);
	}
	ret = 3;
	while (1)
	{
		if ((*res)->x == tmp->x_s && (*res)->y == tmp->y_s)
			ret -= 1;
		else if ((*res)->x == tmp->x_e && (*res)->y == tmp->y_e)
			ret -= 2;
		if (!((*res)->next))
			break ;
		(*res) = (*res)->next;
	}
	return (ret);
}

void			ft_transform_to_points(t_doom *d)
{
	t_line		*tmp;
	t_points	*res;
	int			check_res;

	ft_free_point_lst(&d->point_lst);
	d->point_lst = NULL;
	tmp = d->lines;
	while (tmp)
	{
		res = d->point_lst;
		if ((check_res = ft_check_point_lst(&res, tmp, d)) & 1)
		{
			res->next = ft_memalloc(sizeof(t_points));
			res->next->x = tmp->x_s;
			res->next->y = tmp->y_s;
			res = res->next;
		}
		if (check_res & 2)
		{
			res->next = ft_memalloc(sizeof(t_points));
			res->next->x = tmp->x_e;
			res->next->y = tmp->y_e;
		}
		tmp = tmp->next;
	}
}
