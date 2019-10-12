#include "doom.h"

static void				ft_print_point_lst(t_points *head, t_doom *d)
{
	t_points	*tmp;

	tmp = head;
	while (tmp)
	{
		fprintf(d->log_fd, "x->%d, y->%d\n", tmp->x, tmp->y);
		tmp = tmp->next;
	}
}

void					ft_print_sector_lst(t_sector_lst *head, t_doom *d)
{
	t_sector_lst	*sec;


	sec = head;
	while (sec)
	{
		fprintf(d->log_fd, "\nSTARTED SECTOR\n");
		fprintf(d->log_fd, "%p\n\n", sec);
		ft_print_point_lst(sec->head, d);
		fprintf(d->log_fd, "valid-->%d\n", sec->valid);
		sec = sec->next;
	}
}

static void				ft_free_sector_lst(t_sector_lst *head)
{
	t_sector_lst	*next;

	while (head)
	{
		next = head->next;
		ft_free_point_lst(&(head->head));
		free(head);
		head = next;
	}
}

static int				ft_check_repeat(t_sector_lst *tmp, t_points *ptmp)
{
	t_points	*cur;

	if (!tmp || !tmp->head)
		return (0);
	cur = tmp->head;
	if (ptmp->x == cur->x && ptmp->y == cur->y)
		return (2);
	cur = cur->next;
	while (cur)
	{
		if (cur->x == ptmp->x && cur->y == ptmp->y)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static int				ft_check_connection(t_doom *d, t_sector_lst *sec, t_points *p)
{
	t_points	*arr;
	t_line		*lines;

	arr = sec->head;
	if (arr == NULL)
		return (1);
	while (arr->next)
		arr = arr->next;
	lines = d->lines;
	while (lines)
	{
		if (((arr->x == lines->x_s && arr->y == lines->y_s) ||
			(arr->x == lines->x_e && arr->y == lines->y_e)) &&
			((p->x == lines->x_s && p->y == lines->y_s) ||
			(p->x == lines->x_e && p->y == lines->y_e)))
			return (1);
		lines = lines->next;
	}
	return (0);
}

static void				ft_add_point_to_sector(t_sector_lst *lst, t_points *p)
{
	t_points	*tmp;
	t_points	*new;

	tmp = lst->head;
	new = ft_memalloc(sizeof(t_points));
	while (tmp && tmp->next)
		tmp = tmp->next;
	new->x = p->x;
	new->y = p->y;
	printf("added point to sector x->%d, y->%d\n", p->x, p->y);
	if (tmp == NULL)
		lst->head = new;
	else
		tmp->next = new;

}

static t_sector_lst		*ft_next_sector(t_sector_lst *lst)
{
	t_points		*old;
	t_points		*new;
	t_sector_lst	*new_lst;

	new_lst = ft_memalloc(sizeof(t_sector_lst));
	lst->next = new_lst;
	new = new_lst->head;
	old = lst->head;
	while (old)
	{
		ft_add_point_to_sector(new_lst, old);
		old = old->next;
	}
	return (new_lst);
}

int					ft_sec_length(t_sector_lst *lst)
{
	t_points	*p;
	int			i;

	i = 0;
	p = lst->head;
	while (p)
	{
		p = p->next;
		i++;
	}
	return (i);
}

static int				ft_sector_repeat(t_sector_lst *head, t_sector_lst *sec, t_doom *d)
{
	int				tmp;
	t_sector_lst	*cur_lst;
	t_points		*curp;
	t_points		*secp;

	cur_lst = head;
	while (cur_lst)
	{
		if (ft_sec_length(cur_lst) == ft_sec_length(sec) && cur_lst != sec)
		{
			tmp = 0;
			secp = sec->head;
			while (secp)
			{
				curp = cur_lst->head;
				while (curp)
				{
					if (curp->x == secp->x && curp->y == secp->y)
						tmp++;
					curp = curp->next;
				}
				secp = secp->next;
			}
			// printf("%d %d\n", tmp ,ft_sec_length(sec));
			if (tmp == ft_sec_length(sec))
				return (1);
		}
		cur_lst = cur_lst->next;
	}
	// printf("\n\n");
	return (0);
}

static int				ft_is_part_of_list(t_points	*head, int x, int y)
{
	while (head)
	{
		if (x == head->x && y == head->y)
			return (1);
		head = head->next;
	}
	return (0);
}

double					ft_vector_product(int x1, int y1, int x2, int y2)
{
	double	res;

	// if (((x1 == -1 || y2 == -1) && (x1 == DBL_MIN || y2 == DBL_MIN)) ||
	// 	(x1 > DBL_MAX / y2) || (x1 < DBL_MIN / y2) ||
	// 	((y1 == -1 || x2 == -1) && (y1 == DBL_MIN || x2 == DBL_MIN)) ||
	// 	(y1 > DBL_MAX / x2) || (y1 < DBL_MIN / x2))
	// 	ft_return("error in vector product: double overflow");
	res = x1 * y2 - y1 * x2;
	return (res);
}

double					ft_angle_vectors(int x1, int y1, int x2, int y2)
{

	return (acos((x1 * x2 + y1 * y2) / (sqrt(x1 * x1 +
		y1 * y1) * sqrt(x2 * x2 + y2 * y2))));
}

static double			ft_angle_vectors_dop(int x1, int y1, int x2, int y2)
{
	int		vec;
	double	res;

	vec = x1 * y2 - y1 * x2;
	if (vec > 0)
		vec = 1;
	else if (vec < 0)
		vec = -1;
	res = vec * ft_angle_vectors(x1, y1, x2, y2);
	return (res);
}

static int ft_check_inside_point(t_points *head_pts, t_points *allp, t_sector_lst *lst, t_doom *d)
{
	t_points	*curp;
	t_points	*secp;
	double		res;

	curp = d->point_lst;
	while (curp)
	{
		secp = lst->head;
		res = 0;
		if (!ft_is_part_of_list(lst->head, curp->x, curp->y))
		{
			while (secp->next)
			{
				res += ft_angle_vectors_dop(secp->x - curp->x, secp->y - curp->y,
					secp->next->x - curp->x, secp->next->y - curp->y);
				secp = secp->next;
			}
			res += ft_angle_vectors_dop(secp->x - curp->x, secp->y - curp->y,
				lst->head->x - curp->x, lst->head->y - curp->y);
			// if (fabs(1 - res / 2) < fabs(res / 2))
			// fprintf(d->log_fd, " \nx->%d, y->%d    %f\n",curp->x, curp->y, res);
			if (fabs(res) > 0.4f)
			{
				// printf("INSIDE POINT \n");
				return (1);
			}
		}
		curp = curp->next;
	}
	return (0);
}

// static int				ft_check_final(t_sector_lst *head, t_sector_lst *lst, t_points *ptmp, t_doom *d)
// {
// 	t_points	*tmp;

// 	tmp = lst->head;
// 	if (tmp == NULL)
// 		return (0);
// 	if (ft_sec_length(lst) < 3 || !(tmp->x == ptmp->x && tmp->y == ptmp->y))
// 		return (0);
// 	// fprintf(d->log_fd, "\nThis one got in final\n\n");
// //	ft_print_point_lst(lst->head, d);
// 	if ((ft_sector_repeat(head, lst)))
// 	{
// 		// fprintf(d->log_fd, "\nfailed because of repeat\n\n");
// 		return (0);
// 	}
	// if ((ft_check_inside_point(tmp, d->point_lst, lst, d))) //&&
		// !(ft_lines_inside_sector(tmp, d->lines)))
// 		{
// 			// fprintf(d->log_fd, "\nfailed because of inside point\n\n");
// 			return (0);
// 		}
// 	return (1);
// }

static void				ft_lst_del_last(t_sector_lst *tmp)
{
	t_points	*head;
	t_points	*prev;

	prev = NULL;
	if (tmp)
	{
		head = tmp->head;
		while (head->next)
		{
			prev = head;
			head = head->next;
		}
		free(head);
		if (prev != NULL)
			prev->next = NULL;
		else
		{
			// if (head)
				// free(head);
			tmp->head = NULL;
		}
	}
}

static int				ft_belong_to_last(t_points *p, t_doom *d)
{
	t_line	*line;

	line = d->lines;
	while (line->next)
		line = line->next;
	if ((p->x == line->x_s && p->y == line->y_s) || (p->x == line->x_e && p->y == line->y_e))
		return (1);
	return (0);
}

// static void				ft_sec_recursion(t_doom *d, t_sector_lst *head,
// 											t_sector_lst **tmp, int flag)
// {
// 	t_points	*ptmp;
// 	int			got;
// 	int			rep;

// 	got = 0;
// 	ptmp = d->point_lst;
// 	while (ptmp)
// 	{
// 		if ((!flag && ft_belong_to_last(ptmp, d)) || flag)
// 		{
// 			if ((rep = ft_check_repeat(*tmp, ptmp)) != 1)
// 				if ((ft_check_connection(d, *tmp, ptmp)))
// 				{
// 					if (rep == 2 && ft_check_final(head, *tmp, ptmp, d))
// 						*tmp = ft_next_sector(*tmp);
// 					else if (rep == 0)
// 					{
// 						ft_add_point_to_sector(*tmp, ptmp);
// 						ft_sec_recursion(d, head, tmp, flag + 1);
// 						ft_lst_del_last(*tmp);
// 					}
// 				}
// 		}
// 		ptmp = ptmp->next;
// 	}
// }

static int				ft_check_repeated_points(t_points *toch, t_points *ch)
{
	int				flag;
	t_points		*tmp;

	while (ch)
	{
		tmp = toch;
		flag = 0;
		while (tmp && !flag)
		{
			if (ch->x == tmp->x && ch->y == tmp->y)
				flag++;
			tmp = tmp->next;
		}
		if (flag == 0)
			return (0);
		ch = ch->next;
	}
	return (1);
}

static int				ft_check_little_sectors(t_points *toch,
									t_points *ch1, t_points *ch2)
{
	t_points	*tmp;
	int			flag;

	while (toch)
	{
		flag = 0;
		tmp = ch1;
		while (tmp)
		{
			if (tmp->x == toch->x && tmp->y == toch->y)
				flag++;
			tmp = tmp->next;
		}
		tmp = ch2;
		while (tmp)
		{
			if (tmp->x == toch->x && tmp->y == toch->y)
				flag++;
			tmp = tmp->next;
		}
		if (flag == 0)
			return (0);
		toch = toch->next;
	}
	return (1);
}

static int				ft_check_if_all_points_repeat(t_points *toch, t_points *ch1, t_points *ch2)
{
	t_points	*tmp1;
	t_points	*tmp2;

	tmp1 = ch1;
	tmp2 = ch2;
	while (toch && (tmp1 || tmp2))
	{
		tmp1 = ch1;
		tmp2 = ch2;
		while (tmp1)
		{
			if (tmp1->x == toch->x && tmp1->y == toch->y)
				break ;
			tmp1 = tmp1->next;
		}
		while (tmp2)
		{
			if (tmp2->x == toch->x && tmp2->y == toch->y)
				break ;
			tmp2 = tmp2->next;
		}
		toch = toch->next;
	}
	if (toch == NULL)
		return (1);
	return (0);
}

static int				ft_can_change(t_points *toch, t_points *ch1,
										t_points *ch2)
{
	int			points;
	t_points	*tmp;
	int			flag;

	if (ft_check_repeated_points(toch, ch1) &&
		ft_check_repeated_points(toch, ch2) &&
		ft_check_if_all_points_repeat(toch, ch1, ch2))
		return (1);
	return (0);
}

static void				ft_del_sect(t_sector_lst **head,
							t_sector_lst *todel, t_doom *d)
{
	t_sector_lst	*prev;
	t_sector_lst	*newhead;
	t_sector_lst	*tmp;

	prev = NULL;
	tmp = *head;
	while (tmp != todel)
		tmp = tmp->next;
	if (tmp == *head)
	{
		*head = (*head)->next;
		ft_free_point_lst(&(tmp->head));
		free(tmp);
	}
	else
	{
		prev = *head;
		while (prev->next != tmp)
			prev = prev->next;
		prev->next = tmp->next;
		ft_free_point_lst(&(tmp->head));
		free(tmp);
	}
}

static void				ft_clear_big_sectors(t_sector_lst **sec, t_doom *d)
{
	t_sector_lst	*first;
	t_sector_lst	*second;
	t_sector_lst	*poten;

	poten = *sec;
	while (poten)
	{
		first = *sec;
		while (first)
		{
			if (first != poten)
			{
				second = *sec;
				while (second)
				{
					if (second != first && second != poten && first != poten)
						if (ft_can_change(poten->head, first->head,
							second->head))
							{
								printf("deleted sector %p\n", poten);
								ft_del_sect(sec, poten, d);
								poten = *sec;
							}
					second = second->next;
				}
			}
			first = first->next;
		}
		poten = poten->next;
	}
}

static void				ft_free_last_sec(t_sector_lst **head)
{
	t_sector_lst	*prev;
	t_sector_lst	*tmp;

	if (!(*head))
		return ;
	prev = NULL;
	tmp = *head;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (tmp->head)
		ft_free_point_lst(&tmp->head);
	if (tmp == *head)
	{
		free(tmp);
		(*head) = NULL;
		return ;
	}
	free(tmp);
	prev->next = NULL;
}

static void				ft_add_first_points(t_doom *d, t_sector_lst *f, t_sector_lst *s)
{
	t_points	*pf;
	t_points	*ps;
	t_points	*head;

	head = d->point_lst;
	pf = NULL;
	ps = NULL;
	while (head)
	{
		if (ft_belong_to_last(head, d))
		{
			if (!pf)
				pf = head;
			else
				ps = head;
		}
		head = head->next;
	}
	ft_add_point_to_sector(f, pf);
	ft_add_point_to_sector(s, ps);
}

static double				ft_vector_product_with_last_line(t_sector_lst *lst,
												t_points *p, int sign)
{
	t_points	*cur;
	t_points	*f;
	t_points	*s;
	double		res;

	cur = lst->head;
	while (cur->next->next)
		cur = cur->next;
	f = cur;
	s = cur->next;
	res = ft_vector_product(s->x - f->x, s->y - f->y, p->x - s->x, p->y - s->y);
	if ((s->x == f->x && f->x == p->x) || (s->y == f->y && f->y == p->y))
		return (0);
	else if (res > 0)
		res = ft_angle_vectors(s->x - f->x, s->y - f->y, p->x - s->x, p->y - s->y);
	else if (res < 0)
		res = -ft_angle_vectors(s->x - f->x, s->y - f->y, p->x - s->x, p->y - s->y);
	return (res);
}

static int				ft_point_lst_len(t_points *p)
{
	int		i;

	i = 0;
	while (p)
	{
		i++;
		p = p->next;
	}
	return (i);
}

static void				ft_add_sec_to_sec_lst(t_sector_lst **dst, t_sector_lst *src)
{
	t_sector_lst	*tmp;

	tmp = *dst;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = src;
	}
	else
		*dst = src;
}

static int					ft_point_is_part_of_lst(t_sector_lst *sec, t_points *p)
{
	t_points	*head;

	head = sec->head;
	while (head)
	{
		if (p->x == head->x && p->y == head->y)
			return (1);
		head = head->next;
	}
	return (0);
}

static int					ft_check_point_connection(t_line *lines, t_points *p1, t_points *p2)
{
	while (lines)
	{
		if ((p1->x == lines->x_s && p1->y == lines->y_s && p2->x == lines->x_e && p2->y == lines->y_e) ||
			(p2->x == lines->x_s && p2->y == lines->y_s && p1->x == lines->x_e && p1->y == lines->y_e))
			return (1);
		lines = lines->next;
	}
	return (0);
}

static int					ft_connection_inside_sec(t_sector_lst *sec, t_points *p1, t_points *p2)
{
	t_points	*head;

	head = sec->head;
	while (head->next)
	{
		if ((head->x == p1->x && head->y == p1->y && head->next->x == p2->x && head->next->y == p2->y) ||
			(head->x == p2->x && head->y == p2->y && head->next->x == p1->x && head->next->y == p1->y))
			return (1);
		head = head->next;
	}
	if ((head->x == p1->x && head->y == p1->y && sec->head->x == p2->x && sec->head->y == p2->y) ||
		(head->x == p2->x && head->y == p2->y && sec->head->x == p1->x && sec->head->y == p1->y))
			return (1);
	return (0);
}

static t_points				*ft_find_check_points(t_doom *d, t_sector_lst *sec, t_points *prev, t_points *p1)
{
	t_points	*res;
	t_points	*plist;
	t_points	*to_ret;

	plist = d->point_lst;
	res = plist;
	to_ret = NULL;
	while (res)
	{
		if (ft_point_is_part_of_lst(sec, res) && ft_check_point_connection(d->lines, p1, res) && !ft_connection_inside_sec(sec, p1, res))
			ft_add_point_to_lst(&to_ret, res->x, res->y);
		res = res->next;
	}
	return (to_ret);
}

static int					ft_is_on_the_right(t_points *p1, t_points *p2, t_points *to_check)
{
	return ((to_check->x - p1->x) * (p2->y - p1->y) - (to_check->y - p1->y) * (p2->x - p1->x) > 0 ? 1 : 0);
}

static int					ft_second_clear_big_sectors(t_doom *d, t_sector_lst *sec)
{
	t_points		*head;
	t_points		*to_check;
	t_points		*tmp;
	double			def;

	head = sec->head;
	to_check = NULL;
	while (head->next)
	{
		to_check = ft_find_check_points(d, sec, to_check, head->next);
		tmp = to_check;
		if (head->next->next)
			def = ft_angle_vectors(head->next->x - head->x, head->next->y - head->y, head->next->next->x - head->next->x, head->next->next->y - head->next->y);
		else
			def = ft_angle_vectors(head->next->x - head->x, head->next->y - head->y, sec->head->x - head->next->x, sec->head->y - head->next->y);
		while (tmp)
		{
			if (ft_angle_vectors(head->next->x - head->x, head->next->y - head->y, tmp->x - head->next->x, tmp->y - head->next->y) > def)
			{
				printf("point to del (%d %d) with line (%d %d)->(%d %d)\n", tmp->x, tmp->y, head->x, head->y, head->next->x, head->next->y);
				ft_free_point_lst(&to_check);
				return (1);
			}
			tmp = tmp->next;
		}
		ft_free_point_lst(&to_check);
		head = head->next;
	}
	to_check = ft_find_check_points(d, sec, to_check, sec->head);
	tmp = to_check;
	while (tmp)
	{
		if (!ft_is_on_the_right(head, sec->head, tmp))
		{
			printf("point to del (%d %d) with line (%d %d)->(%d %d)\n", tmp->x, tmp->y, head->x, head->y, sec->head->x, sec->head->y);
			ft_free_point_lst(&to_check);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_free_point_lst(&to_check);
	return (0);
}

static int					ft_check_previous(t_doom *d, t_sector_lst *lst, t_points *p)
{
	t_points	*head;

	head = lst->head;
	while (head->next->next)
		head = head->next;
	if ((head->x == p->x && head->y == p->y) || (head->next->x == p->x && head->next->y == p->y))
		return (1);
	return (0);
}

static int					ft_go_sec(t_doom *d, t_sector_lst *lst, int sign)
{
	double		res;
	double		tmp;
	t_points	*pres;
	t_points	*min;
	t_points	*cur;

	res = -20.0f;
	cur = d->point_lst;
	pres = NULL;
	while (cur)
	{
		// fprintf(d->log_fd, "point x->%d y->%d connection->%d\n", cur->x, cur->y, ft_check_connection(d, lst, cur));
		if (ft_check_connection(d, lst, cur) &&
			((ft_check_repeat(lst, cur) == 0) || (ft_point_lst_len(lst->head) > 2 && ft_check_repeat(lst, cur) == 2)))
			// !ft_check_previous(d, lst, cur))
			{
				tmp = ft_vector_product_with_last_line(lst, cur, sign);
				if (tmp > res)
				{
					printf("max point x->%d, y->%d res->%f prev->%f\n", cur->x, cur->y, tmp, res);
					res = tmp;
					pres = cur;
				}
			}
	if (cur->next == NULL && pres != NULL)
		{
			// fprintf(d->log_fd, "added point x->%d y->%d with res=%f\n", pres->x, pres->y, res);
			if (pres->x == lst->head->x && pres->y == lst->head->y)
				break ;
			ft_add_point_to_sector(lst, pres);
			cur = d->point_lst;
			pres = NULL;
			res = -20.0f;
		}
	else
		cur = cur->next;
	}
	// fprintf(d->log_fd, "LIST THAT TRIED TO\n\n");
	ft_print_sector_lst(lst, d);
	// if (pres)
		// fprintf(d->log_fd, "%d %d %d %d\n", ft_point_lst_len(lst->head), pres->x == lst->head->x, pres->y == lst->head->y, !ft_sector_repeat(d->sect_head, lst, d));
	// else
		// fprintf(d->log_fd, "NESRAL\n");

	if (pres && ft_point_lst_len(lst->head) >= 3 && pres->x == lst->head->x && pres->y == lst->head->y && !ft_sector_repeat(d->sect_head, lst, d))
	{
		if (!(ft_check_inside_point(lst->head, d->point_lst, lst, d)))
	{
		fprintf(d->log_fd, "PROSHEL\n\n");
		if (ft_is_sector_clockwise(lst) < 0)
		{
			// ft_return("not clockwise sector");
			ft_points_lst_rev(lst);
		}
		if (!ft_second_clear_big_sectors(d, lst))
		{
			printf("added sector %p\n", lst);
			ft_add_sec_to_sec_lst(&d->sect_head, lst);
			return (1);
		}
		else
			ft_free_sector_lst(lst);
	}
	else
		ft_free_sector_lst(lst);
	}
	else
		ft_free_sector_lst(lst);
	return (0);
}

static void				ft_add_first_point(t_doom *d, t_sector_lst *sec, int flag)
{
	t_points	*p;
	t_line		*line;
	t_points	*tmp;


	line = d->lines;
	while (line->next)
		line = line->next;
	// printf("last line (%d %d) -> (%d %d)", line->x_s, line->y_s, line->x_e, line->y_e);
	// printf("tail (%d %d) -> (%d %d)", line->x_s, line->y_s, line->x_e, line->y_e);
	p = (t_points *)ft_memalloc(sizeof(t_points));
	p->x = line->x_s;
	p->y = line->y_s;
	p->next = (t_points *)ft_memalloc(sizeof(t_points));
	p->next->x = line->x_e;
	p->next->y = line->y_e;
	// if (flag == 2)
	// {
	// 	p->next->next = p;
	// 	p = p->next;
	// 	p->next->next = NULL;
	// }
	sec->head = p;
}

static void				ft_launch_sec_finding(t_doom *d, t_sector_lst **head, int sign)
{
	t_sector_lst	*cur;
	t_sector_lst	*scur;
	t_points		*pcur;


	cur = (t_sector_lst *)ft_memalloc(sizeof(t_sector_lst));
	ft_add_first_point(d, cur, 1);
	printf("added point to sector x->%d, y->%d\n", cur->head->x, cur->head->y);
	printf("added point to sector x->%d, y->%d\n", cur->head->next->x, cur->head->next->y);
	ft_go_sec(d, cur, 1);
	fprintf(d->log_fd, "\n");
	printf("\n");
	cur = (t_sector_lst *)ft_memalloc(sizeof(t_sector_lst));
	ft_add_first_point(d, cur, 2);
	ft_points_lst_rev(cur);
	printf("added point to sector x->%d, y->%d\n", cur->head->x, cur->head->y);
	printf("added point to sector x->%d, y->%d\n", cur->head->next->x, cur->head->next->y);
	ft_go_sec(d, cur, 1);
	// ft_free_sector_lst(cur);
}

static void				ft_find_sectors(t_doom *d)
{
	t_sector_lst	*head;
	t_points		*phead;
	t_sector_lst	*tmp;
	t_sector_lst	*tail;

	phead = d->point_lst;
	ft_launch_sec_finding(d, &d->sect_head, 1);
	ft_clear_big_sectors(&(d->sect_head), d);
	fprintf(d->log_fd, "\n\nAFTER\n\n");
}

void					ft_check_sectors(t_doom *d)
{
	if (!ft_check_line_points_repeat(d))
		return ;
	ft_transform_to_points(d);
	ft_find_sectors(d);
	d->flags |= (1 << 2);
	ft_fill_sector_info(d);
	ft_print_sector_lst(d->sect_head, d);
	d->flags &= ~(1 << 2);
	d->flags = 0;
}
