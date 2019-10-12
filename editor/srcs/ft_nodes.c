#include "doom.h"

t_line		*ft_get_node_by_num(t_line *head, int num)
{
	t_line	*cur;
	int		i;

	cur = head;
	i = 0;
	while (cur && ++i < num)
		cur = cur->next;
	return (cur);
}

int			ft_get_node_num(t_line *head, t_line *line)
{
	t_line	*cur;
	int		i;

	i = 0;
	cur = head;
	while (cur)
	{
		if (cur == line)
			return (i);
		i++;
		cur = cur->next;
	}
	return (-1);
}

static void	ft_free_all_lst(t_doom *f)
{
	t_line	*tmp;
	fprintf(f->log_fd, "del all lst");
	while (f->lines->next)
	{
		tmp = f->lines;
		f->lines = f->lines->next;
		if (tmp->name != NULL && tmp->name[0] != '\0')
			free(tmp->name);
		//f->nb_ln--;
		free(tmp);
	}
	f->part_ln = 0;
	f->nb_ln = 0;
	f->lines = NULL;
	f->tail = NULL;
}

/* del from tail */

static void	ft_free_n_lists(t_doom *f, int n)
{
	t_line	*tail;
	t_line	*del;

	fprintf(f->log_fd, "nb ln %d  n %d\n", f->nb_ln, n);
	if (f->nb_ln - n >= 1)
		while (n > 0)
		{
			tail = f->tail->prev;
			del = f->tail;
			if (del->name != NULL && del->name[0] != '\0')
				free(del->name);
			free(del);
			f->nb_ln--;
			tail->next = NULL;
			f->tail = tail;
			n--;
		}
	else
		ft_free_all_lst(f);
}

/* if flag = 0, del all chained list, else del flags elem */

void	ft_free_lst(t_doom *f, int flag)
{
	if (f->lines == NULL)
	{
		fprintf(f->log_fd, "nothing to clean\n");
		return ;
	}
	if (flag == 0)
	{
		fprintf(f->log_fd, "clean all\n");
		ft_free_all_lst(f);
	}
	else
	{
		fprintf(f->log_fd, "clean flag\n");
		ft_free_n_lists(f, flag);
	}
}

void	ft_fill_node(t_line **n, t_doom *d)
{
	t_line	*new;

	new = *n;
	new->name[2] = '\0';
	new->name[0] = 'A' + d->nb_ln;
	new->name[1] = '0';
	new->x_s = (int)(d->x_s / (int)(d->c * d->scale));
	new->x_e = (int)(d->x_e / (int)(d->c * d->scale));
	new->y_s = (int)(d->y_s / (int)(d->c * d->scale));
	new->y_e = (int)(d->y_e / (int)(d->c * d->scale));
	d->nb_ln++;
	d->part_ln++;
	new->next = NULL;
	new->prev = NULL;

}

void	ft_create_nodes(t_line **head, t_doom *d)
{
	t_line *tmp;
	t_line *new;

	tmp = *head;
	fprintf(d->log_fd, "create nodes\n");
	if (!(new = (t_line *)ft_memalloc(sizeof(t_line))))
		ft_return("error: malloc");
	if (!(new->name = (char *)ft_memalloc(sizeof(char) * (3))))
		ft_return("error: malloc");
	ft_fill_node(&new, d);
	if ((*head) == NULL)
	{
		(*head) = new;
		d->tail = new;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	d->tail = new;
}
