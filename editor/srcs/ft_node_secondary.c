#include "doom.h"
/* there are some functions, it helps me debug. After i'll del it */

int	ft_lst_len(t_line *ln)
{
	int		i;
	t_line	*tmp;

	tmp = ln;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_print_lst(t_doom *f)
{
	t_line *tmp;

	tmp = f->lines;
	if (tmp == NULL)
	{
		fprintf(f->log_fd, "nothing to print\n");
		return ;
	}
	while (tmp)
	{
		fprintf(f->log_fd, "%s: x_s->%d, y_s->%d, x_e->%d, y_e->%d\n",
			tmp->name, tmp->x_s, tmp->y_s, tmp->x_e, tmp->y_e);
		tmp = tmp->next;
	}
}

/*there are needed functions. DON'T DELETE IT PLS I WILL CRY IF YOU WILL SO DONT*/

void	ft_change_lst_coordinates(t_doom *d, int x, int y)
{
	t_line *tmp;

	tmp = d->lines;
	while (tmp)
	{
		tmp->x_s += x;
		tmp->x_e += x;
		tmp->y_s += y;
		tmp->y_e += y;
		tmp = tmp->next;
	}
	d->player->pos.x += x;
	d->player->pos.y += y;
}

void		ft_change_sec_coordinates(t_sector_lst *head, int x, int y)
{
	t_points	*tmp;

	while (head)
	{
		tmp = head->head;
		while (tmp)
		{
			tmp->x += x;
			tmp->y += y;
			tmp = tmp->next;
		}
		head = head->next;
	}
}

void	ft_move_lst(t_doom *d)
{
	int		x;
	int		y;
	t_line	*tmp;

	x = 0;
	y = 0;
	tmp = d->lines;
	if (d->sdl.event.key.keysym.sym == SDLK_UP)
		y = 1;
	else if (d->sdl.event.key.keysym.sym == SDLK_DOWN)
		y = -1;
	else if (d->sdl.event.key.keysym.sym == SDLK_LEFT)
		x = 1;
	else if (d->sdl.event.key.keysym.sym == SDLK_RIGHT)
		x = -1;
	// d->player->pos.x += x;
	// d->player->pos.y += y;
	ft_change_lst_coordinates(d, x, y);
	ft_change_sec_coordinates(d->sect_head, x, y);
	fprintf(d->log_fd, "\n\nAFTER MOVING\n\n");
	ft_print_sector_lst(d->sect_head, d);
}
