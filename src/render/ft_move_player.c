#include "engine.h"

void	ft_jump(t_engine *e)
{
	if (e->player.soar == 1)
	{
		if (e->player.jump == 1 || e->player.jump == 2 || e->player.jump == 3)
		{
			ft_horizon(e, 0, -100);
			e->player.jump++;
			e->player.where.z += 2;
		}
		else if (e->player.jump == 4 || e->player.jump == 5 || e->player.jump == 6)
		{
			ft_horizon(e, 0, 100);
			e->player.jump++;
			e->player.where.z -= 2;
		}
		else if (e->player.jump == 7)
		{
				e->player.jump = 0;
				e->player.where.z = e->sectors[ft_which_sector(e, e->player.where.x, e->player.where.y)].floor;
				e->player.soar = 0;
		}
	}
}




void	ft_stand_up(t_engine *e)
{
	if (e->player.squats == 2)
	{
		if (e->player.seat == 4 || e->player.seat == 5 || e->player.seat == 6)
		{
			ft_horizon(e, 0, -100);
			e->player.seat++;
			e->player.height += 2;
		}
		else if (e->player.seat == 7)
		{
			e->player.seat = 0;
			e->player.squats = 0;
		}
	}
}

void	ft_seat(t_engine *e)
{
	if (e->player.squats == 1)
	{
		if (e->player.seat == 1 || e->player.seat == 2 || e->player.seat == 3)
		{
			ft_horizon(e, 0, 100);
			e->player.seat++;
			e->player.height -= 2;
		}
		if (e->player.seat == 4)
		{
			e->player.squats = 2;
		}
	}
}
