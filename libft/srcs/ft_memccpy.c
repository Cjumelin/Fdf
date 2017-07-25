/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:05:46 by cjumelin          #+#    #+#             */
/*   Updated: 2017/01/03 21:06:33 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*sorc;
	unsigned char	d;

	d = (unsigned char)c;
	sorc = (unsigned char*)src;
	dest = (unsigned char*)dst;
	while (n--)
	{
		*dest = *sorc;
		dest++;
		if (*sorc == d)
			return ((void *)dest);
		sorc++;
	}
	return (NULL);
}
