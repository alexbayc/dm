#include "engine.h"

void	ft_free_sectors(t_engine *e)
{
	int i;

	i = 0;
	printf("free sect\n");
	while (i < e->num_sectors)
	{
		ft_memdel((void **)&e->sectors[i].vertex);
		ft_memdel((void**)&e->sectors[i].neighbors);
		ft_memdel((void**)&e->sectors[i].texturs);
		i++;
	}
	ft_memdel((void **)&e->sectors);
}

void	ft_free_shotguns(t_engine *e)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(e->shotgun[i]->img);
		free(e->shotgun[i]);
		e->shotgun[i] = NULL;
		i++;
	}
}

void	ft_free_wall(t_engine *e)
{
	ft_memdel((void **)&e->wall_text->img);
	ft_memdel((void **)&e->wall_text[0]);

	/*free iteams */
	ft_memdel((void **)&e->aid->img);
	ft_memdel((void **)&e->aid[0]);
}

void	ft_free_all_in_engine(t_engine *e)
{

	printf("free bot\n");
	ft_memdel((void **)&e->bot);
	printf("free top\n");
	ft_memdel((void **)&e->top);
	ft_memdel((void **)&e->mobs);
	ft_free_sectors(e);
	ft_free_shotguns(e);
	ft_free_wall(e);
	if (e->mus.gmusic)
		Mix_FreeMusic(e->mus.gmusic);
	e->mus.gmusic = NULL;
	e->mouse_iter = 0;
}
