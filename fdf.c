/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:45:18 by cjumelin          #+#    #+#             */
/*   Updated: 2017/06/28 17:49:55 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfdf.h"

int		error(char i)
{
	if (i == 0)
		ft_putstr("Usage : ./fdf map\n");
	if (i == 1)
		ft_putstr("Open Error : returned value --> {-1}\n");
	if (i == 2)
		ft_putstr("Malloc Error : Fail to alloc memory\n");
	if (i == 3)
		ft_putstr("Close Error : returned value --> {-1}\n");
	if (i == 4)
		ft_putstr("Invalid map\n");
	if (i == 5)
		ft_putstr("Invalid map (Max height is 25 000)\n");
	if (i == 6)
		ft_putstr("Invalid map (Max value of x or y is 25 000)\n");
	if (i == 7)
		ft_putstr("HOPE NOP\n");
	exit(-1);
	return (-1);
}

int		ft_init(t_data *d, int i)
{
	i = 0;
	d->sq = 1;
	d->x0 = 0;
	d->y0 = 0;
	d->cst1 = 1;
	d->cst2 = 1;
	d->cst3 = 0;
	d->width = 50;
	d->height = 50;
	d->color = 0x0000ff00;
	d->bresenham = 1;
	if (i)
	{
		d->y = 0;
		d->a = 0;
		d->s = NULL;
	}
	return (0);
}

void	add_string(t_data *d)
{
	mlx_string_put(d->mlx_ptr, d->win_ptr, 10, 5, 0x0000ff00, TEXTE);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 600, 5, 0x0000ff00, TEXTE_);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1100, 5, 0x0000ff00, TEXTE__);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 1600, 5, 0x0000ff00, _TEXTE);
	mlx_string_put(d->mlx_ptr, d->win_ptr, 20, 1165, 0x00ffffff, "COLOR   ==>");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 200, 1165, 0x00ff0000, "C : ROUGE");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 400, 1165, 0x0000ff00, "V : VERT");
	mlx_string_put(d->mlx_ptr, d->win_ptr, 600, 1165, 0x000000ff, "B : BLEU");
}

void	fdf(t_data *d)
{
	if (NULL == (d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH + 100,
	HEIGHT + 100, "fdf")))
		error(7);
	if (NULL == (d->img_ptr = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT)))
		error(7);
	d->data_addr = mlx_get_data_addr(d->img_ptr, &d->bpp, &d->s_l, &d->endian);
	ft_init(d, 1);
	iso_projection(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, d->width,
		d->height);
	add_string(d);
}

int		main(int argc, char const *argv[])
{
	t_data	*d;

	if (argc != 2)
		return (error(0));
	if (!(d = (t_data *)malloc(sizeof(t_data))))
		return (error(2));
	if (ft_strstr((d->argv = (char *)argv[1]), "dev/random"))
		return (error(7));
	if (-1 == (d->fd = open(argv[1], O_RDONLY)))
		return (error(1));
	if (parssing(d) == -1)
		return (-1);
	if (NULL == (d->mlx_ptr = mlx_init()))
		return (error(7));
	fdf(d);
	if (mlx_hook_(d) == -1)
		return (-1);
	mlx_loop(d->mlx_ptr);
	while ((1))
		;
	return (1);
}
