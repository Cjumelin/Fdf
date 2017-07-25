/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:43:06 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/23 04:52:37 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int j;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	else if (big[0] == '\0')
		return (NULL);
	while (big[i])
	{
		if (big[i] == little[0] && i < (int)len)
		{
			j = 0;
			while (little[j] && little[j] == big[i + j] && (i + j) < (int)len)
				j++;
			if (little[j] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
