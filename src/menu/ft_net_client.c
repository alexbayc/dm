#include "engine.h"

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */

void	ft_allocation_client(t_engine *e)
{

	/* a new version for transmittion big data */

	e->dat_anot = NULL;
	e->dat_my = NULL;
	e->dat_tmp = NULL;

	e->dat_anot = (char *)ft_strnew(sizeof(char) * S);
	e->dat_my = (char *)ft_strnew(sizeof(char) * S);
	e->dat_tmp = (char *)ft_strnew(sizeof(char) * S);
	if( !e->dat_tmp || !e->dat_my || !e->dat_anot)
		ft_return("error: malloc");

	/* an old version */
	e->data_my = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero((void *)e->data_my, sizeof(t_data) * 1);
	e->data_my[0].x = 111;
	e->data_my[0].y = 111;

	e->data_another = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero((void *)e->data_another, sizeof(t_data) * 1);

	e->data_tmp = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero((void *)e->data_tmp, sizeof(t_data) * 1);

	e->client_fl = 'C';
}

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */
void	ft_net_client(t_engine *e)
{
	e->port = 1234;
	if (SDLNet_ResolveHost(&(e->ip), e->host_name, e->port) < 0)
	{
		e->client_fl = 'N';
		e->net_err_fl = 'Y';
		ft_putendl("error: resolv_host");
		return ;
	}
	if (!(e->client = SDLNet_TCP_Open(&e->ip)))
	{
		e->client_fl = 'N';
		e->net_err_fl = 'Y';
		ft_putendl("error: tcp open");
		return ;
	}

	ft_putendl("client connect to server");
	// if (system("sh ./scripts/maps_dow.sh") == -1)
	// 	ft_return("error: clone");
	ft_allocation_client(e);
	// e->data_my = (t_data *)malloc(sizeof(t_data) * 1);
	// ft_bzero((void *)e->data_my, sizeof(t_data) * 1);
	// e->data_my[0].x = 111;
	// e->data_my[0].y = 111;

	// e->data_another = (t_data *)malloc(sizeof(t_data) * 1);
	// ft_bzero((void *)e->data_another, sizeof(t_data) * 1);

	// e->data_tmp = (t_data *)malloc(sizeof(t_data) * 1);
	// ft_bzero((void *)e->data_tmp, sizeof(t_data) * 1);

	// e->client_fl = 'C';
	e->choose_map = 'Y';
	ft_putendl("client start tcp session as client");
	ft_loop_net(e);
}
