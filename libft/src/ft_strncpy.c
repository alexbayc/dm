/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nevanna <nevanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:29:36 by htillman          #+#    #+#             */
/*   Updated: 2018/12/17 17:45:41 by nevanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*buf;

	buf = dst;
	while ((*src) && len > 0)
	{
		*buf = *src;
		len--;
		src++;
		buf++;
	}
	while (len > 0)
	{
		*buf = '\0';
		len--;
		buf++;
	}
	return (dst);
}
