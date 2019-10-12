/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:55:31 by htillman          #+#    #+#             */
/*   Updated: 2019/03/14 13:53:05 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	makearr(char *res, int tmp, int len)
{
	int		i;

	i = len;
	if (tmp == 0)
		res[0] = '0';
	if (tmp < 0)
		res[0] = '-';
	while (tmp != 0)
	{
		if (tmp % 10 >= 0)
			res[i] = tmp % 10 + '0';
		else
			res[i] = tmp % 10 * -1 + '0';
		tmp /= 10;
		i--;
	}
	res[len + 1] = '\0';
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		tmp;

	len = -1;
	tmp = n;
	while (tmp != 0 && ++len > -2)
		tmp /= 10;
	if (n <= 0)
		len++;
	if (!(res = (char *)malloc(sizeof(char) * (len + 2))))
		return (NULL);
	makearr(res, n, len);
	return (res);
}
