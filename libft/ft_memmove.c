/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:18:35 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:01:31 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char *d;
	char *s;

	s = (char*)src;
	d = (char*)dest;
	if (dest > src)
	{
		while (count)
		{
			d[count - 1] = s[count - 1];
			count--;
		}
	}
	if (dest < src)
	{
		while (count)
		{
			*d++ = *s++;
			count--;
		}
	}
	return (dest);
}
