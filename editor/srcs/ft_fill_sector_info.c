#include "doom.h"

static int	ft_valid_sec_info(t_sector_lst *sec)
{
	if (sec->floor > sec->ceiling)
		return (0);
	return (1);
}

static int	ft_loop_sec_menu(t_doom *d, t_sector_lst *sec)
{
	int		x;
	int		y;

	while (SDL_PollEvent(&d->sdl.event))
	{
		x = d->sdl.event.button.x;
		y = d->sdl.event.button.y;
		if (d->sdl.event.type == SDL_MOUSEBUTTONDOWN &&
			d->sdl.event.button.button == SDL_BUTTON_LEFT)
		{
			if (ft_is_but_area(d->smenu.ok, d->sdl.event.button.x,
				d->sdl.event.button.y))
			{
				if (ft_valid_sec_info(sec))
					sec->valid = 1;
				return (sec->valid);
			}
			else if (ft_is_but_area(d->smenu.ce_num, x, y))
				d->flags = (1 << 3);
			else if (ft_is_but_area(d->smenu.fl_num, x, y))
				d->flags = (1 << 4);
			else
			{
				d->flags = 0;
				if (ft_is_but_area(d->smenu.ce_right, x, y))
					ft_change_ceil_texture(d, sec, 1);
				else if (ft_is_but_area(d->smenu.ce_left, x, y))
					ft_change_ceil_texture(d, sec, -1);
				if (ft_is_but_area(d->smenu.fl_right, x, y))
					ft_change_floor_texture(d, sec, 1);
				else if (ft_is_but_area(d->smenu.fl_left, x, y))
					ft_change_floor_texture(d, sec, -1);
			}
		}
		else if (d->sdl.event.type == SDL_KEYDOWN)
		{
			if (d->sdl.event.key.keysym.sym == SDLK_RETURN)
			{
				if (ft_valid_sec_info(sec))
					sec->valid = 1;
				return (sec->valid);
			}
			else if (d->flags == 1 << 3)
				ft_change_num(d, &sec->ceiling);
			else if (d->flags == 1 << 4)
				ft_change_num(d, &sec->floor);
		}
		ft_redraw(d);
		ft_init_menu(d, sec);
		SDL_UpdateWindowSurface(d->sdl.win_ptr);
	}
	return (0);
}

void		ft_fill_sector_info(t_doom *d)
{
	t_sector_lst *cur_sec;

	cur_sec = d->sect_head;
	while (cur_sec)
	{
		if (cur_sec->valid == 0)
		{
			ft_init_menu(d, cur_sec);
			SDL_UpdateWindowSurface(d->sdl.win_ptr);
			while (1)
			{
				if (ft_loop_sec_menu(d, cur_sec))
					break ;
			}
		}
		cur_sec = cur_sec->next;
	}
}
