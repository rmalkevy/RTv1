/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:13:04 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:10:04 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	int		i;

	i = 0;
	mem = malloc(size);
	if (!mem)
		return (NULL);
	while (size)
	{
		((unsigned char *)mem)[i] = 0;
		i++;
		size--;
	}
	return (mem);
}
