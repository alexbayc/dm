#include "doom.h"

void	ft_draw_lst(t_doom *d)
{
	t_line	*tmp;
	t_line	save;

	tmp = d->lines;
	while (tmp)
	{
		save = *tmp;
		d->x_s = (int)(tmp->x_s * (int)(d->c * d->scale));
		d->y_s = (int)(tmp->y_s * (int)(d->c * d->scale));
		d->x_e = (int)(tmp->x_e * (int)(d->c * d->scale));
		d->y_e = (int)(tmp->y_e * (int)(d->c * d->scale));
		ft_brasenham(d, 'N', 0);
		ft_draw_start_end(d, d->frame_size);
		*tmp = save;
		d->x_s = (int)(tmp->x_s * (int)(d->c * d->scale));
		d->y_s = (int)(tmp->y_s * (int)(d->c * d->scale));
		d->x_e = (int)(tmp->x_e * (int)(d->c * d->scale));
		d->y_e = (int)(tmp->y_e * (int)(d->c * d->scale));
		if (d->flags & 1)
			ft_wall_texture(d, d->frame_size * 8, tmp);
		tmp = tmp->next;
	}
}

void	ft_ctrl_z(t_doom *d)
{
	ft_free_lst(d, 1);
	ft_clear_net(d);
	ft_draw_lst(d);
}
