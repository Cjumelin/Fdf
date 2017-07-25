/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:45:18 by cjumelin          #+#    #+#             */
/*   Updated: 2017/07/06 18:47:14 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfdf.h"

void		put_color_to_img(int x0, int y0, t_data *d)
{
	char	*tmp;
	int		i;

	i = (x0 * 4) + (y0 * d->s_l);
	tmp = d->data_addr + i;
	(*(unsigned int*)tmp) = d->color;
}

void		x_n_y_prime_(t_data *d)
{
	d->x1 = ((d->x0) + d->y0 + d->cst1) * d->sq;
	d->y1 = ((d->y0) - (d->map[d->y0][d->x0]
		+ (d->map[d->y0][d->x0] ? d->cst3 : 0)) + d->cst2) * d->sq;
	d->x2 = ((d->x0 + 1) + d->y0 + d->cst1) * d->sq;
	d->y2 = ((d->y0) - (d->map[d->y0][d->x0 + 1]
		+ (d->map[d->y0][d->x0 + 1] ? d->cst3 : 0)) + d->cst2) * d->sq;
}

void		x_n_y_prime__(t_data *d)
{
	d->x1 = ((d->x0) + d->y0 + d->cst1) * d->sq;
	d->y1 = ((d->y0) - (d->map[d->y0][d->x0]
		+ (d->map[d->y0][d->x0] ? d->cst3 : 0)) + d->cst2) * d->sq;
	d->x2 = (d->x0 + d->y0 + 1 + d->cst1) * d->sq;
	d->y2 = (d->y0 + 1 - (d->map[d->y0 + 1][d->x0]
		+ (d->map[d->y0 + 1][d->x0] ? d->cst3 : 0)) + d->cst2) * d->sq;
}

void		pre_bresenham(t_data *d, int c)
{
	c ? (x_n_y_prime_(d)) : x_n_y_prime__(d);
	if ((PX_IS_ON_IMG) && (PX_IS_ON_IMG_))
	{
		if (d->bresenham)
			bresenham(d);
		else
		{
			if (PX_IS_ON_IMG)
				put_color_to_img(d->x1, d->y1, d);
		}
	}
}

int			iso_projection(t_data *d)
{
	d->size_max_str = HEIGHT + (WIDTH);
	d->y0 = 0;
	d->x0 = 0;
	while (d->y0 <= d->y)
	{
		while (d->x0 <= d->x)
		{
			if (d->x0 < d->x)
				pre_bresenham(d, 1);
			if (d->y0 < d->y)
				pre_bresenham(d, 0);
			d->x0++;
		}
		d->x0 = 0;
		d->y0++;
	}
	return (0);
}
