/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htillman <htillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:09:26 by htillman          #+#    #+#             */
/*   Updated: 2018/12/12 20:50:23 by htillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *head;

	if (!alst || !del)
		return ;
	head = *alst;
	while (head)
	{
		del(head->content, head->content_size);
		free(head);
		head = head->next;
	}
	*alst = NULL;
}
