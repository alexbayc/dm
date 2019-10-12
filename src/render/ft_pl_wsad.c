#include "engine.h"

static void	ft_foot_sound(t_engine *e)
{
	if (e->mus.steps != NULL)
	{
		Mix_PlayChannel(-1, e->mus.steps, 0);
	}
}

void	ft_w(t_engine *e)
{
	e->player.where.x += cos(ft_dig_to_rad(e->player.angle)) * e->player.speed;
	e->player.where.y += sin(ft_dig_to_rad(e->player.angle)) * e->player.speed;
	ft_foot_sound(e);
}

void	ft_s(t_engine *e)
{
	e->player.where.x -= cos(ft_dig_to_rad(e->player.angle)) * e->player.speed;
	e->player.where.y -= sin(ft_dig_to_rad(e->player.angle)) * e->player.speed;
//в каждом действии надо менять z
	ft_foot_sound(e);
}

void	ft_a(t_engine *e)
{
	e->player.where.x += cos(ft_dig_to_rad(e->player.angle - 90))
		* e->player.speed;
	e->player.where.y += sin(ft_dig_to_rad(e->player.angle - 90))
		* e->player.speed;
	ft_foot_sound(e);
}

void	ft_d(t_engine *e)
{
	e->player.where.x += cos(ft_dig_to_rad(e->player.angle + 90))
		* e->player.speed;
	e->player.where.y += sin(ft_dig_to_rad(e->player.angle + 90))
		* e->player.speed;
	ft_foot_sound(e);
}
