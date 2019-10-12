/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:44:46 by htillman          #+#    #+#             */
/*   Updated: 2018/12/15 16:26:59 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *new;
	t_list *new_list;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	tmp = new;
	while (lst)
	{
		new_list = f(lst);
		new->next = new_list;
		new = new_list;
		lst = lst->next;
	}
	return (tmp);
}
