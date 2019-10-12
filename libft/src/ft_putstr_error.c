/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 20:09:22 by htillman          #+#    #+#             */
/*   Updated: 2018/12/11 13:30:57 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar_error(char c)
{
	write(2, &c, 1);
}

void		ft_putstr_error(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_error(s[i]);
		i++;
	}
}
