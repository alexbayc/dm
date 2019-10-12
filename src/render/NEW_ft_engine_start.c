#include "engine.h"

extern int huita;

void	ft_trans(double *x, double *y, t_co_trans *o)
{
	double	tmp_x;
	double	tmp_y;

	*x = *x - o->a;
	*y = *y - o->b;
	//поворот вокруг нового центра
	tmp_x = *x;
	tmp_y = *y;
	*x =  tmp_x * cos(o->angle) + tmp_y * sin(o->angle);
	*y = -tmp_x * sin(o->angle) + tmp_y * cos(o->angle);

}

void		ft_fill_o(t_engine *e, t_co_trans *o)
{
	o->a = e->player.where.x;
	o->b = e->player.where.y;
	//printf("here10\n");

	o->angle = ft_dig_to_rad(e->player.angle);
	//printf("here10.5\n");
	//(e->sectors[e->draw_in.sector].npoints + 1))
	//printf("size->%d\n", e->draw_in.sector);
	e->vert_new = (t_xy *)ft_memalloc(sizeof(t_xy) * (e->sectors[e->draw_in.sector].npoints + 1));
	//printf("here11\n");
	ft_memcpy(e->vert_new, e->sectors[e->draw_in.sector].vertex, sizeof(t_xy) * (e->sectors[e->draw_in.sector].npoints + 1));
	//printf("here12\n");
}

void		ft_parallel_transfer(t_engine *e, t_co_trans *o)
{
	int	i;
	double	tmp_x;
	double	tmp_y;

	i = 0;
	while (i <= e->sectors[e->draw_in.sector].npoints)
	{
		ft_trans(&e->vert_new[i].x, &e->vert_new[i].y, o);
		i++;
	}
	e->center.a = 0;
	e->center.b = 0;
	e->center.angle = ft_dig_to_rad((-1) * e->player.angle);
	ft_trans(&e->center.a, &e->center.b, o);

}

void	ft_engine_start(t_engine *e)
{

	ft_bzero(e->sdl.sur_ptr->pixels, sizeof(int) * e->sdl.sur_ptr->w * e->sdl.sur_ptr->h);
	ft_bzero((void *)&e->draw_in, sizeof(t_draw));
	e->player.sector = ft_which_sector(e, e->player.where.x, e->player.where.y);
	printf("pl coord (%f, %f, %f)\n", e->player.where.x, e->player.where.y, e->player.where.z);
	if (e->player.sector == -1)
	{

		printf("player out of sector\n");
		exit(-1);
	}
	printf("pl sec ->%d\n", e->player.sector);
	ft_fill_sectors_2(e);
	// exit(-1);


	e->draw_in.sector = e->player.sector;
	int kos = H;
	if (e->player.sector == -1)
		printf("player out of sector\n");
	e->draw_in.right = ft_dig_to_rad(FOV_D);
	e->draw_in.left = ft_dig_to_rad(-(FOV_D));
	e->draw_in.h = H;
	e->draw_in.w = W;
	e->draw_in.x_s = 0;
	e->draw_in.half = H / 2 + e->player.h_l;
	ft_set(e->bot, &kos, sizeof(int), sizeof(int) * (W));
	ft_bzero(e->top, sizeof(int) * (W));
	ft_bzero(e->visited, (sizeof(unsigned char) * 32));
	ft_bzero(e->to_visit, (sizeof(unsigned char) * 32));
	// printf("%d\n", e->player.h_l);
	ft_true_p(e);
	ft_blood_mask(e);
	// int i = -1;
	// while (++i < W)
	// {
	// 	printf("i->%d, top - bot = %d\n", i, e->top[i] - e->bot[i]);
	// }
	// exit (1);
}
