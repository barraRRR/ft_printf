/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 17:16:31 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/14 12:22:29 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The memchr() function scans the initial n bytes of the memory area pointed
// to by s for the first instance of c. Both c and the bytes of the memory area
// pointed to by s are interpreted as unsigned char.
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*ptr;

	ptr = (const unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
