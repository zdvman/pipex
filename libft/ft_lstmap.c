/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:59:22 by dzuiev            #+#    #+#             */
/*   Updated: 2023/10/30 11:24:55 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*last_element;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	if (!new_list)
		return (NULL);
	last_element = new_list;
	while (lst->next)
	{
		lst = lst->next;
		last_element->next = ft_lstnew((*f)(lst->content));
		if (!last_element->next)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		last_element = last_element->next;
	}
	return (new_list);
}
