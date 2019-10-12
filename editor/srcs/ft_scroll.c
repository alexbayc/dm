#include "doom.h"

// void	ft_scroll_left(t_doom *d)
// {
// 	if (d->flag_scroll == 0)
// 		return ;
// 	d->flag_scroll--;
// 	d->nb_tex_cost = d->nb_tex_cost - 6 - d->nb_tex_left;
// 	ft_tex(d, &(d->but[3]));
// 	mlx_put_image_to_window(d->img.mlx_ptr, d->img.win_ptr,
// 		d->img.menu.img_ptr, d->border, 1);
// }

// void	ft_scroll_right(t_doom *d)
// {
// 	int	ost;

// 	if ((ost = d->nb_tex % 6) == 0)
// 		ost = d->nb_tex / 6 - 1;
// 	else
// 		ost = d->nb_tex / 6;
// 	if (d->flag_scroll == ost)
// 		return ;
// 	d->flag_scroll++;
// 	ft_tex(d, &(d->but[3]));
// 	mlx_put_image_to_window(d->img.mlx_ptr, d->img.win_ptr,
// 		d->img.menu.img_ptr, d->border, 1);
// }

// void	ft_choose_tex(t_doom *f, int x, int y)
// {
// 	int	i;
// 	i = 0;

// 	while (i < 6)
// 	{
// 		if (x >= (1812 + 100 * i) && x <= (1910 + 100 * i))
// 		{	ft_tex_arrow(f, x, i);
// 			ft_putendl(ft_strjoin("tex ", ft_itoa(i)));
// 		}
// 		i++;
// 	}
// 	ft_putendl("i want to choose tex");
// }
