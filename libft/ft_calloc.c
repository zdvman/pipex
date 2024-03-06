/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:47:02 by dzuiev            #+#    #+#             */
/*   Updated: 2023/11/08 11:30:41 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	size_t	overflow;
	void	*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	else
	{
		bytes = nmemb * size;
		overflow = bytes / size;
		if (nmemb != overflow)
			return (NULL);
	}
	ptr = (void *)malloc(bytes);
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, bytes));
}

/*
void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*str;
	size_t			bytes;
	void			*ptr;

	if (!nmemb || !size)
		return (malloc(0));
	bytes = nmemb * size;
	if (nmemb != bytes / size)
		return (NULL);
	ptr = (void *)malloc(bytes);
	if (!ptr)
		return (NULL);
	str = (unsigned char *)ptr;
	while (bytes--)
		*str++ = 0;
	return (ptr);
}
*/

/*
void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*memory;

	memory = (void *)malloc(num_elements * element_size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, num_elements * element_size);
	return (memory);
}
*/
