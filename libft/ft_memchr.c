/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:31:36 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/11/24 18:05:17 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int ch, size_t count)
{
	size_t i;

	i = 0;
	while (count > i)
	{
		if (((char*)ptr)[i] == (char)ch)
			return ((char*)ptr + i);
		i++;
	}
	return (0);
}
