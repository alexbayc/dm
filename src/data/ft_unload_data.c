#include "engine.h"

void	ft_unload_data(t_engine *engine)
{
	for (unsigned a = 0; a < engine->num_sectors; ++a)
		free(engine->sectors[a].vertex);
	for (unsigned a = 0; a < engine->num_sectors; ++a)
		free(engine->sectors[a].neighbors);
	free(engine->sectors);
	engine->sectors = NULL;
	engine->num_sectors = 0;
}
