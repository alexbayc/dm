/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 18:59:33 by htillman          #+#    #+#             */
/*   Updated: 2019/02/13 19:12:22 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_exist_n(char **tb, int *len, char **line, int fd)
{
	char		*tmp;

	tmp = NULL;
	if (!(*line = ft_strsub(tb[fd], 0, *len)))
		return (-1);
	if (!(tmp = ft_strdup(tb[fd])))
		return (-1);
	ft_strdel(&(tb[fd]));
	if (!(tb[fd] = ft_strsub(tmp, *len + 1, ft_wlen(tmp, *len + 1, '\0'))))
		return (-1);
	ft_strdel(&tmp);
	if (tb[fd][0] == '\0')
		ft_strdel(&tb[fd]);
	return (1);
}

int				ft_tb_make_line(char **tb, int *len, char **line, int fd)
{
	int			flag;

	flag = 0;
	while (tb[fd][*len] != '\n' && tb[fd][*len] != '\0')
		(*len)++;
	if (tb[fd][0] == '\n')
		flag++;
	if (tb[fd][*len] == '\n')
	{
		if (ft_exist_n(tb, len, line, fd) < 0)
			return (-1);
	}
	else if (tb[fd][*len] == '\0')
	{
		if (!(*line = ft_strdup(tb[fd])))
			return (-1);
		ft_strdel(&tb[fd]);
	}
	return (flag);
}

int				ft_read_line(int fd, char **tb)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	ret = 0;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (tb[fd] == NULL)
			if (!(tb[fd] = ft_strnew(0)))
				return (-1);
		tmp = ft_strjoin(tb[fd], buf);
		ft_strdel(&(tb[fd]));
		tb[fd] = ft_strdup(tmp);
		if (!tmp || !tb[fd])
			return (-1);
		ft_strdel(&tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	static char	*tb[65536];
	t_var		vars;

	vars.ret = 0;
	vars.len = 0;
	vars.flag = 0;
	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	vars.ret = ft_read_line(fd, tb);
	if (vars.ret < 0)
		return (-1);
	if (tb[fd])
		if ((vars.flag = ft_tb_make_line(tb, &vars.len, line, fd)) == -1)
			return (-1);
	if (vars.ret == 0 && (vars.len == 0 && tb[fd] == NULL && vars.flag == 0))
	{
		if (!(*line))
			*line = ft_strnew(0);
		return (0);
	}
	return (1);
}
