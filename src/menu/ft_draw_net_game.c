#include "engine.h"

void	ft_make_full_path_for_map(t_engine *e)
{ 
	char *str;
	char *tmp;

	str = "./.net_maps/";

	tmp = ft_strdup(e->map);
	free(e->map);
	e->map = ft_strjoin(str, tmp);
	free(tmp);
	printf("full path->%s\n", e->map);
}

void	ft_draw_net_game(t_engine *e)
{
	if (Mix_PlayingMusic() == 1)
		Mix_HaltMusic();
	SDL_mutex *mutex;
	mutex = SDL_CreateMutex();

	//printf("i'am here \n");

	if (e->choose_map == 'Y')
	{
		//printf ("i go to clone\n");
		//временнное условие
		if (e->host_fl == 'C')
			if (system("sh ./scripts/maps_dow.sh") == -1)
				ft_return("error: clone");
		// if (e->client_fl == 'C')
		// 	SDL_Delay(50);

		e->choose_map = 'R';
	}
	else if (e->choose_map == 'R' && (e->host_fl == 'C' || e->client_fl == 'C'))
	{
		//printf("choose_map\n");
		ft_choose_map(e);
	}
	else if (e->choose_map == 'W' && (e->host_fl == 'C' || e->client_fl == 'C'))
	{
		//printf("daraw choose_map\n");
		ft_draw_choose_map(e);
	}
	// if (e->choose_map == 'R' && e->client_fl == 'C')
	// {


	// }


	else if (e->choose_map == 'I')
	{
		ft_make_full_path_for_map(e);
		if (e->client_fl == 'C')
		{
			ft_putendl("i am client");
			ft_draw_game(e);
			e->choose_map = 'P';
			//e->sdl.img_ptr = IMG_Load("src/images/client_forest_for_server.png");
		}
		else if (e->host_fl == 'C')
		{
			ft_putendl("i am server");
			ft_draw_game(e);
			e->choose_map = 'P';
			//e->sdl.img_ptr = IMG_Load("src/images/server_forest_for_client.png");
		}



		ft_putendl("kill1");
		ft_putendl("*** data another ***");
		printf("%s\n",e->dat_anot);
		// ft_putendl(ft_itoa(e->data_another[0].x));
		// ft_putendl(ft_itoa(e->data_another[0].y));

		ft_putendl("*** data my ***");
		printf("%s\n",e->dat_my);
		// ft_putendl(ft_itoa(e->data_my[0].x));
		// ft_putendl(ft_itoa(e->data_my[0].y));
		ft_putendl("kill2");
		SDL_LockMutex(mutex);
		e->net_fl = 'S';
		SDL_UnlockMutex(mutex);
		SDL_DestroyMutex(mutex);
		SDL_BlitSurface(e->sdl.img_ptr, NULL, e->sdl.sur_ptr, NULL);
		SDL_UpdateWindowSurface(e->sdl.win_ptr);
		SDL_Delay(1000);
	}

}
