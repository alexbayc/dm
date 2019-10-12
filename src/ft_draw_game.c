#include "engine.h"

void	musicFinished()
{
	printf("Music stopped.\n");
}

void	ft_fill_for_g(t_engine *e)
{
	e->menu_fl = 'G';
	e->mouse_fl = 'G';
}


void	ft_kruchu(t_sector *sec)
{
	int	i;
	t_xy	tmp;
	t_xy	bub;

	tmp.x = sec->vertex[1].x;
	tmp.y = sec->vertex[1].y;
	i = 0;
	while (i < sec->npoints)
	{
		sec->vertex[i].x = sec->vertex[i + 1].x;
		sec->vertex[i].y = sec->vertex[i + 1].y;
		i++;
	}
	sec->vertex[i].x = tmp.x;
	sec->vertex[i].y = tmp.y;
}

void	ft_krutani(t_engine *e)
{
	int	i;
	i = 0;

	while (i < e->num_sectors)
	{
		ft_kruchu(&e->sectors[i]);
		i++;
	}
}

void	ft_draw_game(t_engine *e)
{
	int	i;
	int j;

	j = 0;
	i = 0;
	if (!(e->menu_fl == 'D') && e->menu_fl != 'G')
	{
		printf("++++++I load data\n");
		if (ft_new_load_data(e, e->map) == 0)
			ft_return("error: load data");
		e->choose_map = 'D'; //data	
		ft_krutani(e);
		i = -1;
		ft_init_start_posotion(e);
		ft_init_coef(e);
		SDL_SetRelativeMouseMode(SDL_TRUE);
		e->player.where.z = e->sectors[e->player.sector].floor;
	}
	ft_fill_for_g(e);
	//check about it is the first game
	//if (!(e->menu_fl == 'D') && e->menu_fl != 'G';)
		//ft_draw_intro(e);
}
