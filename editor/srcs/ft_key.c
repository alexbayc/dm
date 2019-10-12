#include "doom.h"

int				ft_exit_x(t_doom *d)
{
	SDL_DestroyWindow(d->sdl.win_ptr);
	SDL_Quit();
	exit(1);
	return (0);
}

int				ft_ch_key(t_doom *d)
{
	if (d->sdl.event.key.keysym.sym == SDLK_ESCAPE)
		ft_exit_x(d);
	else if (d->sdl.event.key.keysym.sym == SDLK_p)
	{
		if (!(d->flags & (1 << 3)))
			d->flags |= (1 << 3);
		else
			d->flags &= ~(1 << 3);
	}
	else if (d->sdl.event.key.keysym.sym == SDLK_UP || d->sdl.event.key.keysym.sym == SDLK_DOWN ||
		d->sdl.event.key.keysym.sym == SDLK_LEFT || d->sdl.event.key.keysym.sym == SDLK_RIGHT)
		ft_move_lst(d);
	else if (d->sdl.event.key.keysym.sym == SDLK_t)
	{
		if (!(d->flags & 1))
			d->flags |= 1;
		else
			d->flags &= ~(1);
	}
	else if (d->sdl.event.key.keysym.sym == SDLK_s)
		ft_check_sectors(d);
	ft_redraw(d);
	return (0);
}

int				ft_mv_flag(t_doom *f)
{

	int		x;
	int		y; 
	int		but;
	int		flag;

	flag = 1;
	x = f->sdl.event.button.x;
	y = f->sdl.event.button.y;
	f->x_s = f->line_x;
	f->y_s = f->line_y;
	but = f->sdl.event.button.button;
	//отжатие
	if (x <= f->border)
	{
		f->x_e = x;
		f->y_e = y;
		if (but == 1)
		{
			if (f->flags & (1 << 1))
				if (!ft_put_point(f))
					flag--;
			f->flags &= ~(1 << 1);
		}
	}
	else
		f->flags &= ~(1 << 1);
	return (flag);
}

int	ft_flag_draw(t_doom *f)
{
	int		x;
	int		y;
	int		but;

	but = f->sdl.event.button.button;
	x = f->sdl.event.button.x;
	y = f->sdl.event.button.y;
	//нажатие
	if (but == SDL_BUTTON_LEFT && x <= f->img.net.width && !f->flags)
	{
		f->line_x = x;
		f->line_y = y;
		f->flags |= (1 << 1);
		// printf("__________________%d %d\n", f->x_s, f->y_s);
	}
	else if (but == SDL_BUTTON_LEFT && ft_is_but_area(f->but[4], x, y))
		f->nb_tex_off++;	
	else if (but == SDL_BUTTON_LEFT && ft_is_but_area(f->but[5], x, y))
		f->nb_tex_off--;
	else if (but == SDL_BUTTON_LEFT && (f->flags & 1))
		ft_pick_texture(f);
	if (f->nb_tex_off == -1)
		f->nb_tex_off = f->nb_tex - 1;
	if (f->nb_tex_off == f->nb_tex)
		f->nb_tex_off = 0;
	x = x * 2500 / f->width;
	y = y * 1300 / f->height;
 	/*clean net*/
	if (but == SDL_BUTTON_LEFT && (x >= 2382 && x<= 2482 && y >= 1200 && y<= 1280 && !f->flags))
	{
		ft_free_lst(f, 0);
		ft_clear_net(f);
	}
	else if( but == SDL_BUTTON_LEFT && (x >=1812 && x<= 1912 && y >= 1200 && y <= 1280))
		ft_save_as(f);
	else if( but == SDL_BUTTON_LEFT && (x >=1951 && x<= 2051 && y >= 1200 && y <= 1280))
		ft_ctrl_z(f);
	if (!(f->flags & (1 << 1)))
		ft_redraw(f);
	return(1);
}

void			ft_key(t_doom *d)
{
	//mlx_hook(img->win_ptr, 3, 0, ft_reset_key, f);
	// mlx_hook(img->win_ptr, 2, 0, ft_ch_key, f); DONE
	// mlx_hook(img->win_ptr, 17, 0, ft_exit_x, img); DONE
	// mlx_hook(img->win_ptr, 5, 0, ft_mv_flag, f); // отжатие DONE
	// mlx_hook(img->win_ptr, 4, 0, ft_flag_draw, f); //нажатие DONE
	// mlx_hook(img->win_ptr, 6, 0, ft_draw_sector, f); //движение
	// mlx_loop_hook(img->mlx_ptr, ft_launch_loop_hook, f);
}
