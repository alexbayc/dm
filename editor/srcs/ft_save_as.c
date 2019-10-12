#include "doom.h"


void ft_save_as(t_doom *d)
{
	int		xmin;
	int		ymin;
	t_line	*tmp;

	xmin = 2147483647;
	ymin = 2147483647;
	tmp = d->lines;
	ft_putendl("save as");
	/* there will be function*/
	while (tmp)
	{
		if (xmin > tmp->x_e)
			xmin = tmp->x_e;
		if (xmin > tmp->x_s)
			xmin = tmp->x_s;
		if (ymin > tmp->y_e)
			ymin = tmp->y_e;
		if (ymin > tmp->y_s)
			ymin = tmp->y_s;
		tmp = tmp->next;
	}
	ft_change_lst_coordinates(d, -xmin, -ymin);
	ft_change_sec_coordinates(d->sect_head, -xmin, -ymin);
	ft_save_map_to_file(d);
	printf("got in redraw after save as\n");
	ft_redraw(d);
}
