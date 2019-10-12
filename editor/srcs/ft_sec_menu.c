#include "doom.h"

void		ft_change_num(t_doom *d, int *n)
{
	char	*res;
	int		num;

	num = *n;
	res = ft_memalloc(sizeof(char) * (ft_strlen(SDL_GetKeyName(d->sdl.event.key.keysym.sym)) + 1));
	ft_strcpy(res, SDL_GetKeyName(d->sdl.event.key.keysym.sym));
	printf("%s\n", res);
	if (res[0] >= '0' && res[0] <= '9')
	{
		if (num < 100)
			num = num * 10 + res[0] - '0';
	}
	else if (ft_strcmp(res, "Backspace\0") == 0)
		num /= 10;
	*n = num;
	free(res);
}

static void	ft_put_tex_to_but(t_doom *d, t_button *but, SDL_Surface *tex)
{
	int		x;
	int		y;

	y = 0;
	while (++y < but->y_len)
	{
		x = 0;
		while (++x < but->x_len)
			ft_surface_set_pixel(d->sdl.sur_ptr, x + but->x, y + but->y,
				ft_surface_get_pixel(tex, x * tex->w / but->x_len, y * tex->h / but->y_len));
	}
}

static void	ft_init_ceil_but(t_doom *d, t_sector_lst *sec)
{
	ft_init_but(&d->smenu.ce_num, d->width * 120 / 2500, d->height * 40 / 1300, d->smenu.border.x + d->width * 20 / 2500);
	ft_init_but_2(&d->smenu.ce_num, d->smenu.border.y + d->height * 60 / 1300, 0x34D800FF);
	ft_button(d, &d->smenu.ce_num);
	ft_init_but(&d->smenu.ce_left, d->width * 40 / 2500, d->height * 40 / 1300, d->smenu.ce_num.x + d->smenu.ce_num.x_len + d->width * 60 / 2500);
	ft_init_but_2(&d->smenu.ce_left, d->smenu.ce_num.y, 0x34D800FF);
	ft_button(d, &d->smenu.ce_left);
	ft_left(d, &d->smenu.ce_left);
	ft_init_but(&d->smenu.ce_tex, d->width * 40 / 2500, d->height * 40 / 1300, d->smenu.ce_left.x + d->smenu.ce_left.x_len + d->width * 20 / 2500);
	ft_init_but_2(&d->smenu.ce_tex, d->smenu.ce_left.y, 0x34D800FF);
	ft_button(d, &d->smenu.ce_tex);
	ft_put_tex_to_but(d, &d->smenu.ce_tex, d->textures[sec->ceil_tex]);
	ft_init_but(&d->smenu.ce_right, d->width * 40 / 2500, d->height * 40 / 1300, d->smenu.ce_tex.x + d->smenu.ce_tex.x_len + d->width * 20 / 2500);
	ft_init_but_2(&d->smenu.ce_right, d->smenu.ce_tex.y, 0x34D800FF);
	ft_button(d, &d->smenu.ce_right);
	ft_right(d, &d->smenu.ce_right);
}

static void	ft_init_floor_but(t_doom *d, t_sector_lst *sec)
{
	ft_init_but(&d->smenu.fl_num, d->width * 120 / 2500, d->height * 40 / 1300, d->smenu.border.x + d->width * 20 / 2500);
	ft_init_but_2(&d->smenu.fl_num, d->smenu.ce_num.y + d->smenu.ce_num.y_len + d->height * 60 / 1300, 0x34D800FF);
	ft_button(d, &d->smenu.fl_num);
	ft_init_but(&d->smenu.fl_left, d->width * 40 / 2500, d->height * 40 / 1300, d->smenu.fl_num.x + d->smenu.fl_num.x_len + d->width * 60 / 2500);
	ft_init_but_2(&d->smenu.fl_left, d->smenu.fl_num.y, 0x34D800FF);
	ft_button(d, &d->smenu.fl_left);
	ft_left(d, &d->smenu.fl_left);
	ft_init_but(&d->smenu.fl_tex, d->width * 40 / 2500, d->height * 40 / 1300, d->smenu.fl_left.x + d->smenu.fl_left.x_len + d->width * 20 / 2500);
	ft_init_but_2(&d->smenu.fl_tex, d->smenu.fl_left.y, 0x34D800FF);
	ft_button(d, &d->smenu.fl_tex);
	ft_put_tex_to_but(d, &d->smenu.fl_tex, d->textures[sec->floor_tex]);
	ft_init_but(&d->smenu.fl_right, d->width * 40 / 2500, d->height * 40 / 1300, d->smenu.fl_tex.x + d->smenu.fl_tex.x_len + d->width * 20 / 2500);
	ft_init_but_2(&d->smenu.fl_right, d->smenu.fl_tex.y, 0x34D800FF);
	ft_button(d, &d->smenu.fl_right);
	ft_right(d, &d->smenu.fl_right);
}

static void	ft_init_x_but(t_doom *d)
{
	t_button	*b;
	ft_init_but(&d->smenu.ok, d->width * 20 / 2500, d->height * 20 / 1300, d->smenu.border.x + d->smenu.border.x_len - d->width * 10 / 2500 - d->smenu.ok.x_len);
	ft_init_but_2(&d->smenu.ok, d->smenu.border.y + d->height * 10 / 1300, 0x34D800FF);
	ft_button(d, &d->smenu.ok);
	b = &d->smenu.ok;
	d->x_s = b->x + 1;
	d->y_s = b->y + 1;
	d->x_e = b->x + b->x_len - 1;
	d->y_e = b->y + b->y_len - 1;
	ft_brasenham(d, 'M', b->color);
	d->x_s = b->x + 1;
	d->y_s = b->y + b->y_len - 1;
	d->x_e = b->x + b->x_len - 1;
	d->y_e = b->y + 1;
	ft_brasenham(d, 'M', b->color);
}

void		ft_put_nbr_to_but(t_doom *d, int num, t_button *but)
{
	int		offset;
	int		offset_num;

	offset_num = (but->x_len - but->x_len * 20 * 3 / 120) / 4;
	offset = offset_num;
	ft_draw_nbr(d, num / 100 % 10, offset, but);
	offset += but->x_len * 20 / 120 + offset_num;
	ft_draw_nbr(d, num / 10 % 10, offset, but);
	offset += but->x_len * 20 / 120 + offset_num;
	ft_draw_nbr(d, num % 10, offset, but);
}

void		ft_init_menu(t_doom *d, t_sector_lst *sec)
{
	ft_init_but(&d->smenu.border, d->but[3].x_len, d->height * 500 / 1300, d->but[3].x);
	ft_init_but_2(&d->smenu.border, d->but[3].y + d->but[3].y_len + d->height * 25 / 1300, 0x34D800FF);
	ft_button(d, &d->smenu.border);
	ft_init_ceil_but(d, sec);
	ft_init_floor_but(d, sec);
	ft_init_x_but(d);
	ft_put_nbr_to_but(d, sec->floor, &d->smenu.fl_num);
	ft_put_nbr_to_but(d, sec->ceiling, &d->smenu.ce_num);
}
