NAME = libftfdf.a

HEADER = libftfdf.h

SRC = parssing.c \
fdf.c \
iso_projection.c \
bresenham.c \
event_hook.c \
ft_virgule.c

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

MLX = -g -I -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit

FS = -g -fsanitize=address

all : $(NAME)

mall : memory

memory :
	@gcc $(FS) -c $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all_exe :
	@gcc -c $(FLAG) $(MLX) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc $(FLAG) $(MLX) -L . -lftfdf && ./a.out

fall_exe :
	@gcc $(FS) $(FLAG) $(MLX) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc $(FLAG) $(FS) $(MLX) -L . -lftfdf && ./a.out

$(NAME):
	@gcc -c $(FLAG) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	
	@echo "Done."

clean :
	@rm -f $(OBJ)
	@echo "Done."

fclean : clean
	@rm -f $(NAME)
	@echo "Done."

re : fclean all

fre : fclean mall

ere : fclean all_exe
fere : fclean fall_exe
