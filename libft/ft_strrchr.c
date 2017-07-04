/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:49:42 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/11/25 17:41:49 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	const char *d;
	const char *a;

	d = str;
	a = NULL;
	while (*d)
	{
		if (*d == ch)
			a = d;
		d++;
	}
	if (ch == 0)
		return ((char*)d);
	return ((char*)a);
}
