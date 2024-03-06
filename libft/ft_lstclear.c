/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:56:13 by dzuiev            #+#    #+#             */
/*   Updated: 2023/10/30 10:56:16 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*temp2;

	if (lst && del)
	{
		temp = *lst;
		while (temp)
		{
			temp2 = temp->next;
			ft_lstdelone(temp, del);
			temp = temp2;
		}
		*lst = NULL;
	}
}
