/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 17:28:24 by cjumelin          #+#    #+#             */
/*   Updated: 2017/01/22 15:15:04 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	y;

	y = (unsigned char)c;
	src = (unsigned char *)s;
	if (!n)
		return (NULL);
	while (*src != y && --n)
		src++;
	if (*src == y)
		return ((void *)src);
	else
		return (NULL);
}
