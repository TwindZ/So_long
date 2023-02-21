NAME	:= So_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
LIBFT	:= ./srcs/libft/libft.a
SRCS	:=	./srcs/main.c			\
			./srcs/ft_parsing.c 	\
			./srcs/ft_parsing2.c	\
			./srcs/ft_render.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS)
	$(MAKE) -C ./srcs/libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBS) $(LIBFT) -o $(NAME)
	make clean
	
debug:  $(NAME) $(SRC)
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