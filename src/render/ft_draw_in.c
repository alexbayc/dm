#include "engine.h"

int		huita = 0;

int	ft_new_w(t_engine *e, uint32_t sec, int **walls)
{
	t_ijk	ijk;
	int		len;


	len = 0;
	ijk.k = 0;
	ijk.i = e->draw_in.x_s;

	while (ijk.k < e->draw_in.w)
	{
		if (e->top[ijk.i] < e->bot[ijk.i] && (uint32_t)(*walls)[ijk.k] == sec)
		{
			if (len == 0)
			{
				e->draw_in.x_s = ijk.i;
				e->draw_in.y_s = e->bot[ijk.i];
			}
			len++;
		}
		ijk.i++;
		ijk.k++;
	}
	if (e->draw_in.sector == 1)
	{
		printf("old len->%d , old x_s->%d\n", len, e->draw_in.x_s);
		exit (1);
	}
	return (len);
}

int	ft_newnew_w(t_engine *e, uint32_t sec, int **walls)
{
	t_ijk	ijk;
	int		len;
	int		lim;


	len = 0;
	ijk.k = 0;
	ijk.i = W * 2 * ((ft_rad_to_dig(e->draw_in.left) + FOV_D) / (2 * FOV_D)) / 2/** 2 / 3*/;
	e->draw_in.x_s = ijk.i;
	e->draw_in.w = W * (ft_rad_to_dig(e->draw_in.right - e->draw_in.left) / (2 * FOV_D)) + 1;
	if (e->draw_in.w < 0)
	{
		e->draw_in.x_s = 0;
		e->draw_in.w = 0;
	}
	else if (e->draw_in.x_s + e->draw_in.w > W)
		e->draw_in.w -= e->draw_in.x_s + e->draw_in.w - W;
	// printf("lim->%d, dig->%f, right->%f, left->%f\n", e->draw_in.w, ft_rad_to_dig(e->draw_in.right - e->draw_in.left), ft_rad_to_dig(e->draw_in.right), ft_rad_to_dig(e->draw_in.left));
	// e->draw_in.w = W * ((ft_rad_to_dig(e->draw_in.right) + FOV_D) / (2 * FOV_D)) + 1  - e->draw_in.x_s;

	// if (e->draw_in.sector == 1)
	// 	printf("%d %d %d\n", ijk.i, e->top[ijk.i + 1], e->bot[ijk.i + 1]);
	//printf("new len->%d , new x_s->%d\n", e->draw_in.w, e->draw_in.x_s);
	return (e->draw_in.w);
}

void	ft_draw_in(t_engine *e, t_true_p **l, int **walls)
{
	t_true_p *tmp;
	int i = 0;
	int w = 0;
	int flag = 0;
	tmp = *l;
	double temp;
	t_draw	sec;

	sec = *(t_draw *)ft_memcpy(&sec, &e->draw_in, sizeof(t_draw));
	// printf("sector %d, left->%f, right->%f, w->%d\n", sec.sector, ft_rad_to_dig(sec.left), ft_rad_to_dig(sec.right), sec.w);
	e->visited[e->draw_in.sector >> 3] |= (1 << (e->draw_in.sector & 7));
	while (tmp->next)
	{
		flag = 0;
		if (tmp->next->after_w >= 0 && !(e->visited[tmp->next->after_w >> 3] & (1 << (tmp->next->after_w & 7))) &&
					e->to_visit[tmp->next->after_w >> 3] & (1 << (tmp->next->after_w & 7)))
		{
			huita++;
			//iz-za osey delayem asin
			// e->draw_in.half =
			e->draw_in.sector = (int)tmp->next->after_w;
			temp = asin(tmp->t.x / sqrt(pow(tmp->t.x, 2)
			 					+ pow(tmp->t.y, 2)));
			if (tmp->t.y > 0)
			{
				flag++;
				temp = acos(-1) - temp;
			}
			e->draw_in.right = temp > e->draw_in.right ? e->draw_in.right : temp;
			temp = asin(tmp->next->t.x / sqrt(pow(tmp->next->t.x, 2)
								+ pow(tmp->next->t.y, 2)));
			if (tmp->next->t.y > 0)
			{
				temp = -acos(-1) - temp;
				flag++;
			}
			e->draw_in.left = temp < e->draw_in.left ? e->draw_in.left : temp;
			e->draw_in.w = ft_newnew_w(e, e->draw_in.sector, walls);
			// e->draw_in.w = ft_new_w(e, e->draw_in.sector, walls);
			if (flag != 2)
			{
				ft_true_p(e);

			}
			printf("sec rec -> %d I try find  u-turn of recursion\n", e->draw_in.sector);
		}
		i++;
		e->draw_in = *(t_draw *)ft_memcpy(&e->draw_in, &sec, sizeof(t_draw));
		tmp = tmp->next;

	}
	//по моей идеи, мы должны отрисовать мобов и предметы на сворачивании рекурсии
	//пока не получается
	//
	e->visited[sec.sector >> 3] &= ~(1 << (sec.sector & 7));


	// printf("sector %d, left->%f, right->%f, w->%d\n", sec.sector, ft_rad_to_dig(sec.left), ft_rad_to_dig(sec.right), sec.w);
	// printf("finished draw_in in sector %d\n", sec.sector);
}
