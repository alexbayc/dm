#include "engine.h"

int				ft_vert_data(t_xy **vert_main, char *gnl, int *num_vert)
{
	char		*save;
	t_xy		*vert;
	int			i;

	i = 0;
	vert = *vert_main;
	save = &gnl[7];
	ft_scan_digit(&save);
	while (*save)
	{
		if (!(vert = ft_realloc(vert, ++*num_vert, sizeof(*vert))))
			return (0);
		vert[*num_vert - 1].y = ft_atof(&gnl[7]);
		vert[*num_vert - 1].x = ft_scan_digit(&save);
		while (*save != '\0' && (*save == ' ' || *save == '\t'))
			save++;
	}
	*vert_main = vert;
	return (1);
}
