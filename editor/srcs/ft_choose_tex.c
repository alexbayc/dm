#include "doom.h"

void	ft_draw_arrow(t_doom *d, int x, int i)
{
	int			c;
	t_button	b;
	ft_putendl("draww arrow");
	b.x = (1910 + 100 * i - 1812 + 100 * i) / 2;
	b.x = 1812 + 100 * i + b.x;
	b.y = d->img.menu.height / 3 + 22 + 100;
	b.color = 0x34D800;
	d->x_s = b.x;
	d->y_s = b.y + 5;
	d->x_e = b.x;
	d->y_e = b.y + 80;
	ft_brasenham(d, 'M', b.color);
	// mlx_put_image_to_window(d->img.mlx_ptr, d->img.win_ptr,
	// 	d->img.menu.img_ptr, d->border, 1);
	free(&b);
}

void	ft_tex_arrow(t_doom *d, int x, int i)
{
	ft_putendl("here");
	ft_draw_arrow(d, x, i);
}
