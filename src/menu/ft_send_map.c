#include "engine.h"

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */

void	ft_send_map(t_engine *e)
{


	int	i;
	int j;

	i = 0;
	e->dat_my[0] = 'M';
	j = 1;
	printf("prepare maps to send\n");
	while (e->map[i] != '\0')
	{
		e->dat_my[j] = e->map[i];
		i++;
		j++;
	}
	e->dat_my[j] = '\0';
	printf("ready: prepare maps to send\n");
}

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */

void	ft_get_map_name(t_engine *e)
{
	int i;
	int	j;

	j = 0;
	i = 1;
	printf("get name from server\n");
	int len = ft_strlen(e->dat_tmp);
	e->map = (char *)ft_memalloc(len);
	while (e->dat_tmp[i] != '\0')
	{
		e->map[j] = e->dat_tmp[i];
		j++;
		i++;
	}
	e->map[j] = '\0';
	printf("ready: get name from server\n");
}