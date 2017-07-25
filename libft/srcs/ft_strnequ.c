/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:07:08 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/27 08:40:55 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	while (s1[i] == s2[i] && n > 0 && s1[i] && s2[i])
	{
		i++;
		n--;
	}
	if (n == 0 || s1[i] == s2[i])
		return (1);
	return (0);
}
