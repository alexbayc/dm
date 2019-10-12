#include "doom.h"

static void	ft_add_point_to_end(t_points *p, t_vert_lst *lst)
{
	t_intl	*tmp;

	if (!lst)
		return ;
	tmp = lst->head;
	if (!(lst->head))
	{
		lst->head = (t_intl *)ft_memalloc(sizeof(t_intl));
		lst->head->coord = p->x;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_intl *)ft_memalloc(sizeof(t_intl));
		tmp->next->coord = p->x;
	}
}

static void	ft_create_new_vert(t_vert_lst **lst, t_points *p)
{
	t_vert_lst	*tmp;

	if (!(*lst))
	{
		*lst = (t_vert_lst *)ft_memalloc(sizeof(t_vert_lst));
		(*lst)->vert = p->y;
		ft_add_point_to_end(p, *lst);
	}
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_vert_lst *)ft_memalloc(sizeof(t_vert_lst));
		tmp->next->vert = p->y;
		ft_add_point_to_end(p, tmp->next);
	}
}

t_vert_lst	*ft_split_on_vertex(t_doom *d)
{
	t_vert_lst	*tmp;
	t_vert_lst	*res;
	t_points	*p;

	res = NULL;
	ft_transform_to_points(d);
	p = d->point_lst;
	while (p)
	{
		tmp = res;
		while (tmp)
		{
			if (tmp->vert == p->y)
			{
				ft_add_point_to_end(p, tmp);
				break ;
			}
			tmp = tmp->next;
		}
		if (tmp == NULL)
			ft_create_new_vert(&res, p);
		p = p->next;
	}
	return (res);
}

void	ft_save_map_to_file(t_doom *d)
{
	t_vert_lst *lst;

	system("rm -f editor/logs.txt");
	system ("touch editor/logs.txt");
	d->output = open("editor/NESRAL.log", O_RDWR);
	lst = ft_split_on_vertex(d);
	ft_print_vertexes(d, lst);
	ft_print_sectors(d, lst);
	ft_print_player(d);
}