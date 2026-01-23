/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:08:55 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/14 13:26:20 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The  memcpy()  function  copies n bytes from memory area src
// to memory area dest.  The memory areas must not overlap.
// Use memmove(3) if the memory areas do overlap.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*ptr1;
	const unsigned char		*ptr2;

	if (!dst && !src && n)
		return (NULL);
	i = 0;
	ptr1 = (unsigned char *)dst;
	ptr2 = (const unsigned char *)src;
	while (i < n)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dst);
}
