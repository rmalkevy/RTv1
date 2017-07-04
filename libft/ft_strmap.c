/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:02:11 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 18:57:04 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			i++;
		}
	}
	else
		return (NULL);
	ptr = (char*)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	else
		ptr[i] = '\0';
	i = 0;
	while (s[i])
	{
		ptr[i] = f(s[i]);
		i++;
	}
	return (ptr);
}
