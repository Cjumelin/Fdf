/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/13 20:05:50 by cjumelin          #+#    #+#             */
/*   Updated: 2017/06/14 17:27:29 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfdf.h"

int		expose_hook(t_data *d)
{
	iso_projection(d);
	if (-1 == (mlx_destroy_image(d->mlx_ptr, d->img_ptr)))
		return (error(7));
	d->img_ptr = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->data_addr = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->s_l,
		&d->endian);
	iso_projection(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr,
	d->width, d->height);
	return (0);
}

void	key_hook_event_(int key, t_data *d)
{
	if (key == 53)
	{
		free(d);
		exit(0);
	}
	if (key == 47)
		d->sq++;
	if (key == 44 && d->sq != 1)
		d->sq--;
	if (key == 8)
		d->color = 0x00ff0000;
	if (key == 9)
		d->color = 0x0000ff00;
	if (key == 11)
		d->color = 0x000000ff;
}

int		key_hook_event(int key, t_data *d)
{
	key_hook_event_(key, d);
	if (key == 124)
		d->cst1++;
	if (key == 125)
		d->cst2++;
	if (key == 123)
		d->cst1--;
	if (key == 126)
		d->cst2--;
	if (key == 15)
		ft_init(d, 0);
	if (key == 6)
		d->cst3++;
	if (key == 7)
		d->cst3--;
	if (key == 3)
		d->bresenham += (d->bresenham ? -1 : 1);
	expose_hook(d);
	return (0);
}

int		key_hook(int key, t_data *d)
{
	if (SELECTED_HOOK)
		key_hook_event(key, d);
	return (0);
}

int		mlx_hook_(t_data *d)
{
	mlx_hook(d->win_ptr, 2, 0, key_hook, d);
	return (1);
}
