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
SRC = src/main.c

OBJ = $(SRC:.c=.o)
LIBS = -Llib/libft -lft \
	-Llib/mlx_linux -lmlx_Linux $(shell pkg-config --libs x11 xext)

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
debug: CFLAGS += -g

# ANSI escape codes
BLUE = \033[0;34m
RESET = \033[0m

# Commands
all: $(NAME)

$(NAME): $(OBJ)
	@make -C lib/libft
	@echo "$(BLUE)$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C lib/libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	@rm -f $(NAME)

re: fclean all

run:
	@make re
	@make clean
	@./$(NAME)
debug: all

.PHONY: all clean fclean re
