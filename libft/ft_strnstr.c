/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:21:41 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/03 17:46:11 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (s2[i] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j] && (i + j) < len)
		{
			j++;
			if (j == ft_strlen(s2))
				return ((char*)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
