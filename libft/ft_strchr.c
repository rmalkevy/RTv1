/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:48:36 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:00:06 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*p)
	{
		if (*p == c)
			return ((char*)p);
		p++;
	}
	if (c == 0)
		return ((char*)p);
	return (0);
}
