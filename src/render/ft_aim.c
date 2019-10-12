#include "engine.h"

void	ft_aim(t_engine *e)
{
	e->sdl.destin.x = W / 2 - 127;
	e->sdl.destin.y = H / 2 - 127;
	SDL_BlitSurface(e->sdl.aim , NULL, e->sdl.sur_ptr, &(e->sdl.destin));
}