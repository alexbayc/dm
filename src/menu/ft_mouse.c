#include "engine.h"

static void	ft_norm(t_engine *e)
{
	Mix_PlayChannel(-1, e->mus.mouse, 0);
	e->host_fl = 'N';
	e->net_err_fl = 'Y';
	e->client_fl = 'N';
	ft_putendl("BACK game button at host/client");
	e->menu_fl = 'M';
	e->net_err_fl = 'N';
	e->vist_net_fl = '\0';
	if (e->host_name)
		ft_strclr(e->host_name);
	ft_menu_net(e);
}

void		ft_net_zone(t_engine *e)
{
	if (e->m_x >= 1440 && e->m_x <= 1835 && e->menu_fl == 'M')
	{
		if ((e->m_y >= 160 && e->m_y <= 320) && (e->vist_net_fl == '\0'))
		{
			ft_putendl("HOST game button");
			Mix_PlayChannel(-1, e->mus.mouse, 0);
			e->net_fl = 'Y';
			e->host_fl = 'Y';
			e->vist_net_fl = 'Y';
		}
		else if ((e->m_y >= 160 + 200 && e->m_y <= 320 + 200) && (e->vist_net_fl == '\0'))
		{
			ft_putendl("CLIENT game button");
			Mix_PlayChannel(-1, e->mus.mouse, 0);
			e->net_fl = 'Y';
			e->client_fl = 'Y';
			e->vist_net_fl = 'Y';
		}
		else if (e->m_y >= 160 + 400 && e->m_y <= 320 + 400
			&& e->host_fl == 'N' && e->client_fl == 'N')
		{
			ft_putendl("BACK game button");
			Mix_PlayChannel(-1, e->mus.mouse, 0);
			if (e->host_name)
				ft_strclr(e->host_name);
			e->vist_net_fl = '\0';
			e->net_err_fl = 'N';
			ft_menu_spec(e);
		}
		else if (e->m_y >= 160 + 400 && e->m_y <= 320 + 400
			&& (e->host_fl != 'N' || e->client_fl != 'N'))
			ft_norm(e);
	}
}

void		ft_check_button_zone(t_engine *e)
{
	if (e->m_x >= 1440 && e->m_x <= 1835 && e->menu_fl == 'Y')
	{
		if (e->m_y >= 160 && e->m_y <= 320)
		{
			Mix_PlayChannel(-1, e->mus.mouse, 0);
			ft_putendl("START game button");
			printf("start mouse(%d %d)\n", e->m_x, e->m_y);
			e->mouse_fl = 'N';
			e->menu_fl = 'S';
		}
		else if (e->m_y >= 160 + 200 && e->m_y <= 320 + 200)
		{
			ft_putendl("NET game button");
			Mix_PlayChannel(-1, e->mus.mouse, 0);
			e->menu_fl = 'M';
			ft_menu_net(e);
		}
		else if (e->m_y >= 160 + 400 && e->m_y <= 320 + 400)
		{
			Mix_PlayChannel(-1, e->mus.mouse, 0);
			ft_exit_x(e);
		}
		else if (e->m_y >= 160 + 600 && e->m_y <= 320 + 600)
		{
			/* execute mapeditor */
			Mix_PlayChannel(-1, e->mus.mouse, 0);
			ft_putendl("Mapeditor game button");
			system("./maped");
			ft_putendl("Mapeditor game button");
		}
	}
	else
		ft_net_zone(e);
}

void		ft_check_tab_zone(t_engine *e)
{
	if(e->menu_fl != 'M')
	{
		if (e->menu_fl == 'D' || e->menu_fl == 'T' || e->player.health == 0 )
		{
			printf("here in tab\n");
			if (e->m_y >= 160 && e->m_y <= 320)
			{
				Mix_PlayChannel(-1, e->mus.mouse, 0);
				ft_putendl("menu");
				ft_free_all_in_engine(e);
				//тут что-то надо отфришить чтобы корректно работало

				ft_menu_spec(e);
			}
			else if (e->m_y >= 160 + 200 && e->m_y <= 320 + 200 && e->player.health > 0)
			{
				Mix_PlayChannel(-1, e->mus.mouse, 0);
				ft_putendl("CONTINUE");
				printf("fall here0\n");
				SDL_WarpMouseInWindow( e->sdl.win_ptr, W / 2, H / 2);
				printf("fall here1\n");
				SDL_SetRelativeMouseMode(SDL_TRUE);
				printf("fall here2\n");
				ft_draw_game(e);
				// ft_fill_for_g(e);
				// printf("fall here3\n");
				// ft_start_game(e);
				//how do we continue game?
			}
			else if (e->m_y >= 160 + 400 && e->m_y <= 320 + 400)
			{
				Mix_PlayChannel(-1, e->mus.mouse, 0);
				ft_exit_x(e);
			}
		}
	}
}

int				ft_ch_mouse(t_engine *e)
{
	SDL_GetMouseState(&e->m_x, &e->m_y);
	e->mouse_fl = 'Y';
	if (e->mouse_fl == 'Y' && (e->menu_fl == 'Y' || e->menu_fl == 'M'))
		ft_check_button_zone(e);
	if (e->mouse_fl == 'Y' && (e->menu_fl == 'D' || e->menu_fl == 'T' || e->player.health <= 0))
		ft_check_tab_zone(e);
	if (e->choose_map == 'W' && e->host_fl == 'C' && e->map_choosen != 'Y')
	{
		//printf("here mouse\n");
		ft_mouse_maps_select(e);

	}
	return (0);
}
