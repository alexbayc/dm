#include "engine.h"

void	ft_main_loop(t_engine *e, SDL_Thread **thread)
{
	SDL_mutex	*mutex;

	mutex = SDL_CreateMutex();
	const Uint8 *state;
	while (1)
	{
		while (SDL_PollEvent(&(e->sdl.event)))
		{
			if (e->sdl.event.type == SDL_QUIT ||
				(e->sdl.event.type == SDL_KEYDOWN
					&& e->sdl.event.key.keysym.sym == SDLK_ESCAPE))
				ft_exit_x(e);
			else if ((e->sdl.event.type == SDL_KEYDOWN
				|| e->sdl.event.type == SDL_KEYUP))
				ft_ch_key(e);
			else if (e->sdl.event.type == SDL_MOUSEBUTTONDOWN
				&& e->sdl.event.button.button == 1 && e->mouse_fl != 'G')
				ft_ch_mouse(e);
			else if (e->sdl.event.type == SDL_MOUSEMOTION
				&& e->menu_fl == 'G' && e->player.health > 0)
				ft_mouse_game(e);
			else if (e->sdl.event.type == SDL_MOUSEMOTION
				&& (e->choose_map == 'W') && e->host_fl == 'C' && e->map_choosen != 'Y')
				ft_mouse_maps(e);
			else if (e->sdl.event.type == SDL_MOUSEBUTTONDOWN
				&& e->sdl.event.button.button == 1 && e->mouse_fl == 'G' && e->player.health > 0)
			{
				ft_activate_shoot(e);
			}
		}
		if ((state = SDL_GetKeyboardState(NULL)) != 0 &&
			(e->menu_fl == 'G') && e->player.health > 0)
			{

			ft_ml_player_input(e, (Uint8 *)state);
			}
			//&& e->host_fl == 'N' && e->client_fl == 'N'

		ft_draw_func(e);
	}
	SDL_DestroyMutex(mutex);
}

void	ft_general_loop(t_engine *e)
{
	SDL_Thread	*thread;

	thread = SDL_CreateThread(ft_connect, "second thread", (void *)e);
	if (NULL == thread)
		ft_return("error: SDL_CreateThread failed");
	if (e->menu_fl == 'G')
	{
		ft_putendl("i will close thread");
		SDL_WaitThread((thread), NULL);
		ft_putendl("i closed thread");
	}
	ft_main_loop(e, &thread);
	SDL_WaitThread(thread, NULL);
}
