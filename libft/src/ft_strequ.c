/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:25:53 by htillman          #+#    #+#             */
/*   Updated: 2018/12/06 22:09:46 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int		rez;
	size_t	i;

	i = 0;
	rez = 0;
	if (!s1 || !s2)
		return (0);
	while ((s1[i] != '\0') && (s2[i] != '\0') && (s1[i] == s2[i]))
	{
		i++;
	}
	rez = (unsigned char)s1[i] - (unsigned char)s2[i];
	if (rez == 0)
		return (1);
	return (0);
}
