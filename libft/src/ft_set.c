/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:41:35 by htillman          #+#    #+#             */
/*   Updated: 2019/07/05 19:19:35 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_set(void *mass, void *what, size_t size, size_t len)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*cast;

	arr = (unsigned char *)mass;
	cast = (unsigned char *)what;
	i = 0;
	while (i < len)
	{
		arr[i] = cast[i % size];
		i++;
	}
	mass = (void *)arr;
}
