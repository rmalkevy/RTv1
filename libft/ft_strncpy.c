/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:22:45 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/02 14:18:04 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char *d;

	d = dst;
	while (*src && len > 0)
	{
		*d++ = *src++;
		len--;
	}
	while (len > 0)
	{
		*d = '\0';
		d++;
		len--;
	}
	return (dst);
}
