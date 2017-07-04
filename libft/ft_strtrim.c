/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:34:37 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:09:00 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*trim;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (!s)
	{
		return (NULL);
	}
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		trim = (char*)malloc(1);
		trim[0] = '\0';
	}
	else
	{
		len = ft_strlen(s) - 1;
		while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
			len--;
		len = len - i + 1;
		trim = ft_strsub(s, i, len);
	}
	return (trim);
}
