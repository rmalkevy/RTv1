/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:51:36 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 19:29:57 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*nlist;
	t_list	*prev;
	t_list	*temp;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	nlist = NULL;
	prev = NULL;
	while (lst)
	{
		nlist = f(lst);
		if (i == 0)
			temp = nlist;
		lst = lst->next;
		if (prev)
			prev->next = nlist;
		prev = nlist;
		i++;
	}
	nlist = temp;
	return (nlist);
}
