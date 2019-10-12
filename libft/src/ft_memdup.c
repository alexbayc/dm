/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 23:03:14 by cmanfred          #+#    #+#             */
/*   Updated: 2019/06/10 17:47:51 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(void *srcs, size_t size)
{
	unsigned char	*res;
	unsigned char	*src;
	size_t			i;

	src = (unsigned char *)srcs;
	res = ft_memalloc(size);
	i = 0;
	while (i < size)
	{
		res[i] = src[i];
		i++;
	}
	return ((void *)res);
}
