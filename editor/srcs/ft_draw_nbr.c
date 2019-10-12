#include "doom.h"

static void	ft_draw_null(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e;
	d->y_s = d->y_s + 30 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_e = b->x + off;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e;
	d->y_s = b->y + 5 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_one(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off + 20 * b->x_len / 120;
	d->x_e = d->x_s;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->y_e = d->y_s + 30 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_two(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e;
	d->y_s = d->y_s + 15 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_e = b->x + off;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e;
	d->y_s = d->y_s + 15 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_three(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e;
	d->y_s = d->y_s - 30 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_four(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s;
	d->y_e = d->y_s + 15 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e + 20 * b->x_len / 120;
	d->y_s = d->y_e;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_e = d->x_s;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->y_e = d->y_s + 30 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_five(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e;
	d->y_s = d->y_s - 15 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = b->x + off;
	d->x_e = d->x_s;
	d->y_e = d->y_s - 15 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_six(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_e = d->x_s;
	d->y_s = b->y + 5 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_s + 20 * b->x_len / 120;
	d->x_e = d->x_s;
	d->y_s = d->y_s + 15 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_seven(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_e + 30 * b->y_len / 40;
	d->x_s = d->x_e;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_eight(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_e = d->x_s;
	d->y_s = b->y + 5 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->x_s = d->x_e;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

static void	ft_draw_nine(t_doom *d, int num, int off, t_button *b)
{
	d->x_s = b->x + off;
	d->y_s = b->y + 5 * b->y_len / 40;
	d->x_e = d->x_s + 20 * b->x_len / 120;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->y_s = d->y_s + 15 * b->y_len / 40;
	d->y_e = d->y_s;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = d->x_e;
	d->y_s = b->y + 5 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
	d->x_s = b->x + off;
	d->x_e = d->x_s;
	d->y_e = d->y_s + 15 * b->y_len / 40;
	ft_brasenham(d, 'M', 0xCCCCCC);
}

void		ft_draw_nbr(t_doom *d, int num, int off, t_button *but)
{
	if (num == 0)
		ft_draw_null(d, num, off, but);
	if (num == 1)
		ft_draw_one(d, num, off, but);
	if (num == 2)
		ft_draw_two(d, num, off, but);
	if (num == 3)
		ft_draw_three(d, num, off, but);
	if (num == 4)
		ft_draw_four(d, num, off, but);
	if (num == 5)
		ft_draw_five(d, num, off, but);
	if (num == 6)
		ft_draw_six(d, num, off, but);
	if (num == 7)
		ft_draw_seven(d, num, off, but);
	if (num == 8)
		ft_draw_eight(d, num, off, but);
	if (num == 9)
		ft_draw_nine(d, num, off, but);
}
