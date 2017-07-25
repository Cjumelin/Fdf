/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfdf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 17:45:06 by cjumelin          #+#    #+#             */
/*   Updated: 2017/06/29 17:45:09 by cjumelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTFDF_H
# define LIBFTFDF_H
# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# define WIDTH 2000
# define HEIGHT 1100
# define TEXTE " COMMANDS ==  -> : SHIFTING RIGHT  |  <- : SHIFTING LEFT  |"
# define TEXTE_ "  up arrow : MOVE UP  |  down arrow : MOVE DOWN  |"
# define TEXTE__ "  r : REFRESH  |  . : ZOOM IN  |  / : ZOOM OUT  |"
# define _TEXTE "  z : EXPANDE Z  |  x : REDUCE Z  |  ESC = EXIT"
# define A key == 6 || key == 7 || key == 8 || key == 9 || key == 11
# define B key == 15 || key == 53 || key == 47 || key == 44 || key == 123
# define C key == 124 || key == 125 || key == 126 || key == 3
# define SELECTED_HOOK (A || B || C)
# define D d->y1 + d->x1 < d->size_max_str && d->x1 < WIDTH
# define E d->y1 < HEIGHT && d->x1 * 4 > 0 && d->y1 * d->s_l > 0
# define PX_IS_ON_IMG (D && E)
# define F d->y2 + d->x2 < d->size_max_str && d->x2 < WIDTH
# define G d->y2 < HEIGHT && d->x2 * 4 > 0 && d->y2 * d->s_l > 0
# define PX_IS_ON_IMG_ (F && G)

typedef struct		s_data
{
	char			*data_addr;
	int				size_max_str;
	void			*win_ptr;
	void			*mlx_ptr;
	void			*img_ptr;
	int				endian;
	int				s_l;
	int				bpp;
	int				fd;
	char			*argv;
	long			**map;
	char			*tmp;
	char			**s;
	int				a;
	int				*max_per_line;
	int				val_max_per_line;
	long			x;
	long			y;
	char			bresenham;
	long			x0;
	long			y0;
	long			x1;
	long			y1;
	long			x2;
	long			y2;
	long			sq;
	long			dx;
	long			dy;
	long			sx;
	long			err;
	long			e2;
	long			sy;
	long			cst1;
	long			cst2;
	long			cst3;
	long			width;
	long			height;
	unsigned int	color;
}					t_data;

int					error(char i);
int					ft_init(t_data *d, int i);
int					iso_projection(t_data *d);
void				put_color_to_img(int x0, int y0, t_data *d);
int					parssing(t_data *d);
int					bresenham(t_data *d);
int					mlx_hook_(t_data *d);
int					ft_virgule(char *s, int i);

#endif
