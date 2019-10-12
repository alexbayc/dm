/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:45:27 by htillman          #+#    #+#             */
/*   Updated: 2018/12/06 22:09:37 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*newstr;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	newstr = (char*)malloc(sizeof(*s1) * (len + 1));
	if (newstr == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[len] = '\0';
	return (newstr);
}
