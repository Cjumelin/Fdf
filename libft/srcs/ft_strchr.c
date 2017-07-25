/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 12:15:38 by cjumelin          #+#    #+#             */
/*   Updated: 2017/03/12 20:04:16 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char*)s;
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
