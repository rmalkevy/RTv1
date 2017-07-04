/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:37:59 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:26:54 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		len;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char*)malloc(len + 1);
	if (!join)
	{
		return (NULL);
	}
	join[len] = '\0';
	while (*s1 || *s2)
	{
		if (*s1)
			*join++ = *s1++;
		else
			*join++ = *s2++;
	}
	return (join - len);
}
