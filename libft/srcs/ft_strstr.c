/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:22:37 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/18 21:25:36 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;

	i = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] && little[j] == big[i + j])
				j++;
			if (little[j] == '\0')
				return ((char*)big + i);
		}
		i++;
	}
	return (NULL);
}
