/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:26:54 by htillman          #+#    #+#             */
/*   Updated: 2018/12/06 22:13:57 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	lenn;

	lenn = 0;
	if (!*needle)
		return ((char *)haystack);
	lenn = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if (ft_strncmp(haystack, needle, lenn) == 0)
		{
			return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}
