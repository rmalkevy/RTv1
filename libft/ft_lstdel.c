/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmalkevy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:45:10 by rmalkevy          #+#    #+#             */
/*   Updated: 2016/12/01 18:02:45 by rmalkevy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	list = *alst;
	while (list)
	{
		*alst = list;
		del((*alst)->content, (*alst)->content_size);
		list = (*alst)->next;
		free(*alst);
	}
	*alst = NULL;
}
