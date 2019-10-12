#include "engine.h"

t_true_p	*ft_del_minus_points(t_engine *e)
{
	int			i;
	int			flag;
	t_true_p	*pon;
	double		angl;
	double		angl1;
	t_true_p	*head;

	angl = 0;
	flag = 0;
	i = 0;
	pon = NULL;
	int j;
	j = 0;
	/*  санитайз чекает ошибку инвалид рид сайз 1!!!!*/
	while (i <= e->sectors[e->draw_in.sector].npoints)
	{
		// if (i > 0)
			ft_add_node_head_prev(&pon, e->vert_new[i], e->sectors[e->draw_in.sector].neighbors[i]);
		// else
			// ft_add_node_head_prev(&pon,e->vert_new[i], e->sectors[e->draw_in.sector].neighbors[e->sectors[e->draw_in.sector].npoints - 1]);
		i++;
	}
	return(pon);
}

void	ft_back_to_screen(t_engine *e, t_true_p	**l)
{
	t_true_p	*tmp;

	tmp = *l;
	while(tmp)
	{
		ft_trans(&tmp->t.x, &tmp->t.y, &e->center);
		tmp = tmp->next;
	}
	ft_transfer_img_to_null(e, l);
}

void	ft_true_p(t_engine *e)
{
	// printf("try to draw sector %d\n", e->draw_in.sector);
	t_true_p	*l;
	t_co_trans	o;

	l = NULL;
	ft_fill_o(e, &o);
	ft_parallel_transfer(e, &o);
	l = ft_del_minus_points(e);
	ft_free((void **)(&e->vert_new));
	ft_back_to_screen(e, &l);
}