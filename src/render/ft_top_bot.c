#include "engine.h"

void	ft_top_bot(t_engine *e, double *ray)
{
	ft_draw_floor(e, ray);
	ft_draw_ceil(e, ray);
}