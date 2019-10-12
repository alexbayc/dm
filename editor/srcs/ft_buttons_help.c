#include "doom.h"

void	ft_what_but(t_doom *d, t_button *b)
{
	if (ft_strcmp(b->type, "trash") == 0)
		ft_trash(d, b);
	else if (ft_strcmp(b->type, "save") == 0)
		ft_save(d, b);
	else if (ft_strcmp(b->type, "ctrz") == 0)
		ft_ctrz(d, b);
//	else if (ft_strcmp(b->type, "1") == 0)
	//	ft_tex(d, b);
	else if (ft_strcmp(b->type, "left") == 0)
	 	ft_left(d, b);
	else if (ft_strcmp(b->type, "right") == 0)
	 	ft_right(d, b);
	else
		return ;

}

void	ft_init_but(t_button *b, int x_len, int y_len, int x)
{
	b->x_len = x_len;
	b->y_len = y_len;
	b->x = x;
}

void	ft_init_but_2(t_button *b, int y, int color)
{
	b->y = y;
	b->color = color;
}

/* take len on x and y, take left up dot*/
void	ft_button(t_doom *d, t_button *tmp)
{
	int	x_lim = tmp->x + tmp->x_len;
	int	y_lim = tmp->y + tmp->y_len;
	int	x_tmp;
	int	y_tmp = tmp->y;

	while (y_tmp <= y_lim)
	{
		x_tmp = tmp->x;
		while (x_tmp <= x_lim)
		{
			if (y_tmp == tmp->y || y_tmp == (y_lim))
				ft_surface_set_pixel(d->sdl.sur_ptr, x_tmp, y_tmp, d->color.menu);
			else if (x_tmp == tmp->x || x_tmp == (x_lim))
				ft_surface_set_pixel(d->sdl.sur_ptr, x_tmp, y_tmp, d->color.menu);
			x_tmp++;
		}
		y_tmp++;
	}
}
