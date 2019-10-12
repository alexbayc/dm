#include "doom.h"

static int ft_get_point_num(t_points *p, t_vert_lst *vert)
{
	int i;
	t_intl *intl;

	i = 0;
	while (vert)
	{
		intl = vert->head;
		while (intl)
		{
			if (intl->coord == p->x && vert->vert == p->y)
				return (i);
			i++;
			intl = intl->next;
		}
		vert = vert->next;
	}
	ft_return ("saving went wrong in filling points to sec");
	return (-1);
}

void ft_print_vertexes(t_doom *d, t_vert_lst *lst)
{
	t_intl *co;

	while (lst)
	{
		ft_putstr_fd("vertex\t", d->output);
		ft_putstr_fd(ft_itoa(lst->vert), d->output);
		ft_putchar_fd('\t', d->output);
		co = lst->head;
		while (co)
		{
			ft_putstr_fd(ft_itoa(co->coord), d->output);
			ft_putchar_fd(' ', d->output);
			co = co->next;
		}
		ft_putchar_fd('\n', d->output);
		lst = lst->next;
	}
	ft_putchar_fd('\n', d->output);
}

static t_line	*ft_find_line(t_doom *d, t_points *p, t_points *pn)
{
	t_line		*line;

	line = d->lines;
	while (line)
	{
		if ((p->x == line->x_s && p->y == line->y_s && pn->x == line->x_e && pn->y == line->y_e) ||
			(pn->x == line->x_s && pn->y == line->y_s && p->x == line->x_e && p->y == line->y_e))
			return (line);
		line = line->next;
	}
	return (NULL);
}

static int	ft_find_nei(t_doom *d, t_sector_lst *sec, t_points *p, t_points *pn)
{
	int		i;
	t_sector_lst	*lst;
	t_points		*o;

	i = 0;
	lst = d->sect_head;
	if ((ft_find_line(d, p, pn))->portal == 0)
	{
		return (-1);
	}
	while (lst)
	{
		if (lst != sec)
		{
			o = lst->head;
			while (o->next)
			{
				if ((p->x == o->x && p->y == o->y && pn->x == o->next->x && pn->y == o->next->y) ||
					(pn->x == o->x && pn->y == o->y && p->x == o->next->x && p->y == o->next->y))
					return (i);
				o = o->next;
			}
			if ((p->x == o->x && p->y == o->y && pn->x == lst->head->x && pn->y == lst->head->y) ||
				(pn->x == o->x && pn->y == o->y && p->x == lst->head->x && p->y == lst->head->y))
				return (i);
			// printf("NESRAL\n");
		}
		i++;
		lst = lst->next;
	}
	return (-1);
}

static void	ft_print_neighbour_sec(t_doom *d, t_sector_lst *sec)
{
	t_points	*p;
	int			nei;

	p = sec->head;
	while (p->next)
	{
		nei = ft_find_nei(d, sec, p, p->next);
		ft_putstr_fd(ft_itoa(nei), d->output);
		ft_putchar_fd(' ', d->output);
		p = p->next;
	}
	nei = ft_find_nei(d, sec, p, sec->head);
	ft_putstr_fd(ft_itoa(nei), d->output);
}

void	ft_print_sectors(t_doom *d, t_vert_lst *lst)
{
	t_sector_lst *sec;
	t_points *p;

	sec = d->sect_head;
	while (sec)
	{
		ft_putstr_fd("sector\t", d->output);
		ft_putstr_fd(ft_itoa(sec->floor), d->output);
		ft_putchar_fd(' ', d->output);
		ft_putstr_fd(ft_itoa(sec->ceiling), d->output);
		ft_putstr_fd("\t\t", d->output);
		p = sec->head;
		while (p)
		{
			ft_putstr_fd(ft_itoa(ft_get_point_num(p, lst)), d->output);
			ft_putchar_fd(' ', d->output);
			p = p->next;
		}
		p = sec->head;
		ft_putstr_fd("\t\t", d->output);
		ft_print_neighbour_sec(d, sec);
		ft_putchar_fd('\n', d->output);
		sec = sec->next;
	}
	ft_putchar_fd('\n', d->output);
}

void	ft_print_player(t_doom *d)
{
	ft_putstr_fd("player\t", d->output);
	ft_putstr_fd(ft_itoa(d->player->pos.x), d->output);
	ft_putchar_fd(' ', d->output);
	ft_putstr_fd(ft_itoa(d->player->pos.y), d->output);
	ft_putchar_fd(' ', d->output);
	ft_putstr_fd(ft_itoa((int)d->player->angle), d->output);
	ft_putstr_fd("\t0", d->output);
}