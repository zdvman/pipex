/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:45:00 by dzuiev            #+#    #+#             */
/*   Updated: 2024/02/05 17:24:15 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_convert_digits(const char *str, int i, int sign)
{
	int	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > INT_MAX / 10
			|| (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_convert_digits(str, i, sign);
	return (result);
}
