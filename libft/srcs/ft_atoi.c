/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:03:50 by cjumelin          #+#    #+#             */
/*   Updated: 2017/02/17 17:00:26 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long			nbr;
	long			i;
	unsigned int	ind;

	ind = 0;
	nbr = 0;
	i = 1;
	while ((str[ind] >= 9 && str[ind] <= 13 && str[ind] != '\200')
			|| str[ind] == 32)
		ind++;
	(str[ind] == '-') ? (i = -1) : nbr;
	(str[ind] == '-' || str[ind] == '+') ? ind++ : ind;
	while (str[ind] <= '9' && str[ind] >= '0')
	{
		nbr += (str[ind] - '0');
		nbr *= 10;
		ind++;
	}
	nbr /= 10;
	return (nbr * i);
}
