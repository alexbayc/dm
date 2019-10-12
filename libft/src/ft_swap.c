/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 20:49:40 by htillman          #+#    #+#             */
/*   Updated: 2019/05/31 20:49:48 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t len)
{
	unsigned char	*p;
	unsigned char	*q;
	unsigned char	tmp;
	size_t			i;

	i = -1;
	if (!a || !b)
		return ;
	p = a;
	q = b;
	while (++i < len)
	{
		tmp = p[i];
		p[i] = q[i];
		q[i] = tmp;
	}
}
