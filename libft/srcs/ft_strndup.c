/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 16:24:30 by cjumelin          #+#    #+#             */
/*   Updated: 2017/06/28 17:56:18 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, int n)
{
	char	*dup;
	int		i;

	i = 0;
	if (!(dup = ft_strnew(n)))
		return (NULL);
	if (!s)
		return (ft_memset(dup, '\0', 1));
	while (n && *s)
	{
		*dup = *s;
		dup++;
		s++;
		n--;
	}
	*dup = '\0';
	while (n > 0)
	{
		*dup = 0;
		dup++;
		n--;
	}
	return (dup);
}
