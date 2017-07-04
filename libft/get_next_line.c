/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 17:55:48 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/29 18:55:28 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_join(char *s1, char *s2)
{
	char	*join;
	int		len;
	int		l;

	len = ft_strlen(s1);
	l = ft_strlen(s2);
	join = ft_strnew(len + l);
	if (!s1 || !s2 || !join)
		return (NULL);
	while (*s1 || *s2)
		if (*s1)
			*join++ = *s1++;
		else
			*join++ = *s2++;
	free(s1 - len);
	free(s2 - l);
	return (join - len - l);
}

char		*check_dest(char **line, char *p, char *d, int size)
{
	int i;

	i = 0;
	while (d[i])
	{
		if (d[i] == '\n')
		{
			p = ft_strsub(d, i + 1, size - i);
			*line = ft_join(*line, ft_strsub(d, 0, i));
			return (p);
		}
		i++;
	}
	return (NULL);
}

char		*check_static(char **line, char *p)
{
	int size;

	size = -1;
	if (p)
	{
		while (p[++size])
		{
			if (p[size] == '\n')
			{
				*line = ft_strsub(p, 0, size);
				p = ft_strsub(p, size + 1, ft_strlen(p) - size);
				return (p);
			}
		}
		*line = p;
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	char		dest[BUFF_SIZE + 1];
	int			size;
	static char	*p;
	char		*d;

	if (!line)
		return (-1);
	*line = ft_strnew(1);
	if (check_static(&(*line), p))
	{
		p = check_static(&(*line), p);
		return (1);
	}
	while ((size = read(fd, dest, BUFF_SIZE)) && size != -1)
	{
		dest[size] = '\0';
		d = ft_strdup(dest);
		if ((p = check_dest(&(*line), p, d, size)))
			return (1);
		*line = ft_join(*line, d);
	}
	if (size == 0 && ft_strlen(*line) > 0)
		size++;
	return (size);
}
