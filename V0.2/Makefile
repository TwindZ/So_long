NAME	:= So_long
CFLAGS	:= -g -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
LIBFT	:= ./srcs/libft/libft.a
SRCS	:=	./srcs/main.c			\
			./srcs/validate.c \
			./srcs/map_data.c	\
			./srcs/so_long_utils.c	\
			./srcs/game.c			\
			./srcs/image_utils.c	\
			./srcs/move.c			\
			./srcs/enemy.c			\
			./srcs/animation.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

all: $(NAME)

run:
	./So_long ./maps/map02.ber

$(NAME): $(OBJS)
	$(MAKE) -C ./srcs/libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) $(LIBFT) -o $(NAME)
	make clean
	
debug: $(NAME) $(SRC)
	$(CC) -g $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	make clean
	
clean:
	$(MAKE) clean -C ./srcs/libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./srcs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean debug comp re