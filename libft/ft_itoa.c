/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:08:44 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/14 12:30:26 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long l, size_t digits)
{
	if (l < 10)
		return (digits);
	else
		return (count_digits(l / 10, digits + 1));
}

static void	cat_num(char *str, char c)
{
	size_t		i;

	i = 0;
	while (str[i])
		i++;
	str[i] = c;
}

static void	countdown(char *str, long l)
{
	if (l >= 10)
		countdown(str, l / 10);
	cat_num(str, (char)((l % 10) + '0'));
}

char	*ft_itoa(int n)
{
	long		l;
	size_t		digits;
	int			sign;
	char		*str;

	l = n;
	sign = 0;
	if (l < 0)
	{
		sign = 1;
		l = -l;
	}
	digits = count_digits(l, 1);
	str = (char *)ft_calloc((sign + digits + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	countdown(str, l);
	return (str);
}
