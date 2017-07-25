/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:00:46 by cjumelin          #+#    #+#             */
/*   Updated: 2017/06/28 17:56:39 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	char	*tmp;

	if (s1 && s2)
	{
		if (!(join = (char*)malloc(sizeof(char)
						* (ft_strlen(s1) + ft_strlen(s2) + 1))))
			return (NULL);
		tmp = join;
		while (*s1)
		{
			*join = *s1;
			s1++;
			join++;
		}
		while (*s2)
		{
			*join = *s2;
			s2++;
			join++;
		}
		*join = '\0';
		return (tmp);
	}
	return (s1 ? ft_strdup(s1) : ft_strdup(s2));
}
