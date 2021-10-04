NAME = 	so_long
PATH_FILES = ./srcs/
PATH_OBJS = ./objs/
LIBFT =	libft/libft.a
FLAGS =	-Wall -Wextra -Werror
SRC =	srcs/map_controler.c \
		srcs/utils.c \
		srcs/map.c \
		srcs/drawing.c \
		srcs/so_long.c \
		srcs/hooks.c \
		srcs/param.c \
		srcs/move.c
		
OBJS = $(SRC:.c=.o)

LIB = -L ./libft -L ./minilibx-linux -lmlx -lXext -lX11

all : $(NAME)

$(NAME):	$(OBJS)
		make -C ./libft
		make -C ./minilibx-linux
		clang -g3 -fsanitize=address $(FLAGS) $(OBJS) $(LIB) $(LIBFT) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $< -o $@

clean:
		@rm -rf $(OBJS)
		make clean -C ./libft
		@echo ".o limpo"

fclean: clean
		@rm -rf $(NAME)
		make fclean -C ./libft
		make clean -C ./minilibx-linux


re: fclean all