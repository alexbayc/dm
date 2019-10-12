#include "engine.h"
void	ft_activate_roar(t_engine *e)
{
	if (e->player.soar == 0)
	{
		e->player.jump++;
		e->player.soar++;
		if (e->mus.jump != NULL)
			Mix_PlayChannel(-1, e->mus.jump, 0);
	}
}

void	ft_activate_squats(t_engine *e)
{
	if (e->player.squats == 0)
	{
		e->player.seat++;
		e->player.squats++;
		// if (e->mus.jump != NULL)
		// 	Mix_PlayChannel(-1, e->mus.jump, 0);
	}

}

void	ft_wsad(t_engine *e, Uint8 *state)
{

	if (state[SDL_SCANCODE_W])
		ft_w(e);
	if (state[SDL_SCANCODE_S])
		ft_s(e);
	if (state[SDL_SCANCODE_A])
		ft_a(e);
	if (state[SDL_SCANCODE_D])
		ft_d(e);
}

void	ft_activate_shoot(t_engine *e)
{
	if (e->player.shoot == 0)
	{
		e->player.shot = 1;
		if (e->player.ammo == 0)
			if (e->mus.empty)
				Mix_PlayChannel(-1, e->mus.empty, 0);
	}
}

void	ft_ml_player_input(t_engine *e, Uint8 *state)
{
	t_xyz  pos;
	float	x;
	float	y;
	float	z;

	pos.x = e->player.where.x;
	pos.y = e->player.where.y;
	pos.z = e->player.where.z;
	ft_wsad(e, state);
	if (state[SDL_SCANCODE_SPACE])
		ft_activate_roar(e);
	if (state[SDL_SCANCODE_LSHIFT])
		e->player.speed = 0.3;
	else
		e->player.speed = 0.1;
	if (state[SDL_SCANCODE_LCTRL])
		ft_putendl("lCTRL");
	if (state[SDL_SCANCODE_C])
		ft_activate_squats(e);
	else
		ft_stand_up(e);
	//printf("try(%f% f %f), was (%f% f %f)\n", e->player.where.x, e->player.where.y, e->player.where.z, pos.x, pos.y, pos.z);
	ft_collision(e, &pos);
}
