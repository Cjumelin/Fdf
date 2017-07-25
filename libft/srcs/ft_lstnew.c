/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 05:38:41 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/25 17:34:48 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	if (!(p = malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		p->content = NULL;
		p->content_size = 0;
	}
	else
	{
		if (!(p->content = malloc(sizeof(content) * content_size)))
			return (NULL);
		ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
	}
	p->next = NULL;
	return (p);
}
