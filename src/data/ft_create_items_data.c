#include "engine.h"

void	ft_create_items_data(t_engine *e, char *gnl)
{
	e->mobs = NULL;
	e->nb_mobs = ft_atoi(&gnl[7]);
	if (e->host_fl || e->client_fl)
		e->nb_mobs++;
	printf("nb_mobs %d\n", e->nb_mobs);
	e->mobs = (t_mobs *)ft_memalloc(sizeof(t_mobs) * e->nb_mobs);
	if (!e->mobs)
		ft_return("error: malloc");

}

void	ft_fill_items_mass(t_engine *e, char *gnl)
{
	static int i;

	gnl += 6;

	if (i >= e->nb_mobs)
		return ;
	e->mobs[i].where.x = ft_scan_digit(&gnl);
	e->mobs[i].where.y = ft_scan_digit(&gnl);
	e->mobs[i].where.z = ft_scan_digit(&gnl);
	e->mobs[i].status = ft_scan_digit(&gnl);
	e->mobs[i].type = ft_scan_digit(&gnl);
	e->mobs[i].damage = ft_scan_digit(&gnl);
	e->mobs[i].height = ft_scan_digit(&gnl);
	e->mobs[i].angle = ft_scan_digit(&gnl);
	i++;
}


void	ft_put_another_pl(t_engine *e, char *gnl)
{
	t_player tmp;

	gnl += 7;
	e->mobs[e->nb_mobs - 1].where.x = ft_scan_digit(&gnl);
	e->mobs[e->nb_mobs - 1].where.y = ft_scan_digit(&gnl);
	e->mobs[e->nb_mobs - 1].angle = ft_scan_digit(&gnl);
	e->mobs[e->nb_mobs - 1].where.z = ft_scan_digit(&gnl);
	e->mobs[e->nb_mobs - 1].type = 4;
	e->mobs[e->nb_mobs - 1].damage = 0;
	e->mobs[e->nb_mobs - 1].status = 1;
	if (e->client_fl == 'C')
	{
		tmp.where.x = e->player.where.x;
		tmp.where.y = e->player.where.y;
		tmp.angle = e->player.angle;
		tmp.where.z = e->player.where.z;

		e->player.where.x = e->mobs[e->nb_mobs - 1].where.x;
		e->player.where.y = e->mobs[e->nb_mobs - 1].where.y;
		e->player.angle = e->mobs[e->nb_mobs - 1].angle;
		e->player.where.z = e->mobs[e->nb_mobs - 1].where.z;

		e->mobs[e->nb_mobs - 1].where.x = tmp.where.x;
		e->mobs[e->nb_mobs - 1].where.y = tmp.where.y;
		e->mobs[e->nb_mobs - 1].angle = tmp.angle;
	    e->mobs[e->nb_mobs - 1].where.z = tmp.where.z;
	}
}

void ft_print_mobs(t_engine *e)
{
	int i;
	i = 0;
	while (i < e->nb_mobs)
	{
		printf("line->%d,  place (%f, %f, %f), status->%d, type->%d, damage->%d, height->%d, angle->%f, sector->%d\n",
				i,  e->mobs[i].where.x,  e->mobs[i].where.y,  e->mobs[i].where.z,e->mobs[i].status,  e->mobs[i].type, e->mobs[i].damage, e->mobs[i].height, e->mobs[i].angle, e->mobs[i].sector);
		i++;
	}
}

void	ft_fill_sectors_2(t_engine *e)
{
	static int j;
	int i;
	i = 0;
	while (i < e->nb_mobs)
	{
		e->mobs[i].sector = ft_which_sector(e, e->mobs[i].where.x, e->mobs[i].where.y);
		if (e->mobs[i].sector == -1)
			ft_return("error: somebody is out of map");
		i++;
	}
	if (j == 0)
	{
        if (e->client_fl == 'C' || e->host_fl == 'C')
        {
            if (e->host_fl == 'C')
                e->mobs[e->nb_mobs - 1].where.z = e->sectors[e->mobs[e->nb_mobs - 1].sector].floor;
            else
            {
                e->player.where.z = e->sectors[ft_which_sector(e,e->player.where.x, e->player.where.y)].floor;
            }
        }
	}


	ft_print_mobs(e);
}



