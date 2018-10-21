# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjumelin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/10 21:14:31 by cjumelin          #+#    #+#              #
#    Updated: 2016/12/13 02:53:21 by smoreno          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fdf.c \
bresenham.c \
event_hook.c \
ft_virgule.c \
iso_projection.c \
parssing.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
	make -C ./libft/.
	gcc $(FLAG) $(OBJ) -L ./libft -lft -L ./minilibx_macos -l mlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	gcc $(FLAGS) -c $<
clean :
	make clean -C ./libft/.
	rm -f $(OBJ)

fclean : clean
	make fclean -C ./libft/.
	rm -f $(NAME)

re : fclean all
