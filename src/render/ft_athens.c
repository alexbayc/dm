#include "engine.h"

void	ft_transfer_90(t_engine *e, t_true_p	**l)
{

	t_true_p	*tmp;
	float	teta;
	float	new_x;
	float	new_y;

	tmp = *l;
	teta = ft_dig_to_rad(270 - e->player.angle);
	while (tmp)
	{
		new_x = tmp->t.x * cosf(teta) - tmp->t.y * sinf(teta);
		new_y = tmp->t.x * sinf(teta) + tmp->t.y * cosf(teta);
		tmp->t.x = new_x;
		tmp->t.y = new_y;
		tmp = tmp->next;
	}
	ft_try_ray(e, l);
}

void	ft_transfer_img_to_null(t_engine *e, t_true_p	**l)
{
	t_true_p	*tmp;
	float	dx;
	float	dy;

	tmp = *l;
	dx = 0 - e->player.where.x;
	dy = 0 - e->player.where.y;
	while (tmp)
	{
		tmp->t.x = tmp->t.x + dx;
		tmp->t.y = tmp->t.y + dy;
		tmp = tmp->next;
	}
	ft_transfer_90(e, l);
}
