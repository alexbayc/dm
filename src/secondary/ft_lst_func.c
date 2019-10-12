#include "engine.h"

void	ft_add_node(t_true_p **head, t_xy l, char aft)
{
	t_true_p	*new;
	t_true_p	*tmp;

	tmp = NULL;
	new = (t_true_p *)ft_memalloc(sizeof(t_true_p));
	if (!new)
		ft_return("erro: malloc");
	new->t.x = l.x;
	new->t.y = l.y;
	new->after_w = aft;
	new->next = NULL;
	new->prev = NULL;
	if ((*head) == NULL)
		(*head) = new;
	else
	{
		tmp = (*head);
		while (tmp->next != NULL)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
}

static int		ft_repeat(t_true_p **is, t_xy l)
{
	t_true_p	*head;

	head = *is;
	while (head)
	{
		if (head->t.x == l.x && head->t.y == l.y)
			return (1);
		head = head->next;
	}
	return (0);
}

void			ft_add_node_head_prev(t_true_p **is, t_xy l, char aft)
{
	t_true_p	*new;
	t_true_p	*tmp;

	tmp = *is;
	// if (ft_repeat(is, l))
	// 	return ;
	new = (t_true_p *)ft_memalloc(sizeof(t_true_p));
	if (!new)
		ft_return("erro: malloc");
	// printf("added to lst x->%f, y->%f\n", l.x, l.y);
	new->t.x = l.x;
	new->t.y = l.y;
	new->after_w = aft;
	if (!(*is))
	{
		(*is) = new;
		return ;
	}
	tmp->prev = new;
	new->next = tmp;
	*is = new;
}

void			ft_add_node_prev(t_true_p **is, t_xy l, char aft)
{
	t_true_p	*new;
	t_true_p	*tmp;

	tmp = NULL;
	new = (t_true_p *)ft_memalloc(sizeof(t_true_p));
	if (!new)
		ft_return("erro: malloc");
	new->t.x = l.x;
	new->t.y = l.y;
	new->after_w = aft;
	new->next = NULL;
	new->prev = NULL;
	if ((*is) == NULL)
		(*is) = new;
	else
	{
		tmp = (*is);
		new->next = tmp;
		new->prev = tmp->prev;
		if (tmp->prev != NULL)
			tmp->prev->next = new;
		tmp->prev = new;
	}
}


void	ft_add_node_next(t_true_p **is, t_xy l, char aft)
{
	t_true_p	*new;
	t_true_p	*tmp;

	tmp = NULL;
	new = (t_true_p *)ft_memalloc(sizeof(t_true_p));
	if (!new)
		ft_return("erro: malloc");
	new->t.x = l.x;
	new->t.y = l.y;
	new->after_w = aft;
	if ((*is) == NULL)
		(*is) = new;
	else
	{
		tmp = (*is);
		new->next = tmp->next;
		if (tmp->next != NULL)
			tmp->next->prev = new;
		tmp->next = new;
		new->prev = tmp;
	}
}

void	ft_print_lst(t_true_p **head)
{
	t_true_p *tmp;
	double		angl;

	tmp = (*head);
	if ((*head) == NULL)
		ft_putendl("NULL");
	printf("list\n");
	while (tmp)
	{
		angl = acos((float)tmp->t.x /
			sqrt(pow((tmp->t.y), 2) + pow((tmp->t.x), 2)));
		printf("list x->%f, y->%f, after wall->%d, angl->%f\n", tmp->t.x, tmp->t.y, tmp->after_w, tmp->t.y < 0 ? -ft_rad_to_dig(angl) : ft_rad_to_dig(angl));
		tmp = tmp->next;
	}
}

int		ft_lst_len(t_true_p **head)
{
	t_true_p *tmp;
	int	i;

	i = 0;
	tmp = (*head);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_true_p	*ft_get_node(t_true_p **head, int i)
{
	t_true_p	*tmp;
	int			j;

	j = 0;
	tmp = *head;
	while (j < i)
	{
		tmp = tmp->next;
		j++;
	}
	return (tmp);
}

t_true_p	*ft_get_last(t_true_p **head)
{
	t_true_p	*tmp;

	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_print_mas(t_xyz *mas, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("x->%f, y->%f, z->%f\n", mas[i].x, mas[i].y, mas[i].z);
		i++;
	}
}

void	ft_print_border(int *mas, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf(" b (%d, %d) ", i, mas[i]);
		i++;
	}
	printf("\n");
}

void	ft_free_lst(t_true_p **head)
{
	t_true_p	*tmp;
	t_true_p	*adr;

	tmp = *head;
	adr = *head;
	if (tmp == NULL)
		return ;
	while (tmp)
	{
		adr = tmp->next;
		ft_free((void **)(&tmp));
		tmp = adr;
	}
	tmp = NULL;
}