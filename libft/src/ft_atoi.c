/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmanfred <cmanfred@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 21:02:20 by htillman          #+#    #+#             */
/*   Updated: 2019/06/01 00:06:41 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] == '\n') || (str[i] == '\t')
	|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r')
	|| (str[i] == ' '))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while ((str[i] != '\0') && (ft_isdigit(str[i])))
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return ((int)(sign * num));
}
