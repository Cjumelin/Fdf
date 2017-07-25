/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:45:18 by cjumelin          #+#    #+#             */
/*   Updated: 2017/05/30 19:42:17 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfdf.h"

long long		llabsolute(long long abs)
{
	return ((abs < 0) ? abs * -1 : abs);
}

void			swp(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int				bresenham(t_data *d)
{
	d->dx = llabsolute(d->x2 - d->x1);
	d->dy = llabsolute(d->y2 - d->y1);
	d->sx = d->x1 < d->x2 ? 1 : -1;
	d->sy = d->y1 < d->y2 ? 1 : -1;
	d->err = (d->dx > d->dy ? d->dx : -d->dy) / 2;
	if (PX_IS_ON_IMG)
		put_color_to_img(d->x1, d->y1, d);
	while (!(d->x1 == d->x2 && d->y1 == d->y2))
	{
		d->e2 = d->err;
		if (PX_IS_ON_IMG)
			put_color_to_img(d->x1, d->y1, d);
		if (d->e2 > -d->dx)
		{
			d->err -= d->dy;
			d->x1 += d->sx;
		}
		if (d->e2 < d->dy)
		{
			d->err += d->dx;
			d->y1 += d->sy;
		}
	}
	return (0);
}
