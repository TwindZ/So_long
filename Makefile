NAME	:= So_long
CFLAGS	:= -Wextra -Wall -Werror 
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -lglfw -L "/Users/$(USER)/.brew/opt/glfw/lib/"
LIBFT	:= ./srcs/libft/libft.a
SRCS	:=	./srcs/main.c

OBJS = $(SRC:%.c=%.o)

CC = gcc

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(MAKE) -C ./srcs/libft
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) -o $(NAME)
	make clean
	./So_long

debug:  $(NAME) $(SRC)
	$(CC) -g $(SRC) main.c
	make clean
	lldb a.out
	
clean:
	$(MAKE) clean -C ./srcs/libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./srcs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean debug comp re