/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:13:47 by dzuiev            #+#    #+#             */
/*   Updated: 2024/02/05 17:13:47 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	ft_convert_digits(const char *str, int i, int sign)
{
	long long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > LLONG_MAX / 10
			|| (result == LLONG_MAX / 10 && (str[i] - '0') > LLONG_MAX % 10))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;
	int			i;

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
