#include "engine.h"

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */
int	ft_compare2(char **tmp, char **client)
{
	/* experemtation*/
	//ft_strcmp(*tmp, *client) != 0
	if (*tmp[0] != *client[0])
	{
		ft_memcpy(*client, *tmp, sizeof(char) * ft_strlen(*tmp));
		ft_bzero(*tmp, sizeof(char) * ft_strlen(*tmp));
		return(1);
	}
	else
	{
		ft_bzero(*tmp, sizeof(char) * ft_strlen(*tmp));
	}
	return (0);

}

int	ft_compare(t_data *tmp, t_data *client)
{
		
	if (tmp->x - client[0].x != 0 || tmp->y - client[0].y != 0)
	{
		ft_memcpy(&client[0], tmp, sizeof(t_data));
		ft_bzero(tmp, sizeof(t_data));
		return (1);
	}
	else
		ft_bzero(tmp, sizeof(t_data));
	return (0);
}

/* the same function for server and client */
void	ft_loop_net(t_engine *e)
{
	int	rez_recv;
	SDL_mutex *mutex;
	int how_much = 0;
	mutex = SDL_CreateMutex();
	int i = 0;
	
	ft_putendl("loop net");
	while (1)
	{
		if (e->host_fl == 'C' && e->map_choosen == 'Y')
		{
			SDL_LockMutex(mutex);
				e->dat_my[0] = 'M'; 
				ft_strcpy(&e->dat_my[1], e->map);
				// e->data_my[0].x = 444;
				// e->data_my[0].y = 444;
				e->choose_map = 'I';
				e->map_choosen = 'N';
			SDL_UnlockMutex(mutex);	
		}
		if (SDLNet_TCP_Send(e->client, e->dat_my, S) > 0)
		{
			ft_putendl("i sent");
		}
		rez_recv = SDLNet_TCP_Recv(e->client, e->dat_tmp, S);
		if (rez_recv > 0)
		{
			ft_putendl("recive cycle");
			SDL_LockMutex(mutex);
			// if (e->client_fl == 'C' && e->choose_map == 'W' && e->data_tmp[0].x == 444 && e->data_tmp[0].y == 444)
			// 	e->choose_map = 'I';
			if (e->client_fl == 'C' && e->choose_map == 'W' && e->dat_tmp[0] == 'M')
			{
				e->map = ft_strdup(&e->dat_tmp[1]);
				printf("i recive->%s\n", e->map);
				e->choose_map = 'I';
			}	
			// if (ft_compare(&e->data_tmp[0], &e->data_another[0]) == 1)
			// {
			// 	e->net_fl = 'T';
				
			// } //means Transmitte
			// else
			// 	e->net_fl = 'S'; //means Same

			// if (ft_compare2(&e->dat_tmp, &e->dat_anot) == 1)
			// {
			// 	e->net_fl = 'T';
				
			// } //means Transmitte
			// else
			// 	e->net_fl = 'S'; //means Same	
			SDL_UnlockMutex(mutex);
		}
		SDL_Delay(2000);
			
	}
	SDL_DestroyMutex(mutex);



/*again dont recive true message */

	// if (SDLNet_TCP_Send(e->client, &e->dat_my, 50) > 0)
	// 		{
	// 			printf("i sent:->%s\n",e->dat_my);
	// 			ft_bzero(e->dat_my, sizeof(char)* ft_strlen(e->dat_my));
	// 			printf("i sent\n");
	// 		}
	// 		rez_recv = SDLNet_TCP_Recv(e->client, &e->dat_tmp, 50);
	// 		if (rez_recv > 0)
	// 		{
	// 			printf("i recive\n");
	// 			SDL_LockMutex(mutex);
	// 			if (ft_compare(&e->dat_tmp, &e->dat_anot) == 1)
	// 				e->net_fl = 'T'; //means Transmitte
	// 			else
	// 				e->net_fl = 'S'; //means Same
	// 			printf("i recive:->%s\n", e->dat_anot);	
	// 			SDL_UnlockMutex(mutex);
	// 		}
	// 		if( e->client_fl == 'C')
	// 			SDL_Delay(100);
	// 		else
	// 		{
	// 			SDL_Delay(2000);
	// 		}

/*again dont recive true message */




/*пустое сообщение всега что за фигня */
		// printf("map choosen->%c\n", e->map_choosen);
		// printf("e->choose_map->%c\n", e->choose_map);
		// if (e->map_choosen == 'Y' && e->host_fl == 'C')
		// {
		// 	printf("try send\n");
		// 	ft_send_map(e);
		// 	int len = ft_strlen(e->dat_my);
		// 	printf("len of message %d\n", len);
		// 	printf("server->MAP_is ->%s\n", e->dat_my);
		// 	how_much = SDLNet_TCP_Send(e->client, (void*)&e->dat_my, 20);
		// 	printf("how_much i sent->%d\n", how_much);
		// 	if (how_much > 0)
		// 	{	
		// 		e->choose_map = 'I';
		// 		e->map_choosen = 'I';
		// 	}
		// }
		// if (e->choose_map == 'I')
		// {
		// 	ft_bzero(e->dat_my, 20);
		// 	e->dat_my[0] = i;
		// 	e->dat_my[1] = i + 2;
		// 	if (i == 2147483646)
		// 		i = 0;
		// 	i++;	
		// 	how_much = SDLNet_TCP_Send(e->client, (void*)&e->dat_my, 20);
		// 	if ( how_much > 0)
		// 	{
		// 		ft_putendl("i sent");
		// 		printf("sent_rez->%s\n",e->dat_my);
		// 	}
		// 	ft_bzero(e->dat_tmp, 20);
		// 	rez_recv = SDLNet_TCP_Recv(e->client, &e->dat_tmp, 20);
		// 	if  (rez_recv > 0)
		// 	{
		// 		ft_putendl("recive cycle");
		// 		printf("rec_rez->%s\n", e->dat_tmp);

		// 	}
/*пустое сообщение всега что за фигня */
				
		// }
		// if(e->choose_map == 'W' && e->client_fl == 'C')
		// {
		// 	printf("try recive\n");
		// 	rez_recv = SDLNet_TCP_Recv(e->client, (void*)&e->dat_tmp, 20);
			
		// 	printf("i recive->%d\n", rez_recv);
		// 	printf("what i recive->%s\n",e->dat_tmp);
		// 	if (rez_recv > 0 && e->dat_tmp[0] == 'M')
		// 	{
		// 		e->dat_tmp[20] = '\0';
		// 		ft_get_map_name(e);
		// 		printf("get name->%s\n", e->map);
		// 		e->choose_map = 'I';
		// 		e->map_choosen = 'I';
		// 	}
			
		// }








		// if (e->map_choosen == 'Y')
		// {
		// 	printf("try send\n");
		// 	ft_send_map(e);
		// 	int len = ft_strlen(e->dat_my);
		// 	SDL_LockMutex(mutex);
		// 	int how_much = SDLNet_TCP_Send(e->client, &e->dat_my, len + 1);
		// 	if (how_much > 0)
		// 	{
		// 		e->choose_map = 'I';
		// 		ft_putendl("i sent map");
		// 		printf("server->MAP_is ->%s\n", e->dat_my);
		// 		printf("how_much i sent->%d\n", how_much);
		// 	}
		// 	SDL_UnlockMutex(mutex);

		// }
		// // else
		// // 	if (SDLNet_TCP_Send(e->client, &e->data_my[0], 8) > 0)
		// // 		ft_putendl("i sent");

		// rez_recv = SDLNet_TCP_Recv(e->client, &e->dat_tmp, 1400);
		// if (rez_recv > 0)
		// {
		// 	ft_putendl("recive cycle");
		// 	SDL_LockMutex(mutex);
			
		// 	if (e->client_fl == 'C' && e->choose_map == 'W')
		// 	{
		// 		if (e->dat_tmp[0] == 'M')
		// 		{
		// 			printf("what i am get as clint->%s\n", e->dat_tmp);
		// 			ft_get_map_name(e);
		// 			e->choose_map = 'I';
		// 			printf("clien->MAP_is ->%s\n", e->map);
		// 		}
		// 	}

		// 	// if (ft_compare(&e->data_tmp[0], &e->data_another[0]) == 1)
		// 	// 	e->net_fl = 'T'; //means Transmitte
		// 	// else
		// 	// 	e->net_fl = 'S'; //means Same
		// 	SDL_UnlockMutex(mutex);

		// 
	//если дошел сюда то надо сделать такой флаг, чтобы выкидывал в меню

}

/** net thread
*** net thread
*** net thread
*** net thread
*** net thread */
int		ft_connect(void *data)
{
	t_engine	*e;

	e = (t_engine *)data;
	while (1)
	{
		ft_putendl("i am in the second thread");
		if (e->host_fl == 'I')
			ft_net_server(e);
		else if (e->client_fl == 'R')  //means ready
			ft_net_client(e);
		// else if (e->menu_fl == 'G')
		// 	return (0);// раньше закрывала, когда в одиночной игре играли
		SDL_Delay(400);
	}
	return (0);
}
