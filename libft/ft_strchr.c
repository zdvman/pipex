/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:07:03 by dzuiev            #+#    #+#             */
/*   Updated: 2023/10/30 11:07:07 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int character)
{
	while (*str != (char)character)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}
