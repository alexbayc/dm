#include "engine.h"

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */

void	ft_allocation_server(t_engine *e)
{
	/* a new version for transmittion big data */

	e->dat_anot = (char *)ft_strnew(sizeof(char) * S);
	e->dat_my = (char *)ft_strnew(sizeof(char) * S);
	e->dat_tmp = (char *)ft_strnew(sizeof(char) * S);



	/* an old version */
	e->data_my = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero((void *)e->data_my, sizeof(t_data) * 1);
	e->data_my[0].x = 222;
	e->data_my[0].y = 222;

	e->data_tmp = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero((void *)e->data_tmp, sizeof(t_data) * 1);

	e->data_another = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero((void *)e->data_another, sizeof(t_data) * 1);


	e->host_fl = 'C';

}
/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */
int	ft_listening(t_engine *e)
{
	long int	time_st;

	time_st = time(NULL);
	ft_putendl("i am listening");
	while (1)
	{

		e->client = SDLNet_TCP_Accept(e->server);
		if (e->client)
		{
			ft_putendl("catch client");
			ft_allocation_server(e);
			// e->data_my = (t_data *)malloc(sizeof(t_data) * 1);
			// ft_bzero((void *)e->data_my, sizeof(t_data) * 1);
			// e->data_my[0].x = 222;
			// e->data_my[0].y = 222;

			// e->data_tmp = (t_data *)malloc(sizeof(t_data) * 1);
			// ft_bzero((void *)e->data_tmp, sizeof(t_data) * 1);

			// e->data_another = (t_data *)malloc(sizeof(t_data) * 1);
			// ft_bzero((void *)e->data_another, sizeof(t_data) * 1);
			// e->host_fl = 'C';
			ft_putendl("catch client2");
			return (1);
			break ;
		}
		if (time(NULL) - time_st >= 5 || e->host_fl != 'I')
		{
			ft_putendl("i am listening error");
			e->host_fl = 'N';
			e->net_err_fl = 'Y';
			return (-1);
		}
	}
}

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */
void	ft_net_server(t_engine *e)
{

	e->host_name = NULL;
	e->port = 1234;
	ft_putendl("here net server");
	if (SDLNet_ResolveHost(&(e->ip), e->host_name, e->port) < 0)
	{
		e->host_fl = 'N';
		e->net_err_fl = 'Y';
		ft_putendl("error: resolv_host");
		return ;
	}
	if (!(e->server = SDLNet_TCP_Open(&e->ip)))
	{
		e->host_fl = 'N';
		e->net_err_fl = 'Y';
		ft_putendl("error: error: tcp open");
		return ;
	}
	else
	{
		if (ft_listening(e) == -1)
			SDLNet_TCP_Close(e->server);
		else
		{
			ft_putendl("server connect with client");
			e->host_fl = 'C';
			ft_putendl("server start tcp session as server");
			e->choose_map = 'Y';

			// ft_choose_map(e);


			ft_loop_net(e);
		}
	}
}
