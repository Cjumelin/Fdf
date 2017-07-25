/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 20:54:15 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/27 09:58:35 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*p;

	p = NULL;
	if (!lst)
		return (NULL);
	if (lst)
	{
		p = f(lst);
		p->next = ft_lstmap(lst->next, f);
		if (!p)
			return (NULL);
	}
	return (p);
}
