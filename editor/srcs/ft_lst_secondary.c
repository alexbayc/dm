#include "doom.h"

int		ft_line_repeats(t_line *line, t_points p1, t_points p2)
{
	while (line)
	{
		if ((line->x_s == p1.x && line->y_s == p1.y && line->x_e == p2.x && line->y_e == p2.y) ||
			 (line->x_s == p2.x && line->y_s == p2.y && line->x_e == p1.x && line->y_e == p1.y))
			return (1);
		line = line->next;
	}
	return (0);
}

void	ft_add_line(t_line **lines, t_points p1, t_points p2)
{
	t_line	*tmp;

	if (!*lines)
	{
		*lines = (t_line *)ft_memalloc(sizeof(t_line));
		(*lines)->x_s = p1.x;
		(*lines)->y_s = p1.y;
		(*lines)->x_e = p2.x;
		(*lines)->y_e = p2.y;
		return ;
	}
	else
	{
		tmp = *lines;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_line *)ft_memalloc(sizeof(t_line));
		tmp->next->x_s = p1.x;
		tmp->next->y_s = p1.y;
		tmp->next->x_e = p2.x;
		tmp->next->y_e = p2.y;
	}
}