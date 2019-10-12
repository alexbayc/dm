/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort_bubble.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:48:00 by htillman          #+#    #+#             */
/*   Updated: 2018/12/13 14:47:54 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ftt_strcmp(char *s1, char *s2)
{
	int			rez;
	int			i;

	i = 0;
	rez = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	rez = s1[i] - s2[i];
	return (rez);
}

void			ft_strsort_bubble(int gc, char **gv)
{
	int		i;
	int		j;
	char	*bubble;

	bubble = gv[gc - 1];
	j = gc - 2;
	while (j != 0)
	{
		i = gc - 2;
		while (i != 0)
		{
			if (ftt_strcmp(gv[i], gv[i + 1]) > 0)
			{
				bubble = gv[i + 1];
				gv[i + 1] = gv[i];
				gv[i] = bubble;
			}
			i--;
		}
		j--;
	}
}
