/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:49:16 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/28 08:32:03 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	printf_strlen(char const *str)
{
	ssize_t		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

ssize_t	printf_putchr(char c)
{
	if (write(1, &c, 1) < 0)
		return (PRINTF_ERROR);
	return (1);
}

ssize_t	printf_putstr(char const *s)
{
	ssize_t		len;

	len = 0;
	if (!s)
	{
		len = printf_strlen("(null)");
		write(1, "(null)", len);
		return (len);
	}
	len = printf_strlen(s);
	if (write(1, s, len) < 0)
		return (PRINTF_ERROR);
	return (len);
}
