#include "doom.h"

void		ft_change_ceil_texture(t_doom *d, t_sector_lst *lst, int num)
{
	lst->ceil_tex += num;
	if (lst->ceil_tex == d->nb_tex - 1)
		lst->ceil_tex = 0;
	else if (lst->ceil_tex == -1)
		lst->ceil_tex = d->nb_tex - 2;
}

void		ft_change_floor_texture(t_doom *d, t_sector_lst *lst, int num)
{
	lst->floor_tex += num;
	if (lst->floor_tex == d->nb_tex - 1)
		lst->floor_tex = 0;
	else if (lst->floor_tex == -1)
		lst->floor_tex = d->nb_tex - 2;
}
