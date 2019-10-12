#include "engine.h"

int		ft_clr_pxl(float pctx, float pcty, int t, t_engine *e)
{
	int x;
	int y;

	x = (int)((float)e->wall_text->w / 100 * pctx);
	y = (int)((float)e->wall_text->h / 100 * pcty);
	if (x < 0)
		x = 0;
	if (y < 0)
		y = 0;
	return (e->wall_text[t].img[x + (e->wall_text[t].h - 1 - y) * e->wall_text[t].w]);

}

void	ft_draw_ray(t_engine *e, t_true_p **l, double *ray, int *walls, float *pctx)
{
	int	half;
	int	lim;
	t_ijk	ijk;
	int	flag = 0;
	int	start = -1;

	float pcty;
	int		clr;

	ijk.j = 0;
	half = H / 2 + e->player.h_l;
	ijk.i = e->draw_in.x_s;
	ijk.k = 0;
	SDL_LockSurface(e->sdl.sur_ptr);
	ft_top_bot(e, ray);

	while (ijk.k < e->draw_in.w)
	{
		ijk.j = half - ray[ijk.k] / 2;
		lim = (half + ray[ijk.k] / 2);
		if ((int)walls[ijk.k] < 0)
		{
			ijk.j = ijk.j < e->top[ijk.i] ? e->top[ijk.i] : ijk.j;
			lim = lim > e->bot[ijk.i] ? e->bot[ijk.i] : lim;
			while (ijk.j < lim)
			{
				/*textures */
				//pcty = ((ijk.j - (half - ray[ijk.k] / 2)) / (((half + ray[ijk.k] / 2) - (half - ray[ijk.k] / 2)) / 100));
				//clr = ft_clr_pxl(pctx[ijk.k], pcty, 0, e);
				// ft_surface_set_pixel(e->sdl.sur_ptr, ijk.i, ijk.j, clr);
				/*textures */

				ft_surface_set_pixel(e->sdl.sur_ptr, ijk.i, ijk.j, 0x111122 << (e->draw_in.sector * 10));

				(e->top[ijk.i])++;
				ijk.j++;
			}
		}
		else if ((int)walls[ijk.k] >= 0)
		{
			if (start == -1)
				start = ijk.i;
			ft_draw_portal_wall(e, ray, walls, ijk);
			flag++;
		}
		ijk.k++;
		ijk.i++;
	}
	ft_draw_in(e, l, &walls);
	SDL_UnlockSurface(e->sdl.sur_ptr);
}

float		ft_textur(t_xy a, t_xy b)
{
	float	ab;
	float	res;

	ab = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
	res = (ab - (int)ab) * 100;
	return (res);
}

void	ft_try_ray(t_engine *e, t_true_p **l)
{
	double	*ray;
	int		*walls;
	float	*percent;
	double temp;
	t_t_ray	st;
	t_true_p *tmp;
	t_xy	*a;
	t_xy	o;

	st.i = 0;
	tmp = *l;

	ray = (double *)ft_memalloc(sizeof(double) * (e->draw_in.w));
	walls = (int *)ft_memalloc(sizeof(int) * (e->draw_in.w));
	percent = (float *)ft_memalloc(sizeof(int) * (e->draw_in.w));
	if (!ray || !walls)
		ft_return("error: malloc");
	st.d_a = ft_rad_to_dig(-e->draw_in.left + e->draw_in.right) / e->draw_in.w;
	while (st.i < e->draw_in.w)
	{
		tmp = *l;
		while (tmp->next)
		{
			if (tmp->next->after_w == -1 || !(e->visited[tmp->next->after_w >> 3] & (1 << (tmp->next->after_w & 7))))
			{
				o.x = cos(ft_dig_to_rad(ft_rad_to_dig(e->draw_in.left) + st.i * st.d_a));
				o.y = -sin(ft_dig_to_rad(ft_rad_to_dig(e->draw_in.left) + st.i * st.d_a));
				a = ft_cross_point(tmp->t, tmp->next->t, o);
				if (a != NULL && a->y <= 0)
				{
					/* ищу какой моб в это секторе */



					temp = (H * (e->sectors[e->draw_in.sector].ceil - e->sectors[e->draw_in.sector].floor) / 10 / (float)((sqrt(pow(a->x, 2) + pow(a->y, 2)))
						* cos(ft_dig_to_rad((ft_rad_to_dig(e->draw_in.left) + st.i * st.d_a)))));
					ray[st.i] = temp > ray[st.i] ? temp : ray[st.i];
					if (st.i == W / 2 - 2)
						ray[st.i] = ray[st.i - 1];
					if (ray[st.i] != ray[st.i])
						ray[st.i] = ray[st.i - 1];
					else if (st.i == 1)
						ray[0] = ray[1];
					else if (st.i == e->draw_in.w - 1)
						ray[st.i] = ray[st.i - 1];
					walls[st.i] = tmp->next->after_w;
					e->to_visit[walls[st.i] >> 3] |= 1 << (walls[st.i] & 7);
					percent[st.i] = ft_textur(tmp->t, *a);
				}
				ft_memdel((void **)&a);
			}
			tmp = tmp->next;
		}
		st.i++;
	}

	ft_draw_ray(e, l, ray, walls, percent);
	ft_free_lst(l);
	ft_free((void**)(&ray));
	ft_free((void **)(&walls));
	ft_free((void **) (&percent));
	//SDL_FreeSurface(e->sdl.img_ptr);
}
