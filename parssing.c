/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 15:45:18 by cjumelin          #+#    #+#             */
/*   Updated: 2017/06/28 17:54:36 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftfdf.h"

int		ft_number_of_number(char *line, t_data *d)
{
	int		n_o_n;

	n_o_n = 0;
	if (!line || !(*line))
		return (0);
	while (*line != '\0')
	{
		if (*line != '\0' && *line >= '0' && *line <= '9')
		{
			while (*line != '\0' && *line >= '0' && *line <= '9' && *line)
				line++;
			if (*line == ',')
				while (*line && *line != ' ')
					line++;
			n_o_n++;
			if (d->a > d->val_max_per_line)
				d->val_max_per_line = d->a;
		}
		else
			line++;
	}
	return (n_o_n);
}

int		filler_tab(t_data *d, int i, int y, int x)
{
	d->x = d->val_max_per_line;
	while (y < d->y && !(i &= 0) && !(x = 0))
	{
		if (!(d->map[y] = (long *)malloc(sizeof(long) * (d->x))))
			return (error(2));
		while (x < d->val_max_per_line)
		{
			while ((d->s[y])[i] == ' ')
				i++;
			if (((d->map[y])[x] = ft_atoi((d->s[y]) + i)) > 25000)
				return (error(5));
			if ((d->s[y])[i] == '-')
				i++;
			while ((d->s[y])[i] >= '0' && (d->s[y])[i] <= '9')
				i++;
			if ((d->s[y])[i] == ',')
				i = ft_virgule((d->s[y]), ++i);
			x++;
		}
		while (x < d->val_max_per_line)
			d->map[y][x++] = 0;
		y++;
	}
	return (0);
}

int		parssing__(t_data *d)
{
	char	*nl;
	int		y;
	int		nbr;

	y = 0;
	if (NULL == (d->s = (char **)malloc(sizeof(char *) * (d->y + 1))))
		error(2);
	if (-1 == (d->fd = open((const char *)d->argv, O_RDONLY)))
		return (error(1));
	while (get_next_line(d->fd, &(nl)) > 0)
	{
		d->s[y] = ft_strdup(nl);
		if ((nbr = ft_number_of_number(nl, d)) > d->val_max_per_line)
			d->val_max_per_line = nbr;
		free(nl);
		y++;
	}
	free(nl);
	if (close(d->fd) == -1)
		return (error(3));
	d->map[d->y] = 0;
	d->a = 0;
	filler_tab(d, 0, 0, 0);
	return (0);
}

void	parssing_(t_data *d, int i)
{
	char	*nl;

	while (get_next_line(d->fd, &(nl)) > 0 && !(i = 0))
	{
		d->y++;
		free(nl);
	}
	free(nl);
	if (!(d->max_per_line = (int *)malloc(sizeof(int) * (d->y + 1))))
		error(2);
	if (!(d->map = (long **)malloc(sizeof(long *) * (d->y + 1))))
		error(2);
}

int		parssing(t_data *d)
{
	int		val_max_per_line;

	d->y = 0;
	val_max_per_line = 0;
	parssing_(d, 0);
	if (close(d->fd) == -1)
		return (error(3));
	parssing__(d);
	d->y--;
	d->x--;
	if (d->y < 2)
		return (error(4));
	if (d->val_max_per_line < 2)
		return (error(4));
	if (d->y > 25000 || d->x > 25000)
		return (error(6));
	return (1);
}
