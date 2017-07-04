/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:19:18 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/03 15:01:11 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*a;
	const char	*b;
	size_t		len_s2;

	b = s2;
	len_s2 = 0;
	if (*s2 == 0)
		return ((char*)s1);
	while (*s1)
	{
		a = s1;
		while (*b == *a)
		{
			len_s2++;
			if (len_s2 == ft_strlen(s2))
				return ((char*)s1);
			a++;
			b++;
		}
		len_s2 = 0;
		s1++;
		b = s2;
	}
	return (NULL);
}
