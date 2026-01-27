/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:42:36 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/27 21:39:03 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ****** PARSING FUNCTIONS ******
int	is_arg(char c2)
{
	if (c2 == 'c' || c2 == 's' || c2 == 'p' || c2 == 'd'
		|| c2 == 'i' || c2 == 'u' || c2 == 'x' || c2 == 'X' || c2 == '%')
		return (1);
	return (0);
}

ssize_t	arg_parser(va_list *ap, char arg)
{
	ssize_t		len;

	if (arg == 'c')
		len = printf_putchr(va_arg(*ap, int));
	else if (arg == '%')
		len = printf_putchr('%');
	else if (arg == 's')
		len = printf_putstr(va_arg(*ap, char *));
	else if (arg == 'p')
		len = printf_putptr(va_arg(*ap, unsigned long));
	else if (arg == 'd')
		len = printf_putnbr(va_arg(*ap, int));
	else if (arg == 'i')
		len = printf_putnbr(va_arg(*ap, int));
	else if (arg == 'u')
		len = printf_putunbr(va_arg(*ap, unsigned int));
	else if (arg == 'x')
		len = printf_puthex(va_arg(*ap, unsigned int), "0123456789abcdef");
	else if (arg == 'X')
		len = printf_puthex(va_arg(*ap, unsigned int), "0123456789ABCDEF");
	return (len);
}

// *************************************

ssize_t	printf_putchr(char c)
{
	if (write(1, &c, 1) < 0)
		return (-1);	
	return (1);
}

ssize_t	printf_putstr(char *s)
{
	char		*str;
	ssize_t		len;

	len = 0;
	if (!s)
	{
		len = ft_strlen("(null)");
		write(1, "(null)", len);
		return (len);
	}
	len = ft_strlen(s);
	if (write(1, s, len) < 0)
		return (-1);
	return (len);
}

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
			return (-1);
		n = -n;
	}
	if (n >= 10)
		len += printf_putnbr((n / 10));
	len += printf_putchr((n % 10) + '0');
	return (len);
}

ssize_t	printf_puthex(unsigned long long n, char const *hex)
{
	ssize_t		len;

	len = 0;
	if (n >= 16)
		len += printf_puthex(n / 16, hex);
	len += printf_putchr(hex[n % 16]);
	return (len);
}

// --- FINISHED ----
ssize_t	printf_putptr(unsigned long ptr)
{
	ssize_t		len;

	if (!ptr)
	{
		len = ft_strlen("(nil)");
		write(1, "(nil)", len);
		return (len);
	}
	len = printf_putstr("0x");
	if (!len)
		return (-1);
	len += printf_puthex(ptr, "0123456789abcdef");
	return (len);
}

ssize_t	printf_putunbr(unsigned int n)
{
	ssize_t		len;

	len = 0;
	if (n >= 10)
		len += printf_putunbr(n / 10);
	len += printf_putchr((n % 10) + '0');
	return (len);
}


int	ft_printf(char const *str, ...)
{
	va_list			ap;
	size_t			total_len;
	size_t			arg_len;

	va_start(ap, str);
	total_len = 0;
	while (*str)
	{
		if (*str == '%' && *(++str) && is_arg(*str))
		{
			arg_len = arg_parser(&ap, *str);
			if (arg_len == -1)
				return (-1);
			else
				total_len += arg_len;
			str++;
		}
		else
		{
			total_len += printf_putchr(*str);
			str++;
		}
	}
	va_end(ap);
	return (total_len);
}
