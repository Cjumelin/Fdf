/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 19:30:53 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/25 16:29:48 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **lst, t_list *new)
{
	if (!*lst)
		*lst = NULL;
	if (!new)
		new = ft_lstnew(new, 0);
	new->next = *lst;
	*lst = new;
}
