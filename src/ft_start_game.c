#include "engine.h"

void	ft_load_and_blit(t_engine *e)
{
	e->sdl.destin.x = 0;
	e->sdl.destin.y = 850;
	SDL_BlitSurface(e->sdl.gui, NULL, e->sdl.sur_ptr, &(e->sdl.destin));
}

void	ft_start_game(t_engine *e)
{
	if (Mix_PlayingMusic() == 1)
	{
		Mix_HaltMusic();
		Mix_FreeMusic(e->mus.gmusic);
		e->mus.gmusic = NULL;
	}
	//printf("fall here4\n");
	ft_engine_start(e);
	ft_load_and_blit(e);
	ft_gui(e);
}
