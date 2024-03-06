/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:13:45 by dzuiev            #+#    #+#             */
/*   Updated: 2023/10/30 11:13:49 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int character)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char)character)
			last = (char *)str;
		str++;
	}
	if (*str == (char)character)
		last = (char *)str;
	return (last);
}
