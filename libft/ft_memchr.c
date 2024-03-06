/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:01:18 by dzuiev            #+#    #+#             */
/*   Updated: 2023/11/05 20:52:56 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

/*
int	main(int argc, char **argv)
{
	char	*a;
	char	*b;
	size_t	n;
	int		c;

	if (argc == 4)
	{
		c = atoi(argv[2]) + 48;
		n = (size_t)(atoi(argv[3]));
		a = (char *)malloc(sizeof(char) * strlen(argv[1]));
		if (!a)
			return (-1);
		b = (char *)malloc(sizeof(char) * strlen(argv[1]));
		if (!b)
			return (-1);
		printf("argc : %i\n", argc);
		printf("s : %s; c : %c; n : %zu\n", argv[1], (char)c, n);
		a = strcpy(a, argv[1]);
		b = strcpy(b, argv[1]);
		printf("адрес в а memchr: %p\n", memchr(a, c, n));
		printf("адрес в b ft_memchr: %p\n", memchr(a, c, n));
	}
	free(a);
	free(b);
	return (0);
}
*/
