/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:36:42 by htillman          #+#    #+#             */
/*   Updated: 2018/12/07 20:38:57 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_range(char *begin, size_t size)
{
	char	*tmp;

	tmp = begin;
	while (*tmp && size)
	{
		tmp++;
		size--;
	}
	return (tmp - begin);
}

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*tmp1;
	char	*tmp2;
	size_t	occup_mem;
	size_t	free_mem;

	tmp1 = dst;
	tmp2 = (char *)src;
	occup_mem = get_range(dst, size);
	free_mem = size - occup_mem;
	if (free_mem == 0)
		return (occup_mem + ft_strlen(src));
	tmp1 = tmp1 + occup_mem;
	while (*tmp2)
	{
		if (free_mem != 1)
		{
			*tmp1 = *tmp2;
			tmp1++;
			free_mem--;
		}
		tmp2++;
	}
	*tmp1 = '\0';
	return (occup_mem + (tmp2 - src));
}
