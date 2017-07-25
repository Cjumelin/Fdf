/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 15:29:35 by cjumelin          #+#    #+#             */
/*   Updated: 2017/01/04 12:34:04 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (dst);
	while (--n)
	{
		(((unsigned char*)dst)[i]) = (((unsigned char*)src)[i]);
		i++;
	}
	(((char*)dst)[i]) = (((char*)src)[i]);
	return (dst);
}
