#include "engine.h"

void	ft_mouse_maps(t_engine *e)
{
	SDL_GetMouseState(&e->m_x, &e->m_y);
	int max_x;
	int max_y;

	max_x = 800 + e->max_len_name_map * 25;
	max_y = (300 + 50 * e->nb_map);
	//printf("max x y (%d, %d)\n", max_x, max_y);
	//e->max_len_name_map * 5)
	//e->m_y < (300 + 50 * e->nb_map)
	//printf("i'm at mose maps\n");
		if (e->m_x > 800 && e->m_x < max_x && e->m_y > 300 && e->m_y < max_y)
		{
			e->fl_select = 'Y';
			//ft_draw_choose_map(e);
			//printf("select, fl->%c\n", e->fl_select);
		}
		else
		{
			e->fl_select = 'N';
			//printf("UNselect, fl->%c\n", e->fl_select);
			e->m_x = 0;
			e->m_y = 0;
		}
	ft_draw_choose_map(e);
}

void	ft_mouse_maps_select(t_engine *e)
{
	int max_x;
	int max_y;
	SDL_mutex *mutex;

	mutex = SDL_CreateMutex();
	SDL_GetMouseState(&e->m_x, &e->m_y);
	max_x = 800 + e->max_len_name_map * 25;
	max_y = (300 + 50 * e->nb_map);



	if (e->m_x > 800 && e->m_x < max_x && e->m_y > 300 && e->m_y < max_y)
	{
		int nb_map = 0;
		nb_map = (e->m_y - 300) / 50;
		e->map = ft_strdup(e->maps[nb_map]);
		printf("map from server from mouse choose->%s\n", e->map);
		//отфришить e->maps
		//ft_free_mass(&e->maps); разобраться  с этой функцией
		//
		SDL_LockMutex(mutex);
		e->map_choosen = 'Y';
		printf("1mouse e->map_choosen -> %c\n", e->map_choosen);
		SDL_UnlockMutex(mutex);
		SDL_DestroyMutex(mutex);
		printf("2mouse e->map_choosen -> %c\n", e->map_choosen);

	}
	//printf("host mouse button press\n");

}