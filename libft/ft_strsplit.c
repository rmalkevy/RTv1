/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:23:10 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/02 13:18:46 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	num_words(char const *s, char c)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (ft_strlen(s) > 0)
		while (s[i])
		{
			if (s[i] != c)
			{
				count++;
				while (s[i] != c && s[i] != '\0')
					i++;
			}
			else
				i++;
		}
	return (count);
}

static char	*next_word(char const *s, char c)
{
	char	*word;
	size_t	size;

	size = 0;
	while (s[size] != c && s[size] != '\0')
	{
		size++;
	}
	word = ft_strsub(s, 0, size);
	return (word);
}

static char	**all_words(char **split, char const *s, char c)
{
	int size;

	size = 0;
	while (*s)
	{
		if (*s != c)
		{
			split[size] = next_word(s, c);
			size++;
			while (*s != c && *s != '\0')
				s++;
		}
		else
			s++;
	}
	split[size] = 0;
	return (split);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**split;
	int		size;

	if (!s)
	{
		return (NULL);
	}
	size = num_words(s, c);
	split = (char**)malloc(sizeof(char*) * (size + 1));
	if (!split)
	{
		return (NULL);
	}
	split = all_words(split, s, c);
	return (split);
}
