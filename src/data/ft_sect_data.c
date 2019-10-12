#include "engine.h"

static int			ft_num_init(int **num, char **gnl,
	unsigned int *m, t_sector *sect)
{
	sect->floor = ft_scan_digit(gnl);
	sect->ceil = ft_scan_digit(gnl);
	while (**gnl)
	{
		if (!(num[0] = ft_realloc(num[0], ++(*m), sizeof(**num))))
		{
			if (num[0])
				free(num[0]);
			return (0);
		}
		num[0][*m - 1] = ft_scan_digit(gnl);
		while (**gnl == ' ' || **gnl == '\t')
			gnl[0]++;
	}
	return (1);
}

static int		ft_mnogo_if(t_engine *engine, int m, t_sector *sect, int *num)
{
	sect->npoints = m / 2;
	if (!(sect->neighbors = ft_memalloc(m / 2 * sizeof(*sect->neighbors))))
	{
		free(num);
		return (0);
	}
	if (!(sect->texturs = ft_memalloc(m / 2 * sizeof(int))))
	{
		free(num);
		free(sect->neighbors);
		return (0);
	}
	if (!(sect->vertex = ft_memalloc((m / 2 + 1) * sizeof(*sect->vertex))))
	{
		free(num);
		free(sect->neighbors);
		free(sect->texturs);
		return (0);
	}
	return (1);
}

int				ft_sect_data(t_engine *engine, t_xy *vert, char *gnl)
{
	t_sector				*sect;
	int						*num;
	unsigned int			m;

	gnl += 7;
	m = 0;
	num = 0;

	if (!(engine->sectors = ft_realloc(engine->sectors,
			++engine->num_sectors, sizeof(*engine->sectors))))
		return (0);
	sect = &engine->sectors[engine->num_sectors - 1];
	if (!ft_num_init(&num, &gnl, &m, sect))
		return (0);
	if (!ft_mnogo_if(engine, m, sect, num))
		return (0);
	m = -1;
	while (++m < sect->npoints)
	{
		sect->neighbors[m] = num[m + sect->npoints];
		sect->vertex[m + 1] = vert[num[m]];
	}
	sect->vertex[0] = sect->vertex[sect->npoints];
	ft_memdel((void **)&num);
	return (1);
}
