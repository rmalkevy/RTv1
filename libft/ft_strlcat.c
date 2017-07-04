/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:50:37 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:42:20 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *str, size_t size)
{
	char	*d;
	size_t	i;
	size_t	end;

	d = dest;
	end = 0;
	i = ft_strlen(dest);
	if (i >= size)
	{
		return (size + ft_strlen(str));
	}
	size = size - i - 1;
	while (str[end] && size)
	{
		d[i++] = str[end++];
		size--;
	}
	d[i] = '\0';
	end = i + ft_strlen(str) - end;
	return (end);
}
