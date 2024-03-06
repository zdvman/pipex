/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:46:37 by dzuiev            #+#    #+#             */
/*   Updated: 2023/11/05 19:57:20 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = 0;
}
/*
void	ft_bzero(void *str, size_t len)
{
	ft_memset(str, 0, len);
}
*/
/*
void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = 0;
}
*/
/*
int	main(int argc, char **argv)
{
	char	*a;
	char	*b;
	size_t	n;

	if (argc == 3)
	{

		n = ((size_t)atoi(argv[2]));
		a = (char *)malloc(sizeof(char) * strlen(argv[1]));
		if (!a)
			return (-1);
		b = (char *)malloc(sizeof(char) * strlen(argv[1]));
		if (!b)
			return (-1);

		printf("%i\n", argc);
		printf("%s\n", argv[1]);
		a = strcpy(a, argv[1]);
		b = strcpy(b, argv[1]);
		bzero(a, n);
		ft_bzero(b, n);
		for (size_t i=0; i < strlen(argv[1]); i++)
		{
			printf("%02hhx", a[i]);

		}
		printf("\n");
		for (size_t i=0; i < strlen(argv[1]); i++)
		{
			printf("%02hhx", b[i]);

		}
		printf("\n");
	}
	free(a);
	free(b);
	return (0);
}
*/
