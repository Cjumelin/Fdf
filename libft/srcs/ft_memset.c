/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:10:49 by cjumelin          #+#    #+#             */
/*   Updated: 2017/01/04 13:05:41 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem;

	mem = b;
	if (len == 0)
		return (b);
	while (len != 0)
	{
		*mem = (unsigned char)c;
		mem++;
		len--;
	}
	return (b);
}
