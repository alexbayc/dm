/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:13:50 by htillman          #+#    #+#             */
/*   Updated: 2018/12/12 17:24:45 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	int		ft_lstlen(t_list *alst)
{
	t_list		*tmp;
	long int	count;

	if (!alst)
	{
		ft_putstr_error("no list");
		return (-1);
	}
	count = 0;
	tmp = alst;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
