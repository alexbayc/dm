#include "doom.h"


static void				ft_x(t_doom *k, t_b *b, char flag, int col)
{
	b->d = (b->dy << 1) - b->dx;
	b->d1 = b->dy << 1;
	b->d2 = (b->dy - b->dx) << 1;
	if (flag == 'N')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, k->color.draw);
	else if (flag == 'M')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, col);
	b->x = k->x_s + b->sx;
	b->y = k->y_s;
	while (b->i < b->dx)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->y += b->sy;
		}
		else
			b->d += b->d1;
		if (flag == 'N')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, k->color.draw);
		else if (flag == 'M')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, col);
		b->x += b->sx;
		b->i++;
	}
}

static void				ft_y(t_doom *k, t_b *b, char flag, int col)
{
	b->d = (b->dx << 1) - b->dy;
	b->d1 = b->dx << 1;
	b->d2 = (b->dx - b->dy) << 1;
	if (flag == 'N')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, k->color.draw);
	else if (flag == 'M')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, col);
	b->x = k->x_s;
	b->y = k->y_s + b->sy;
	while (b->i < b->dy)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->x += b->sx;
		}
		else
			b->d += b->d1;
		if (flag == 'N')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, k->color.draw);
		else if (flag == 'M')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, col);
		b->y += b->sy;
		b->i++;
	}
}

void				ft_draw_start_end(t_doom *d, int size)
{
	t_b		b;

	b.i = 0;
	b.dx = size * 2;
	b.dy = 0;
	b.sx = 1;
	b.sy = 1;
	d->x_s -= size;
	d->y_s += size;
	ft_x(d, &b, 'M', 0xFFFFFF);
	d->y_s -= size * 2;
	b.i = 0;
	ft_x(d, &b, 'M', 0xFFFFFF);
	b.i = 0;
	b.dx = 0;
	b.dy = size * 2;
	ft_y(d, &b, 'M', 0xFFFFFF);
	b.i = 0;
	d->x_s += size * 2;
	ft_y(d, &b, 'M', 0xFFFFFF);
	b.i = 0;
	b.dx = size * 2;
	b.dy = 0;
	d->x_s = d->x_e - size;
	d->y_s = d->y_e + size;
	ft_x(d, &b, 'M', 0xFFFFFF);
	d->y_s -= size * 2;
	b.i = 0;
	ft_x(d, &b, 'M', 0xFFFFFF);
	b.i = 0;
	b.dx = 0;
	b.dy = size * 2;
	ft_y(d, &b, 'M', 0xFFFFFF);
	b.i = 0;
	d->x_s += size * 2;
	ft_y(d, &b, 'M', 0xFFFFFF);
}

void					ft_brasenham(t_doom *k, char flag, int col)
{
	t_b					b;

	b.i = 0;
	b.dx = (k->x_e > k->x_s) ? (k->x_e - k->x_s) : (k->x_s - k->x_e);
	b.dy = (k->y_e > k->y_s) ? (k->y_e - k->y_s) : (k->y_s - k->y_e);
	b.sx = (k->x_e >= k->x_s) ? (1) : (-1);
	b.sy = (k->y_e >= k->y_s) ? (1) : (-1);
	if (b.dy < b.dx)
		ft_x(k, &b, flag, col);
	else
		ft_y(k, &b, flag, col);
}

static void				ft_coord_x(t_doom *k, t_b *b, char flag, int col)
{
	b->d = (b->dy << 1) - b->dx;
	b->d1 = b->dy << 1;
	b->d2 = (b->dy - b->dx) << 1;
	if (flag == 'N')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, k->color.draw);
	else if (flag == 'M')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, col);
	b->x = k->x_s + b->sx;
	b->y = k->y_s;
	while (b->i < b->dx)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->y += b->sy;
		}
		else
			b->d += b->d1;
		if (flag == 'N')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, k->color.draw);
		else if (flag == 'M')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, col);
		if (abs((int)sqrt(pow(k->x_s - b->x, 2) + pow(k->y_s - b->y, 2)) % ((int)(k->c * k->scale))) <= 1)
		{
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, 0x55FF55);
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x + 1, b->y, 0x55FF55);
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y + 1, 0x55FF55);
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x + 1, b->y + 1, 0x55FF55);
		}
		b->x += b->sx;
		b->i++;
	}
}

static void				ft_coord_y(t_doom *k, t_b *b, char flag, int col)
{
	b->d = (b->dx << 1) - b->dy;
	b->d1 = b->dx << 1;
	b->d2 = (b->dx - b->dy) << 1;
	if (flag == 'N')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, k->color.draw);
	else if (flag == 'M')
		ft_surface_set_pixel(k->sdl.sur_ptr, k->x_s, k->y_s, col);
	b->x = k->x_s;
	b->y = k->y_s + b->sy;
	while (b->i < b->dy)
	{
		if (b->d > 0)
		{
			b->d += b->d2;
			b->x += b->sx;
		}
		else
			b->d += b->d1;
		if (flag == 'N')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, k->color.draw);
		else if (flag == 'M')
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, col);
		if (abs((int)sqrt(pow(k->x_s - b->x, 2) + pow(k->y_s - b->y, 2)) % ((int)(k->c * k->scale))) <= 1)
		{
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y, 0x55FF55);
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x + 1, b->y, 0x55FF55);
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x, b->y + 1, 0x55FF55);
			ft_surface_set_pixel(k->sdl.sur_ptr, b->x + 1, b->y + 1, 0x55FF55);
		}
		b->y += b->sy;
		b->i++;
	}
}

void					ft_coord_brasenham(t_doom *k, char flag, int col)
{
	t_b					b;

	b.i = 0;
	b.dx = (k->x_e > k->x_s) ? (k->x_e - k->x_s) : (k->x_s - k->x_e);
	b.dy = (k->y_e > k->y_s) ? (k->y_e - k->y_s) : (k->y_s - k->y_e);
	b.sx = (k->x_e >= k->x_s) ? (1) : (-1);
	b.sy = (k->y_e >= k->y_s) ? (1) : (-1);
	if (b.dy < b.dx)
		ft_coord_x(k, &b, flag, col);
	else
		ft_coord_y(k, &b, flag, col);
}

