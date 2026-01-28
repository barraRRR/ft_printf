/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_nbr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 07:52:48 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/28 08:48:54 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	printf_putnbr(int nbr)
{
	long		n;
	ssize_t		len;

	n = nbr;
	len = 0;
	if (n < 0)
	{
		len += 1;
		if (write(1, "-", 1) < 0)
			return (PRINTF_ERROR);
		n = -n;
	}
	if (n >= 10)
		len += printf_putnbr((n / 10));
	if (len < 0)
		return (PRINTF_ERROR);
	len += printf_putchr((n % 10) + '0');
	return ((int)len);
}

ssize_t	printf_putunbr(unsigned int n)
{
	ssize_t		len;

	len = 0;
	if (n >= 10)
		len += printf_putunbr(n / 10);
	if (len < 0)
		return (PRINTF_ERROR);
	len += printf_putchr((n % 10) + '0');
	return (len);
}

ssize_t	printf_puthex(unsigned long long n, char const *hex)
{
	ssize_t		len;

	len = 0;
	if (n >= 16)
		len += printf_puthex(n / 16, hex);
	if (len < 0)
		return (PRINTF_ERROR);
	len += printf_putchr(hex[n % 16]);
	return (len);
}

/*		*** LINUX VERSION ***
		len = printf_strlen("(nil)");
		write(1, "(nil)", len);
*/
ssize_t	printf_putptr(unsigned long ptr)
{
	ssize_t		len;

	if (!ptr)
	{
		len = printf_strlen("0x0");
		write(1, "0x0", len);
		return (len);
	}
	len = printf_putstr("0x");
	if (len < 0)
		return (PRINTF_ERROR);
	len += printf_puthex(ptr, "0123456789abcdef");
	return (len);
}
