/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:53:34 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/11/26 19:32:19 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *lhs, const void *rhs, size_t count)
{
	size_t i;

	i = 0;
	while (count > i)
	{
		if (((char*)lhs)[i] != ((char*)rhs)[i])
			return (((unsigned char*)lhs)[i] - ((unsigned char*)rhs)[i]);
		i++;
	}
	return (0);
}
