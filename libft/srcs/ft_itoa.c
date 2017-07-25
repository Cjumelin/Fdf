/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 15:53:32 by cjumelin          #+#    #+#             */
/*   Updated: 2017/01/26 17:34:24 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <stdio.h>

static long		ft_abs(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

char			*ft_itoa(int n)
{
	t_point p;

	p.signe = 0;
	(n < 0) ? p.signe = 1 : p.signe;
	p.size = 1;
	p.nbr = ft_abs(n);
	while (p.nbr >= 10)
	{
		p.nbr = p.nbr / 10;
		p.size++;
	}
	if (!(p.dst = ft_strnew(p.size + p.signe)))
		return (NULL);
	if (p.signe == 1)
		p.dst[0] = '-';
	p.nbr = ft_abs(n);
	while (p.size--)
	{
		p.dst[p.size + p.signe] = p.nbr % 10 + 48;
		p.nbr = p.nbr / 10;
	}
	return (p.dst);
}
