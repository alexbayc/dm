/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 17:55:37 by htillman          #+#    #+#             */
/*   Updated: 2018/12/12 16:50:00 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*buf;
	unsigned char	*buf1;

	if (!dst && !src)
		return (NULL);
	buf = (unsigned char *)dst;
	buf1 = (unsigned char *)src;
	while (n)
	{
		*buf = *buf1;
		buf++;
		buf1++;
		n--;
	}
	return (dst);
}
