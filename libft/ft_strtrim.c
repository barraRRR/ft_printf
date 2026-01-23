/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:11:28 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/14 12:33:48 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	first_chunk(char const *s, char const *set)
{
	size_t		total;

	total = 0;
	while (s[total])
	{
		if (is_set(s[total], set))
			total++;
		else
			break ;
	}
	return (total);
}

static size_t	last_chunk(char const *s, char const *set, size_t len)
{
	size_t		total;

	total = 0;
	while (len > 0 && is_set(s[len - 1], set))
	{
		len--;
		total++;
	}
	return (total);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	size_t		first;
	size_t		last;
	size_t		new_size;
	char		*new;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	first = first_chunk(s1, set);
	last = last_chunk(s1, set, len);
	new_size = len - first - last;
	if ((first + last) >= len)
		new_size = 0;
	new = malloc(sizeof(char) * (new_size + 1));
	if (!new)
		return (NULL);
	if (new_size > 0)
		ft_memcpy(new, s1 + first, new_size);
	new[new_size] = '\0';
	return (new);
}
