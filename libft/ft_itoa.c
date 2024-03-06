/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:54:25 by dzuiev            #+#    #+#             */
/*   Updated: 2023/10/30 10:54:30 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	unsigned int	tmp;
	int				i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	tmp = (unsigned int)n;
	while (tmp >= 10)
	{
		tmp /= 10;
		i++;
	}
	return (i);
}

static unsigned int	ft_tenpow(int n)
{
	if (n == 0)
		return (1);
	else
		return (10 * ft_tenpow(n - 1));
}

char	*ft_itoa(int n)
{
	unsigned int	divisor;
	int				i;
	char			*num;
	char			*tmp;

	i = ft_intlen(n);
	tmp = (char *)malloc(i + 1);
	if (!tmp)
		return (NULL);
	num = tmp;
	if (n < 0)
	{
		*num++ = '-';
		n *= -1;
		i--;
	}
	while (i > 0)
	{
		divisor = ft_tenpow(i - 1);
		*num++ = n / divisor + 48;
		n = n - (n / divisor) * divisor;
		i--;
	}
	*num = '\0';
	return (tmp);
}

/*
int	ft_intlen(int n)
{
	unsigned int	tmp;
	int				len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	tmp = n;
	while (tmp >= 10)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	tmp;
	char			*str;
	int				len;

	len = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		tmp = -n;
	}
	else
		tmp = n;
	while (len-- > 0 && str[len] != '-')
	{
		str[len] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}
*/
/*
int    main(void)
{
	char	*str;
	
	str = ft_itoa(-2147483647)
    printf("Nu : %s\n", str);
	free(str);
    return (0);
}
*/
