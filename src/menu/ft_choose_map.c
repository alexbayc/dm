#include "engine.h"


void	ft_free_mass(char ***str)
{
	char	**tmp;
	int		i;

	tmp = *str;
	i = 0;
	while (tmp[i])
	{
		ft_memdel((void **)&tmp[i]);
		i++;
	}
	free(tmp);
	tmp = NULL;
}



void	ft_choose_map(t_engine *e)
{
	char	*str;
	int	i;
	int	fd;
	int	tmp;

	fd = 0;
	i = 0;
	// if (system("sh ./scripts/maps_dow.sh") == -1)
	// 	ft_return("error: clone");
	//временное условие тоже убрать потом
	if (system("sh ./scripts/show_maps.sh") == -1)
		ft_return("error: clone");

	fd = open("./scripts/rez_maps.txt", O_RDONLY);
	if (fd < 0)
		ft_return("error: open file");

	i = get_next_line(fd, &str);
	if (i == -1 || i == 0)
		ft_return("error: file");
	i = ft_atoi(str);
	e->nb_map = i;
	ft_memdel((void **)&str);
	e->maps = (char **)ft_memalloc(sizeof(char*) * (i + 1));
	if (!e->maps)
		ft_return("error: malloc");
	e->maps[i] = NULL;
	i = 0;
	while (get_next_line(fd, &str))
	{
		e->maps[i] = ft_strdup(str);
		if (!e->maps[i])
			ft_free_mass(&e->maps);
		tmp = ft_strlen(e->maps[i]);
		if (e->max_len_name_map < tmp)
			e->max_len_name_map = tmp;
		ft_memdel((void **)&str);
		i++;
	}
	i = 0;
	//printf("max len name %d\n",e->max_len_name_map );
	//printf("e->nb_map ->%d\n", e->nb_map);
	while (e->maps[i])
	{
		printf("file_name->%s\n", e->maps[i]);
		i++;
	}
	e->choose_map = 'W'; //W-waiting choose
}