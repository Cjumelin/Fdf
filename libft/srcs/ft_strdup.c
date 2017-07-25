/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:07:39 by cjumelin          #+#    #+#             */
/*   Updated: 2017/06/28 17:56:02 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dup;

	dup = (char*)ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	ft_strcpy(dup, s);
	return (dup);
}
