/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:42:36 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/28 11:37:39 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char const *str, ...)
{
	va_list			ap;
	ssize_t			total_len;
	ssize_t			arg_len;

	va_start(ap, str);
	total_len = 0;
	while (*str)
	{
		if (*str == '%' && *(++str) && is_arg(*str))
		{
			arg_len = arg_parser(&ap, *str);
			if (arg_len == -1)
				return (PRINTF_ERROR);
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

int	is_arg(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
		|| c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

ssize_t	arg_parser(va_list *ap, char arg)
{
	ssize_t		len;

	len = 0;
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
