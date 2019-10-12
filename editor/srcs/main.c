#include "doom.h"
#include <stdio.h>

void	ft_init_sdl(t_doom *d)
{
	if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
		ft_return("Can't initialize SDL");
	if (!(d->sdl.win_ptr = SDL_CreateWindow(d->titel,
											SDL_WINDOWPOS_CENTERED,
											SDL_WINDOWPOS_CENTERED,
											d->width, d->height,
											SDL_WINDOW_RESIZABLE)))
		ft_return("Can't create window");
	if (!(d->sdl.sur_ptr = SDL_GetWindowSurface(d->sdl.win_ptr)))
		ft_return("Can't get window surface");
}
void ft_init_lines(t_doom *d)
{
	//if (!(d->lines = (t_line *) malloc(sizeof(t_line))))
	//	ft_return("error: malloc");
	d->lines = NULL;

}

void	ft_init_borders(t_doom *d)
{
	if (d->sdl.event.window.event == SDL_WINDOWEVENT_RESIZED)
	{
		SDL_GetWindowSize(d->sdl.win_ptr, &d->width, &d->height);
		SDL_FreeSurface(d->sdl.sur_ptr);
		d->sdl.sur_ptr = SDL_GetWindowSurface(d->sdl.win_ptr);
	}
	d->img.net.height = d->height;
	d->img.net.width = d->width * 18 / 25 + 1;
	d->img.menu.height = d->height -2;
	d->img.menu.width = d->width * 7 / 25 - 2;
	d->border = d->width * 18 / 25 + 2;
}

void	ft_init(t_doom *d, int argc, char **argv)
{
	int		fd;

	d->height = 1300;
	d->width = 2500;
	d->titel = "MAPED";
	// d->c = 20;
	d->c = 50;
	d->scale = 1.0f;
	d->frame_size = 4;
	ft_init_borders(d);
	d->color.menu = 0x057D9FFF;
	d->color.menu_border = 0xFF8500FF;
	d->color.set = 0x1a3e70;
	d->color.draw = 0xCFF700;
	if (!(d->but = ft_memalloc(sizeof(t_button) * 6)) ||
			!(d->tex_but = ft_memalloc(sizeof(t_button) * 3)))
		ft_return("allocation fails");
	d->nb_ln = 0;
	system("rm -f editor/NESRAL.log");
	system("touch editor/NESRAL.log");
	system("rm -f editor/logs.txt");
	system("touch editor/logs.txt");
	d->log_fd = fopen("editor/logs.txt", "a+");
	d->part_ln = 0;
	ft_init_lines(d);
	d->flags = 0;
	d->flag_scroll = 0;
	d->nb_tex_off = 0;
	d->nb_tex_set = 0;
	d->tex_size = 256;
	d->point_lst = NULL;
	ft_nb_tex(d);
	if (!(d->textures = (SDL_Surface **)ft_memalloc(sizeof(SDL_Surface *) * (d->nb_tex + 1))) ||
		!(d->bmps = (SDL_Surface **)ft_memalloc(sizeof(SDL_Surface *) * (d->nb_tex + 1))) ||
		!(d->player = (t_player *)ft_memalloc(sizeof(t_player))))
		ft_return("error: malloc");
	ft_read_textures(d);
	ft_init_sdl(d);
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		ft_read_from_file(fd, d);
	}
}

void	ft_valid_arg(int argc, char **argv, t_doom *d)
{
	d->fd = 0;
	if (argc != 2)
		ft_return("Usage: maped map_name");
	else
	{ /* if file ex return error */
		d->fd = open(argv[1], O_RDWR | O_CREAT | O_EXCL , 777);
		if (d->fd == -1)
		{
			//ft_return("exist");
			d->fd = open(argv[1], O_RDWR);
			if (d->fd == -1)
				ft_return("error: file read");
		}
	}
}

int main(int argc, char **argv)
{
	t_doom	d;

	// ft_valid_arg(argc, argv, &d);
	ft_init(&d, argc, argv);
	ft_net(&d);
	ft_menu(&d);
	if (argc > 1)
	{
		ft_redraw(&d);	
		SDL_UpdateWindowSurface(d.sdl.win_ptr);
	}
	while(1)
		while(SDL_PollEvent(&d.sdl.event))
		{
			if(d.sdl.event.type == SDL_QUIT || (d.sdl.event.type == SDL_KEYDOWN && d.sdl.event.key.keysym.sym == SDLK_ESCAPE))
				ft_exit_x(&d);
			else if (d.sdl.event.window.event == SDL_WINDOWEVENT_RESIZED)
				ft_redraw(&d);
			else if (d.sdl.event.type == SDL_KEYDOWN && !(d.flags & (1 << 1)))
				ft_ch_key(&d);
			else if (d.sdl.event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (!(d.flags & (1 << 3)))
					ft_flag_draw(&d);
				else if (d.sdl.event.button.button == SDL_BUTTON_LEFT)
					ft_place_player(&d);
				else if (d.sdl.event.button.button == SDL_BUTTON_RIGHT && (d.flags & (1 << 3)))
				{
					ft_putendl("kek");
					d.flags |= (1 << 4);
					d.mouse.x = d.sdl.event.button.x;
					d.mouse.y = d.sdl.event.button.y;
				}
			}
			else if (d.sdl.event.type == SDL_MOUSEBUTTONUP)
			{
				if (!ft_mv_flag(&d))
					ft_check_sectors(&d);
				ft_redraw(&d);
				if (d.sdl.event.button.button == SDL_BUTTON_RIGHT)
					d.flags &= ~(1 << 4);
			}
			else if (d.sdl.event.type == SDL_MOUSEWHEEL && !(d.flags & (1 << 1)))
			{
				ft_change_net_scale(&d);
				ft_redraw(&d);
			}
			else if (d.sdl.event.type == SDL_MOUSEMOTION && ((d.flags & 1) || d.flags & (1 << 1) || d.flags & (1 << 3)))
				ft_redraw(&d);
			if (d.sdl.event.type == SDL_MOUSEMOTION && (d.flags & (1 << 4)) && (d.flags & (1 << 3)))
				ft_change_player_angle(&d);
			SDL_UpdateWindowSurface(d.sdl.win_ptr);
		}
	return (0);
}
