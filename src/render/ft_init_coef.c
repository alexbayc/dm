#include "engine.h"


void	ft_init_coef(t_engine *e)
{
	e->player.speed = 0.3;
	e->player.health = 40;
	e->player.health_max = 100;
	e->player.ammo_max = 50;
	e->player.ammo = 50;
	e->player.height = 10;
	e->player.where.z = 0;
	e->player.jump = 0;
	e->player.soar = 0;
	e->player.seat = 0;
	e->player.squats = 0;
}
