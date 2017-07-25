/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:45:28 by cjumelin          #+#    #+#             */
/*   Updated: 2017/01/12 23:18:36 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*mem;
	int		i;

	i = 0;
	if (!(mem = (char *)malloc(sizeof(char) * size)))
		exit(0);
	ft_bzero(mem, size);
	mem[i] = 0;
	return ((void *)mem);
}
