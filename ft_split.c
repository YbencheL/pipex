/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:16:30 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/17 18:42:45 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	count_splits(char const *s, char c)
{
	size_t	count;
	int		in_split;

	count = 0;
	in_split = 0;
	while (*s)
	{
		if (*s != c && !in_split)
		{
			in_split = 1;
			count++;
		}
		else if (*s == c)
			in_split = 0;
		s++;
	}
	return (count);
}

static char	**free_split(char **split, size_t i)
{
	while (i--)
		free(split[i]);
	free(split);
	return (NULL);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**process_splits(char const *s, char c, char **split)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = get_word_len(s, c);
			split[i] = ft_substr(s, 0, len);
			if (!split[i])
				return (free_split(split, i));
			i++;
			s += len;
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	total_splits;

	if (!s)
		return (NULL);
	total_splits = count_splits(s, c);
	split = (char **)malloc((total_splits + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	return (process_splits(s, c, split));
}
