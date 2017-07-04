/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 16:52:22 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/02 14:17:27 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char*)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	while (size + 1)
	{
		ptr[i] = 0;
		i++;
		size--;
	}
	return (ptr);
}
