/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:43:52 by cjumelin          #+#    #+#             */
/*   Updated: 2017/02/22 15:13:29 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*strg;
	size_t	i;

	i = 0;
	if (!(strg = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		strg[i] = '\0';
		i++;
	}
	strg[i] = '\0';
	return (strg);
}
