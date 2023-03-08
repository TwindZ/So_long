NAME	:= So_long
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
LIBFT	:= ./srcs/libft/libft.a
SRC	:=		./srcs/main.c			\
			./srcs/validate.c 		\
			./srcs/map_data.c		\
			./srcs/so_long_utils.c	\
			./srcs/game.c			\
			./srcs/image_utils.c	\
			./srcs/move.c			\
			./srcs/enemy.c			\
			./srcs/animation.c

OBJS_DIR = objs/
OBJS = $(SRC:%.c=%.o)
OBJS := $(OBJS:./srcs/%=$(OBJS_DIR)%)

CC = gcc

all: mlx $(NAME) 

mlx: dep
	(cd ./MLX42/ && cmake -B build)
	make -C ./MLX42/build/

dep:
	brew install glfw
	brew install cmake

$(NAME): $(OBJS)
	$(MAKE) -C ./srcs/libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)%.o: ./srcs/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	$(MAKE) clean -C ./srcs/libft
	$(MAKE) clean -C ./MLX42/build
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C ./srcs/libft
	rm -rf ./MLX42/build
	rm -f $(NAME)

bonus: all

re: fclean all

.PHONY: all clean fclean bonus re