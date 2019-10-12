#include "engine.h"

void		ft_return(char *str)
{
	ft_putendl(str);
	exit(-1);
}

/* получает часы */
int	ft_time()
{
	long int	ttime;

	ttime = 0;
	ttime = time (NULL);
	ttime = ttime % 86400 /3600; //получим по гринвичу
	ttime += 3;
	if (ttime >= 24)
		ttime -= 24;
	return(ttime);
}
/* delay in sec */
void	ft_delay_sec(int sec)
{
	long int	time_st;

	time_st = time(NULL);
	while (1)
		if ((time(NULL) - time_st) >= sec)
			return ;
}

void	ft_surface_set_pixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
	Uint32	*target_pixel;

	if (x < 0 || y < 0 || x >= surface->w || y >= surface->h)
		return ;
	target_pixel = (Uint32 *)((Uint8* )surface->pixels + y *
		surface->pitch + x * sizeof(*target_pixel));
	*target_pixel = color;
}

Uint32	ft_surface_get_pixel(SDL_Surface *sur, int x, int y)
{
	Uint32 *pixels;

	if (x < 0 || y < 0 || x >= sur->w || y >= sur->h)
		return (0);
	pixels = (Uint32 *)sur->pixels;
	return (pixels[y * sur->w + x]);
}
