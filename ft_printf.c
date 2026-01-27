/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:42:36 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/27 16:11:33 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"


// ****** PARSING FUNCTIONS ******
bool	is_arg(char c2)
{
	if (c2 == 'c' || c2 == 's' || c2 == 'p' || c2 == 'd'
		|| c2 == 'i' || c2 == 'u' || c2 == 'x' || c2 == 'X' || c2 == '%')
		return (true);
	return (false);
}

bool	arg_parser(va_list *ap, char arg, int *len)
{
	if (arg == 'c' || (arg == '%'))
		return(printf_putchr(ap, len)); // √
	else if (arg == 's')
		return(printf_putstr(ap, len)); // √
	else if (arg == 'p')
		return(printf_putptr(ap, len)); // v
	else if (arg == 'd')
		return(printf_putdig(ap, len)); // v
	else if (arg == 'i')
		return(printf_putdig(ap, len)); // v
	else if (arg == 'u')
		return(printf_putun(ap, len)); // todo
	else if (arg == 'x')
		return(printf_puthex(ap, len)); // v
	else if (arg == 'X')
		return(printf_putuphex(ap, len)); // v
}

// *************************************

bool	putun(va_list *ap, size_t *len)
{
	unsigned long		n;
	char				*str;
	
	n = va_arg(*ap, long);
	str = printf_itoa(n);
	if (!str)
		return (false);
	*len += ft_strlen(str);
	ft_pustr(str);
	free(str);
	return (true);
}

// ****** POINTER & HEX ******
void	hex_cat(char *buf, char hex)
{
	char	*ptr;

	while(*ptr)
		*ptr++;
	*ptr = hex;
}

void	to_hex(char *buf, unsigned long long n)
{
	char				*hex;

	hex = "0123456789abcdef";
	if (n >= 16)
		to_hex(buf, n / 16);
	hex_cat(buf, &hex[n % 16]); // ojo que no entra porque no va a contar bien destlen
}

bool	printf_puthex(va_list *ap, size_t *len)
{
	unsigned int		n;
	char				*buf;

	n = va_arg(*ap, unsigned int);
	buf = malloc(sizeof(char) * 20);
	if (!buf)
		return (false);
	ft_memset(buf, 0, 20);
	to_hex(buf, n);
	*len += ft_strlen(buf);
	ft_putstr(buf);
	free(buf);
	return (true);
}

bool	printf_putuphex(va_list *ap, size_t *len)
{
	unsigned int		n;
	char				*buf;
	size_t				i;

	n = va_arg(*ap, unsigned int);
	buf = malloc(sizeof(char) * 20);
	if (!buf)
		return (false);
	ft_memset(buf, 0, 20);
	to_hex(buf, n);
	*len += ft_strlen(buf);
	i = 0;
	while (str[i])
		topper(str[i++]);
	ft_putstr(buf);
	free(buf);
	return (true);
}





// --- FINISHED ----
bool	print_putptr(va_list *ap, size_t len)
{
	unsigned long long			n;
	char						*hex;
	char						*buf;

	n = va_arg(*ap, unsigned long long);
	if (!n)
	{
		write(1, "(nil)", 5);
		len += 5;
	}
	else
	{
		buf = malloc(sizeof(char) * 20);
		if (!buf)
			return (false);
		ft_memset(buf, 0, 20);
		to_hex(buf, n);
		ft_putstr("0x");
		len += (2 + ft_strlen(hex));
		free(buf);
	}
	return (true);
}

bool	printf_putchr(va_list *ap, size_t *len)
{
	char		c;

	c = va_arg(*ap, int);
	if (write(1, &c, 1) < 0)
		return (false);
	(*len)++;
	return (true);
}

bool	printf_putstr(va_list *ap, size_t *len)
{
	char		*str;

	str = va_arg(*ap, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		*len += 6;
		return (true);
	}
	*len += ft_strlen(str);
	ft_putstr(str);
	return (true);
}

bool	printf_putdig(va_list *ap, size_t *len)
{
	long		n;
	char		*str;

	n = va_arg(*ap, long);
	str = printf_itoa(n);
	if (!str)
		return (false);
	*len += ft_strlen(str);
	ft_pustr(str);
	free(str);
	return (true);
}

int	ft_printf(char const *str, ...)
{
	va_list			ap;
	size_t			len;

	va_start(ap, str);
	len = 0;
	while (str)
	{
		if (*str == '%' && *(++str) && is_arg(&str))
		{
			if (!arg_parser(&ap, &str, &len))
				return (-1);
		}
		else
		{
			ft_putchr(&str);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
