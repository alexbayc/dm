#include "engine.h"

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */

void	ft_fill_struct(t_data *d, int x, int y)
{
	d->x = x;
	d->y = y;
}

void	ft_create_struct_my(t_engine *e, int x, int y)
{
	e->data_my = (t_data *)malloc(sizeof(t_data) * 1);
	ft_fill_struct(e->data_my, x, y);
}

void	ft_create_struct_another(t_engine *e, int x, int y)
{
	e->data_another = (t_data *)malloc(sizeof(t_data) * 1);
	ft_fill_struct(e->data_another, x, y);
}


