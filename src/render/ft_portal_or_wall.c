#include "engine.h"

void	ft_fill_p(t_xyz *p,  t_xy *p_n)
{
	p_n->x = p->x;
	p_n->y = p->y;
}

int	ft_portal_or_wall(t_engine *e, t_xyz *p, int sec, int sec_now)
{
	int		i;
	t_xy	p1;
	t_xy	p2;
	int		flag;

	flag = 0;
	i = 0;

	ft_fill_p(p, &p1);
	ft_fill_p(&e->player.where, &p2);
	while (i < e->sectors[sec_now].npoints)
	{
		if (ft_intersect(e->sectors[sec_now].vertex[i], e->sectors[sec_now].vertex[i + 1], p1, p2) == 1)
		{
			flag++;
			break ;
		}
		i++;
	}
	if ( flag != 0)
	{
		if (e->sectors[sec_now].neighbors[i] == -1)
			return (-1);
		else
		{
			return (e->sectors[sec_now].neighbors[i]);
		}
	}
	return (sec_now);
}
