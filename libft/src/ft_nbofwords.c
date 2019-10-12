/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbofwords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:48:34 by htillman          #+#    #+#             */
/*   Updated: 2019/03/07 20:46:46 by cmanfred         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbofwords(char const *s, char c)
{
	size_t	nb;
	size_t	i;

	if (!s || !c)
		return (0);
	nb = 0;
	i = 0;
	if (s[0] != c)
		nb++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			nb++;
		i++;
	}
	return ((int)nb);
}
