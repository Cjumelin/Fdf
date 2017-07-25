/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:42:15 by cjumelin          #+#    #+#             */
/*   Updated: 2017/02/22 14:53:10 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>

static	int		ft_wordsize(char *s, int i, char c)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		size++;
	}
	return (size);
}

static	char	**ft_putword(char *s, char c, char **dst, int size)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (s[i] && size > 0)
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			dst[a] = ft_strnew(ft_wordsize(s, i, c));
			dst[a] = ft_strncpy(dst[a], s + i, ft_wordsize(s, i, c));
			size--;
			dst[a][ft_wordsize(s, i, c)] = '\0';
			i += ft_wordsize(s, i, c) - 1;
			a++;
		}
		i++;
	}
	dst[a] = NULL;
	return (dst);
}

static	int		ft_nbrmot(char const *s, char c)
{
	int i;
	int mot;

	mot = 0;
	i = 0;
	if (s[0] != c)
		mot++;
	while (s[i] == c)
		i++;
	if (i == 0)
		i++;
	while (s[i])
	{
		if (s[i - 1] == c && s[i] != c && s[i] != '\0')
			mot++;
		i++;
	}
	return (mot);
}

char			**ft_strsplit(char const *s, char c)
{
	int		mot;
	char	**dst;

	if (!s)
		return (NULL);
	mot = ft_nbrmot(s, c);
	if (!(dst = (char**)malloc(sizeof(char*) * (mot + 1))))
		return (NULL);
	if (mot == 0)
	{
		dst[0] = NULL;
		return (dst);
	}
	return (ft_putword((char *)s, c, dst, mot));
}
