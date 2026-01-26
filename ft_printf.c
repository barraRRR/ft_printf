/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:42:36 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/26 17:00:04 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

bool	is_arg(char c1, char c2)
{
	if (c1 == '%' && (c2 == 'c' || c2 == 's' || c2 == 'p' || c2 == 'd'
		|| c2 == 'i' || c2 == 'u' || c2 == 'x' || c2 == 'X' || c2 == '%'))
		return (true);
	return (false);
}

bool	put_arg(va_list ap, char arg, int *len)
{
	if (arg == 'c')
		return(printf_putchr(ap, len));
	else if (arg == 's')
		return(printf_putstr(ap, len));
	else if (arg == 'p')
		return(printf_putptr(ap, len));
	else if (arg == 'd')
		return(printf_putdig(ap, len));
	else if (arg == 'i')
		return(printf_putdig(ap, len));
	else if (arg == 'u')
		return(printf_putdig(ap, len)); // unsigned
	else if (arg == 'x')
		return(printf_puthex(ap, len));
	else if (arg == 'X')
		return(printf_putuphex(ap, len));
}

bool	printf_putchr(char c, size_t *len)
{
	if (write(1, &c, 1) < 0)
		return (false);
	(*len)++;
	return (true);
}

bool	printf_putstr(char *str, size_t *len)
{
	*len *= ft_strlen(str);
	ft_putstr(str);
	return (true);
}

bool	printf_putdig(long nbr, size_t *len)
{
	char	*str;

	str = printf_itol(long nbr);

int	ft_printf(char const *str, ...)
{
	va_list			ap;
	size_t			i;
	size_t			len;

	va_start(ap, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] && is_arg(str[i], str[i + 1]))
		{
			if (!put_arg(ap, str[i + 1], &len))
				return (-1);
			i += 2;
		}
		else if (str[i] == '%')
			return (-1);	// gestionar el %
		else
			len += printf_putchr(str[i++]);
	}
	va_end(ap);
	return (len);
}
