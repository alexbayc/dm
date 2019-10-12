#include "engine.h"

void	ft_init_start_posotion(t_engine *e)
{

	e->bot = (int *)ft_memalloc(sizeof(int) * W);
	e->top = (int *)ft_memalloc(sizeof(int) * W);
}