/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzuiev <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:02:40 by dzuiev            #+#    #+#             */
/*   Updated: 2023/11/08 10:16:16 by dzuiev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_ptr;
	unsigned char		*dest_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	if (dest_ptr == src_ptr || n == 0)
		return (dest);
	if (dest_ptr < src_ptr || dest_ptr >= src_ptr + n)
	{
		while (n--)
			*dest_ptr++ = *src_ptr++;
	}
	else
	{
		dest_ptr += n;
		src_ptr += n;
		while (n--)
			*(--dest_ptr) = *(--src_ptr);
	}
	return (dest);
}
