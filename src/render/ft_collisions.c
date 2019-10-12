#include "engine.h"

void	ft_out_of_map(t_engine *e, t_xyz *p)
{
	float	c;
	c = 0;
	if (ft_which_sector(e, e->player.where.x + c, e->player.where.y + c) == -1)
	{
		//printf("try(%f% f %f),check (%f% f %f),  last (%f% f %f)\n", e->player.where.x, e->player.where.y, e->player.where.z, e->player.where.x + c, e->player.where.y + c, e->player.where.z + c, p->x, p->y, p->z );
		e->player.where.x = p->x;
		e->player.where.y = p->y;
		// e->player.where.z = p->z;
	}
}

void	ft_col_fl(t_engine *e, t_xyz *p)
{
	int	sec;
	int	sec_now;
	int	flag;

	flag = 0;
	sec = ft_which_sector(e, e->player.where.x, e->player.where.y);
	sec_now = ft_which_sector(e, p->x, p->y);
	if (sec == -1)
		flag++;
	if (e->player.where.z < e->sectors[sec].floor)
		flag++;
	if (e->player.where.z + e->player.height >= e->sectors[sec].ceil)
	{
		flag++;
	}
	if (sec != sec_now)
	{
		int test = ft_portal_or_wall(e, p, sec, sec_now);
		// printf("after step->%d\n", test);
		if (test == -1)
		{
			flag++;
		}
	}

	if (flag != 0)
	{
		e->player.where.x = p->x;
		e->player.where.y = p->y;
		e->player.where.z = p->z;
	}
	else
	{
		// printf("here123\n");
		if (e->sectors[sec_now].floor - e->sectors[sec].floor > 5)
		{
			e->player.health -= 10;
			if(e->player.health < 0)
				e->player.health = 0;
			if (e->player.health > 0 && e->mus.hurt != NULL)
				Mix_PlayChannel(-1, e->mus.hurt, 0);
			else if (e->mus.game_over != NULL)
				Mix_PlayChannel(-1, e->mus.game_over, 0);

			printf("health ->%d\n", e->player.health);
		}
		e->player.where.z = e->sectors[sec].floor;
	}
}


void	ft_collision(t_engine *e, t_xyz *p)
{
	//ft_out_of_map(e, p);
	ft_col_fl(e, p);
}