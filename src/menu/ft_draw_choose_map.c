#include "engine.h"

void	ft_additional_text(t_engine *e, SDL_Rect dest)
{
	t_text		tex;

	dest.x -= 500;
	if (e->host_fl == 'C')
	{
		ft_fill_text_struct(&tex, dest.x, dest.y, 40);
		ft_fill_text_struct_c(&tex, 0xff, 0xff, 0xff);
		tex.text = "You're host,";
		ft_text(&tex, e);
		dest.y += 50;
		ft_fill_text_struct(&tex, dest.x, dest.y, 30);
		ft_fill_text_struct_c(&tex, 0xff, 0xff, 0xff);
		tex.text = "choose map";
		ft_text(&tex, e);

	}
	else if (e->client_fl == 'C')
	{
		ft_fill_text_struct(&tex, dest.x, dest.y, 40);
		ft_fill_text_struct_c(&tex, 0xff, 0xff, 0xff);
		tex.text = "You're client,";
		ft_text(&tex, e);
		dest.y += 50;
		ft_fill_text_struct(&tex, dest.x, dest.y, 30);
		ft_fill_text_struct_c(&tex, 0xff, 0xff, 0xff);
		tex.text = "waiting for a map";
		ft_text(&tex, e);
	}
}

void	ft_draw_select(t_engine *e, int x, int y)
{
	//printf("draw select \n");
	int i;
	int j;
	int lim_x = 0;
	int lim_y = 0;


	j = y;
	lim_x = x + 20;
	lim_y = y + 20;
	while (j < lim_y)
	{
		i = x;
		while (i <lim_x)
		{
			ft_surface_set_pixel(e->sdl.sur_ptr, i, j, 0xFFBF73);
			i++;
		}
		j++;
	}
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
}

void	ft_draw_choose_map(t_engine *e)
{
	int i;
	SDL_Rect	dest;
	t_text		tex;

	dest.x = 800;
	dest.y = 300;

	i = 0;
	ft_bzero(e->sdl.sur_ptr->pixels, sizeof(int) * H * W);
	SDL_BlitSurface(e->sdl.blood_mask, NULL, e->sdl.sur_ptr, NULL);

	ft_additional_text(e, dest);

	while (e->maps[i])
	{
		ft_fill_text_struct(&tex, dest.x, dest.y, 30);
		ft_fill_text_struct_c(&tex, 0xff, 0xff, 0xff);
		tex.text = e->maps[i];
		ft_text(&tex, e);
		dest.y += 50;
		i++;
	}
	if (e->host_fl == 'C' && e->fl_select == 'Y')
	{
		//printf("try draw select\n");
		int start_y = ((dest.y + 50 * (((e->m_y - dest.y) / 50) - 1)));
		start_y += 13;
		ft_draw_select(e, dest.x - 50, start_y); //получили у какой это все карты
	}
}