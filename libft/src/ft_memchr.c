/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:07:21 by htillman          #+#    #+#             */
/*   Updated: 2018/12/07 20:34:39 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *src;
	unsigned char c1;

	src = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (n)
	{
		if (*src == c1)
			return (src);
		src++;
		n--;
	}
	return (NULL);
}
