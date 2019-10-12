#include "engine.h"

int		ft_filter_key(char *name_k)
{
	if (ft_strlen(name_k) > 1)
		return (-1);
	return (0);
}

void	ft_handle_key(t_engine *e)
{
	char	*name_k;
	char	*tmp;

	tmp = NULL;
	if (e->sdl.event.type == SDL_KEYDOWN)
	{
		if (e->host_name && ft_strlen(e->host_name) > 22)
			return ;
		if (!(name_k = (char *)SDL_GetKeyName(e->sdl.event.key.keysym.sym)))
			ft_return("error: malloc");
		if (ft_filter_key(name_k) == -1)
			return ;
		if (e->host_name)
			if (!(tmp = ft_strdup(e->host_name)))
				ft_return("error: malloc");
		if (e->host_name)
			ft_memdel((void **)&e->host_name);
		if (!(e->host_name = ft_strjoin(tmp, name_k)))
			ft_return("error: malloc");
		ft_memdel((void **)&tmp);
		ft_draw_ask_about_host(e);
	}
}

void	ft_back_space(t_engine *e)
{
	char	*tmp;

	if (!e->host_name || e->host_name[0] == '\0')
		return ;
	tmp = (char *)ft_memalloc(sizeof(char) * ft_strlen(e->host_name));
	if (!tmp)
		ft_return("error: malloc");
	ft_strncpy(tmp, e->host_name, ft_strlen(e->host_name) - 1);
	ft_memdel((void **)&e->host_name);
	e->host_name = tmp;
	ft_draw_ask_about_host(e);
}

void	ft_ready_host_name(t_engine *e)
{
	e->client_fl = 'R';
}
