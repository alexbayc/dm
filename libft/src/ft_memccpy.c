/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:23:23 by htillman          #+#    #+#             */
/*   Updated: 2018/12/07 20:35:26 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *buf;
	unsigned char *buf1;
	unsigned char c1;

	c1 = (unsigned char)c;
	buf = (unsigned char *)dst;
	buf1 = (unsigned char *)src;
	while (n)
	{
		*buf = *buf1;
		if (*buf1 == c1)
			return (dst + 1);
		buf++;
		buf1++;
		n--;
		dst++;
	}
	return (NULL);
}
