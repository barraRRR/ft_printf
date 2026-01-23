/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 08:41:54 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/14 12:32:20 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_partial(char **split, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free(split[j]);
		j++;
	}
	free(split);
}

static int	count_sub(char const *s, char c)
{
	int			sub;
	size_t		i;

	sub = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			sub++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (sub);
}

static char	*sub_alloc(char const *s, char c)
{
	char		*sub;
	size_t		len;
	size_t		i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		sub[i] = s[i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

static int	split_alloc(char **split, char const *s, char c, int sub)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[j] && i < sub)
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j] && s[j] != c)
		{
			split[i] = sub_alloc(s + j, c);
			if (!split[i])
			{
				free_partial(split, i);
				return (0);
			}
			i++;
			while (s[j] && s[j] != c)
				j++;
		}
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		sub;

	if (!s)
		return (0);
	sub = count_sub(s, c);
	split = malloc(sizeof(char *) * (sub + 1));
	if (!split)
		return (NULL);
	if (!split_alloc(split, s, c, sub))
		return (NULL);
	split[sub] = NULL;
	return (split);
}
