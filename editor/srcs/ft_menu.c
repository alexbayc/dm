#include "doom.h"

void	ft_redraw(t_doom *d)
{
	t_button	but;

	ft_init_borders(d);
	ft_clear_surface(d);
	ft_net(d);
	ft_draw_lst(d);
	ft_draw_player(d);
	ft_menu(d);
	ft_draw_cursor_tex(d, d->frame_size * 10);
	ft_draw_last_line(d);
	ft_init_but(&but, d->width * 120 / 2500, d->height * 40 / 1300, d->smenu.border.x + d->width * 20 / 2500);
	ft_init_but_2(&but, d->smenu.ce_num.y + d->smenu.ce_num.y_len + d->height * 100 / 1300, 0x34D800FF);
	ft_button(d, &but);
	ft_put_nbr_to_but(d, abs((int)d->player->angle % 360), &but);
}

void	ft_bort(t_doom *d)
{
	int x;
	int y;

	y = 0;
	while (y <= d->img.menu.height)
	{
		x = 0;
		while (x <= d->img.menu.width)
		{
			if (y == 0 || y == (d->img.menu.height - 1))
				ft_surface_set_pixel(d->sdl.sur_ptr, x + d->img.net.width, y, d->color.menu_border);
			if (x == 0 || x == (d->img.menu.width - 1))
				ft_surface_set_pixel(d->sdl.sur_ptr, x + d->img.net.width, y, d->color.menu_border);
			x++;
		}
		y++;
	}
}

int			ft_is_but_area(t_button but, int x, int y)
{
	if (x > but.x && x < but.x + but.x_len
			&& y > but.y && y < but.y + but.y_len)
		return (1);
	return (0);
}

static void	ft_clear_menu(t_doom *d)
{
	int		x;
	int		y;

	y = -1;
	while (++y < d->height)
	{
		x = d->width - d->img.menu.width - 1;
		while (++x < d->width)
			ft_surface_set_pixel(d->sdl.sur_ptr, x, y, 0x000000);
	}
}

void	ft_menu(t_doom *d)
{
	t_button but;

	ft_clear_menu(d);
	ft_bort(d);
	ft_trash_main(d);
	ft_save_main(d);
	ft_ctrz_main(d);
	ft_textures_left_main(d);
	ft_textures_right_main(d);
	ft_textures_main(d);
	ft_init_but(&but, d->width * 120 / 2500, d->height * 40 / 1300, d->smenu.border.x + d->width * 20 / 2500);
	ft_init_but_2(&but, d->smenu.ce_num.y + d->smenu.ce_num.y_len + d->height * 100 / 1300, 0x34D800FF);
	ft_button(d, &but);
	ft_put_nbr_to_but(d, abs((int)d->player->angle % 360), &but);
}

