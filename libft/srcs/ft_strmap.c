/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:07:27 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/27 08:39:56 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int			i;
	char		*dst;

	i = 0;
	if (s && f)
	{
		if (!(dst = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[i])
		{
			dst[i] = f(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
