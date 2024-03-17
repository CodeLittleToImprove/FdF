# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 14:25:15 by tbui-quo          #+#    #+#              #
#    Updated: 2023/12/15 14:25:15 by tbui-quo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target names
NAME = fdf

# Directories and source files
SRC = src/main.c \
src/read_file.c \
src/draw.c \
src/utils.c \
src/keys_handler.c \
src/set_param.c \
src/help_menu.c

OBJ = $(SRC:.c=.o)
LIBS = -Llib/libft -lft \
	-Llib/ft_printf -lftprintf \
	-Llib/mlx_linux -lmlx_Linux $(shell pkg-config --libs x11 xext)

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
debug: CFLAGS += -g

# ANSI escape codes
BLUE = \033[0;34m
RESET = \033[0m

# Commands
all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/libft
	@make -C lib/ft_printf
	@make -C lib/mlx_linux
	@echo "$(BLUE)$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test: CFLAGS := -g #Only g flag for valgrind memoryleak test
test: $(OBJ)
	@make -C lib/libft
	@make -C lib/ft_printf
	@make -C lib/mlx_linux
	@echo "$(BLUE)$(CC) -o $(NAME) $(OBJ) $(LIBS)$(RESET)"
	@$(CC) -o $(NAME) $(OBJ) $(LIBS)


clean:
	@make clean -C lib/libft
	@make clean -C lib/ft_printf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	@make fclean -C lib/ft_printf
	@rm -f $(NAME)

re: fclean all

run:
	@make re
	@make clean
	@./$(NAME)

debug: all

.PHONY: all clean fclean re
