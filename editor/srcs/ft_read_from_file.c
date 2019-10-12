#include "doom.h"

void	ft_fill_lines(t_doom *d)
{
	t_sector_lst	*sec;
	t_points		*p;
	t_line			*l;

	sec = d->sect_head;
	while (sec)
	{
		p = sec->head;
		while (p->next)
		{
			if (!(ft_line_repeats(d->lines, *p, *(p->next))))
				ft_add_line(&d->lines, *p, *(p->next));
			p = p->next;
		}
		if (!(ft_line_repeats(d->lines, *p, *(sec->head))))
			ft_add_line(&d->lines, *p, *(sec->head));
		sec = sec->next;
	}
	l = d->lines;
}

void	ft_read_sectors(int fd, t_doom *d)
{
	char			*str;
	char			*save;
	int				ret;
	t_points		tmp;
	t_sector_lst	*sec;
	t_points		*p;

	ret = get_next_line(fd, &str);
	while (ret > 0 && str[0] == 's')
	{
		sec = ft_create_last_sec(&d->sect_head);
		save = &(str[7]);
		sec->floor = ft_scan_digit(&save);
		sec->ceiling = ft_scan_digit(&save);
		sec->valid = 1;
		while (*save == '\t')
			save++;
		while (*save != '\t')
		{
			tmp = ft_get_point_with_number(d->point_lst, ft_scan_digit(&save));
			ft_add_point_to_lst(&(sec->head), tmp.x, tmp.y);
			while (*save != '\0' && (*save == ' '))
				save++;
		}
		p = sec->head;
		ft_free((void **)&str);
		ret = get_next_line(fd, &str);
	}
	ft_free((void **)&str);
}

void	ft_read_player(int fd, t_doom *d)
{
	char	*str;
	char	*save;
	int		ret;

	if ((ret = get_next_line(fd, &str)) <= 0)
		return ;
	save = &(str[7]);
	d->player->pos.x = ft_scan_digit(&save);
	d->player->pos.y = ft_scan_digit(&save);
	d->player->angle = ft_scan_digit(&save);
	d->player->is = 1;
	ft_free((void **)&str);

}

void	ft_read_points(int fd, t_doom *d)
{
	char		*str;
	int			ret;
	char		*save;
	int			y;
	t_points	*tmp;

	ret = get_next_line(fd, &str);
	while (ret > 0 && str[0] == 'v')
	{
		save = &(str[7]);
		y = ft_scan_digit(&save);
		while (*save)
		{
			ft_add_point_to_lst(&d->point_lst, ft_scan_digit(&save), y);
			while (*save != '\0' && (*save == ' ' || *save == '\t'))
				save++;
		}
		ft_free((void **)&str);
		ret = get_next_line(fd, &str);
	}
	ft_free((void **)&str);
	tmp = d->point_lst;
}

void	ft_read_from_file(int fd, t_doom *d)
{
	ft_read_points(fd, d);
	ft_read_sectors(fd, d);
	ft_fill_lines(d);
	ft_read_player(fd, d);
}
