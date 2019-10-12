#include "doom.h"

void	ft_trash(t_doom *d, t_button *b)
{
	d->x_s = b->x + d->width * 20 / 2500;
	d->y_s = b->y + d->height * 20 / 1300;
	d->x_e = b->x + d->width * 80 / 2500;
	d->y_e = b->y + d->height * 20 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_e = b->x + d->width * 30 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + d->width * 30 / 2500;
	d->y_s = b->y + d->height * 60 / 1300;
	d->x_e = b->x + d->width * 70 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + d->width * 80 / 2500;
	d->y_s = b->y + d->height * 20 / 1300;
	d->x_e = b->x + d->width * 70 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
}

static void	ft_save_d(t_doom *d, t_button *b)
{
	d->x_s = b->x + d->width * 80 / 2500;
	d->y_s = b->y + d->height * 35 / 1300;
	d->x_e = b->x + d->width * 60 / 2500;
	d->y_e = b->y + d->height * 20 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + d->width * 30 / 2500;
	d->y_s = b->y + d->height * 60 / 1300;
	d->x_e = b->x + d->width * 30 / 2500;
	d->y_e = b->y + d->height * 40 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + d->width * 30 / 2500;
	d->y_s = b->y + d->height * 40 / 1300;
	d->x_e = b->x + d->width * 70 / 2500;
	d->y_e = b->y + d->height * 40 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + d->width * 70 / 2500;
	d->y_s = b->y + d->height * 40 / 1300;
	d->x_e = b->x + d->width * 70 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
}

void	ft_save(t_doom *d, t_button *b)
{
	d->x_s = b->x + d->width * 20 / 2500;
	d->y_s = b->y + d->height * 20 / 1300;
	d->x_e = b->x + d->width * 60 / 2500;
	d->y_e = b->y + d->height * 20 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_e = b->x + d->width * 20 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + d->width * 20 / 2500;
	d->y_s = b->y + d->height * 60 / 1300;
	d->x_e = b->x + d->width * 80 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + d->width * 80 / 2500;
	d->y_s = b->y + d->height * 60 / 1300;
	d->x_e = b->x + d->width * 80 / 2500;
	d->y_e = b->y + d->height * 35 / 1300;
	ft_brasenham(d, 'M', b->color);
	ft_save_d(d, b);
}

void	ft_ctrz(t_doom *d, t_button *b)
{
	d->x_s = b->x + d->width * 20 / 2500;
	d->y_s = b->y + d->height * 10 / 1300;
	d->x_e = b->x + d->width * 80 / 2500;
	d->y_e = b->y + d->height * 10 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = d->x_e;
	d->y_s = d->y_e;
	d->x_e = b->x + d->width * 20 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
	d->x_s = d->x_e;
	d->y_s = d->y_e;
	d->x_e = b->x + d->width * 80 / 2500;
	d->y_e = b->y + d->height * 60 / 1300;
	ft_brasenham(d, 'M', b->color);
}

void	ft_left(t_doom *d, t_button *b)
{
	d->x_s = b->x + (b->x_len * 20 / 100);
	d->y_s = b->y + (b->y_len * 20 / 40);
	d->x_e = b->x + (b->x_len * 80 / 100);
	d->y_e = b->y + (b->y_len * 20 / 40);
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + (b->x_len * 20 / 100);
	d->y_s = b->y + (b->y_len * 20 / 40);
	d->x_e = b->x + (b->x_len * 40 / 100);
	d->y_e = b->y + (b->y_len * 5 / 40);
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + (b->x_len * 20 / 100);
	d->y_s = b->y + (b->y_len * 20 / 40);
	d->x_e = b->x + (b->x_len * 40 / 100);
	d->y_e = b->y + (b->y_len * 35 / 40);
	ft_brasenham(d, 'M', b->color);
}

void	ft_right(t_doom *d, t_button *b)
{
	d->x_s = b->x + (b->x_len * 20 / 100);
	d->y_s = b->y + (b->y_len * 20 / 40);
	d->x_e = b->x + (b->x_len * 80 / 100);
	d->y_e = b->y + (b->y_len * 20 / 40);
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + (b->x_len * 80 / 100);
	d->y_s = b->y + (b->y_len * 20 / 40);
	d->x_e = b->x + (b->x_len * 60 / 100);
	d->y_e = b->y + (b->y_len * 5 / 40);
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + (b->x_len * 80 / 100);
	d->y_s = b->y + (b->y_len * 20 / 40);
	d->x_e = b->x + (b->x_len * 60 / 100);
	d->y_e = b->y + (b->y_len * 35 / 40);
	ft_brasenham(d, 'M', b->color);
}

void	ft_save_main(t_doom *d)
{
	ft_init_but(&(d->but[1]), d->width * 100 / 2500, d->height * 80 / 1300,
		d->img.net.width + d->width * 10 / 2500);
	ft_init_but_2(&(d->but[1]), d->height * 1200 / 1300, 0x34D800FF);
	ft_button(d, &(d->but[1]));
	ft_save(d, &d->but[1]);
}

void	ft_trash_main(t_doom *d)
{
	ft_init_but(&(d->but[0]), d->width * 100 / 2500, d->height * 80 / 1300,
		d->img.net.width + d->width * 580 / 2500);
	ft_init_but_2(&(d->but[0]), d->height * 1200 / 1300, 0x34D800FF);
	ft_button(d, &(d->but[0]));
	ft_trash(d, &d->but[0]);
}

void	ft_ctrz_main(t_doom *d)
{
	ft_init_but(&(d->but[2]), d->width * 100 / 2500, d->height * 80 / 1300,
		d->img.net.width + d->width * 150 / 2500);
	ft_init_but_2(&(d->but[2]), d->height * 1200 / 1300, 0x34D800FF);
	ft_button(d, &(d->but[2]));
	ft_ctrz(d, &d->but[2]);
}

void	ft_textures_main(t_doom *d)
{
	ft_init_but(&(d->but[3]), d->img.menu.width - d->width * 65 / 2500, d->height * 200 / 1300, d->img.net.width + d->width * 65 / 2500 / 2);
	ft_init_but_2(&(d->but[3]), d->img.menu.height / 3 + d->height * 19 / 1300, 0x34D800FF);
	ft_button(d, &(d->but[3]));
	ft_put_textures_to_menu(d);
}

void	ft_textures_left_main(t_doom *d)
{
	ft_init_but(&(d->but[4]), d->width * 100 / 2500, d->height * 40 / 1300, d->img.net.width + d->width * 40 / 2500);
	ft_init_but_2(&(d->but[4]), d->img.menu.height / 4 + d->height * 60 / 1300, 0x34D800FF);
	ft_button(d, &(d->but[4]));
	ft_left(d, &d->but[4]);
}

void	ft_textures_right_main(t_doom *d)
{
	ft_init_but(&(d->but[5]), d->width * 100 / 2500, d->height * 40 / 1300, d->img.net.width + d->width * 560 / 2500);
	ft_init_but_2(&(d->but[5]), d->img.menu.height / 4 + d->height * 60 / 1300, 0x34D800FF);
	ft_button(d, &(d->but[5]));
	ft_right(d, &d->but[5]);
}
