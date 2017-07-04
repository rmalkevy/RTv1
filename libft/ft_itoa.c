/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:31:57 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/02 15:48:32 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		len(int n)
{
	int a;
	int i;

	a = n;
	i = 0;
	if (a <= 0)
		i++;
	while (a != 0)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

static int		minus(int n, char *number)
{
	if (n == 0)
	{
		number[0] = '0';
	}
	if (n < 0)
	{
		number[0] = '-';
		if (n == -2147483648)
		{
			number[1] = '2';
			n = 147483648;
		}
		else
			n = -n;
	}
	return (n);
}

char			*ft_itoa(int n)
{
	char	*number;
	int		i;
	int		b;

	b = 0;
	i = len(n);
	number = (char*)malloc(sizeof(char) * (i + 1));
	if (!number)
		return (NULL);
	number[i] = '\0';
	n = minus(n, number);
	while (n > 0)
	{
		b = n % 10;
		n = n / 10;
		number[--i] = b + '0';
	}
	return (number);
}
