#include "doom.h"

void	ft_surface_set_pixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
	Uint32		*target_pixel;

	if (x < 0 || y < 0 || x >= surface->w || y >= surface->h)
		return ;
	target_pixel = (Uint32 *)((Uint8 *)surface->pixels + y *
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

void	ft_clear_surface(t_doom *d)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++x < d->width)
	{
		y = -1;
		while (++y < d->height)
			ft_surface_set_pixel(d->sdl.sur_ptr, x, y, 0x000000);
	}
}

Uint32	ft_texture_get_pixel(SDL_Surface *surface, int x, int y, int scale)
{
	double		res[3];
	Uint32		tmp;
	int			x1;
	int			y1;

	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	y1 = y - 1;
	while (++y1 < y + scale)
	{
		x1 = x - 1;
		if (y1 < surface->h)
			while (++x1 < x + scale)
			{
				if (x1 == surface->w)
					break ;
				tmp = ((Uint32 *)surface->pixels)[y1 * surface->w + x1];
				res[0] += (tmp & 0xFF) / (double)(scale * scale);
				res[1] += (((tmp >> 8) & 0xFF) / (double)(scale * scale));
				res[2] += (((tmp >> 16) & 0xFF) / (double)(scale * scale));
			}
	}
	return ((int)res[0] | (int)res[1] << 8 | (int)res[2] << 16);
}
