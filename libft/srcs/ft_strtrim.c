/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 20:11:30 by cjumelin          #+#    #+#             */
/*   Updated: 2016/11/27 08:42:54 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trim;
	int		deb;
	int		fin;

	deb = 0;
	if (!s)
		return (NULL);
	fin = ft_strlen(s);
	while (s[deb] == ' ' || s[deb] == '\t' || s[deb] == '\n')
		deb++;
	if (deb == fin)
		return (trim = ft_strnew(1));
	while (deb != fin && (s[fin - 1] == ' ' || s[fin - 1] == '\t'
				|| s[fin - 1] == '\n'))
		fin--;
	if (!(trim = ft_strsub(s, deb, (fin - deb))))
		return (NULL);
	return (trim);
}
