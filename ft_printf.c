/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:42:36 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/25 17:59:42 by jbarreir         ###   ########.fr       */
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

int	put_arg(va_list ap, char arg, int *len)
{
	if (arg == 'c')
		ft_putstr_fd(ap, 1);



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
		{
			ft_putchar_fd(str[i++], 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
