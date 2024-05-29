/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorisak <hmorisak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 20:53:24 by hmorisak          #+#    #+#             */
/*   Updated: 2022/11/19 13:49:08 by hmorisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*head;

	head = NULL;
	if (lst && f)
	{
		while (lst)
		{
			new_list = ft_lstnew(f(lst->content));
			if (new_list == NULL)
			{
				ft_lstclear(&head, del);
				return (NULL);
			}
			ft_lstadd_back(&head, new_list);
			lst = lst->next;
		}
		return (head);
	}
	return (NULL);
}
