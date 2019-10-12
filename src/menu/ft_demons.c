#include "engine.h"

void	ft_demons_five(t_engine *e)
{
	int		i;
	int		j;
	size_t	c;
	size_t	nc;

	j = 0;
	c = ft_surface_get_pixel(e->sdl.img_ptr, 0, 0);
	while (j < 200)
	{
		i = 0;
		while (i < 200)
		{
			if (c != (nc = ft_surface_get_pixel(e->sdl.img_ptr,
				((double)(i + 40) * 70)
				/ 200, ((double)(j + 250) * 70) / 200)))
				ft_surface_set_pixel(e->sdl.sur_ptr, i + 1200, j + 700, nc);
			i++;
		}
		j++;
	}
	Mix_PlayChannel(-1, e->mus.intro_bite , 0);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	ft_delay_sec(1);
	free(e->sdl.img_ptr);
}

void	ft_demons_four(t_engine *e)
{
	int		i;
	int		j;
	size_t	c;
	size_t	nc;

	j = 0;
	c = ft_surface_get_pixel(e->sdl.img_ptr, 0, 0);
	while (j < 200)
	{
		i = 0;
		while (i < 200)
		{
			if (c != (nc = ft_surface_get_pixel(e->sdl.img_ptr,
				((double)(i + 270) * 70) / 200,
				((double)(j + 250) * 70) / 200)))
				ft_surface_set_pixel(e->sdl.sur_ptr, i + 300, j + 800, nc);
			i++;
		}
		j++;
	}
	Mix_PlayChannel(-1, e->mus.intro_bite , 0);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	ft_delay_sec(1);
	ft_demons_five(e);
}

void	ft_demons_three(t_engine *e)
{
	int		i;
	int		j;
	size_t	c;
	size_t	nc;

	j = 0;
	c = ft_surface_get_pixel(e->sdl.img_ptr, 0, 0);
	while (j < 200)
	{
		i = 0;
		while (i < 200)
		{
			if (c != (nc = ft_surface_get_pixel(e->sdl.img_ptr,
				((double)(i + 470) * 70) / 200,
				((double)(j + 250) * 70) / 200)))
				ft_surface_set_pixel(e->sdl.sur_ptr, i + 1000, j + 500, nc);
			i++;
		}
		j++;
	}
	Mix_PlayChannel(-1, e->mus.intro_bite , 0);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	ft_delay_sec(1);
	ft_demons_four(e);
}

void	ft_demons_two(t_engine *e)
{
	int		i;
	int		j;
	size_t	c;
	size_t	nc;

	j = 0;
	c = ft_surface_get_pixel(e->sdl.img_ptr, 0, 0);
	while (j < 200)
	{
		i = 0;
		while (i < 200)
		{
			if (c != (nc = ft_surface_get_pixel(e->sdl.img_ptr,
				((double)(i + 660) * 70) / 200, ((double)j * 91) / 200)))
				ft_surface_set_pixel(e->sdl.sur_ptr, i + 1000, j + 8000, nc);
			i++;
		}
		j++;
	}
	Mix_PlayChannel(-1, e->mus.intro_bite , 0);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	ft_delay_sec(1);
	ft_demons_three(e);
}

void	ft_demons_one(t_engine *e)
{
	int		i;
	int		j;
	size_t	c;
	size_t	nc;

	j = -1;
	ft_music_stop_start(e, "src/music/thunder2.mp3");
	if (!(e->sdl.img_ptr = IMG_Load("src/demons/Cacodemon.png")))
		ft_return("error: malloc");
	c = ft_surface_get_pixel(e->sdl.img_ptr, 0, 0);
	while (++j < 200)
	{
		i = 0;
		while (i < 200)
		{
			if (c != (nc = ft_surface_get_pixel(e->sdl.img_ptr,
				((double)(i + 870) * 70) / 200, ((double)j * 91) / 200)))
				ft_surface_set_pixel(e->sdl.sur_ptr, i + 500, j + 500, nc);
			i++;
		}
	}
	Mix_PlayChannel(-1, e->mus.intro_bite, 0);
	SDL_UpdateWindowSurface(e->sdl.win_ptr);
	ft_delay_sec(1);
	ft_demons_two(e);
}
