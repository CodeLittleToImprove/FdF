# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    older_Makefile_with_also_works                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbui-quo <tbui-quo@student.42wolfsburg.d>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 17:25:01 by tbui-quo          #+#    #+#              #
#    Updated: 2023/12/12 17:25:01 by tbui-quo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Target names
NAME = fdf

# Directories and source files
SRC = src/main.c

OBJ = $(SRC:.c=.o)
LIBS = -Llib/libft -lft \
	#-Llib/ft_printf -lftprintf


# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
debug: CFLAGS += -g

# Commands
all: $(NAME)
	@echo $(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)


$(NAME): $(OBJ)
	@make -C lib/libft
	#@make -C lib/ft_printf
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C lib/libft
	#@make clean -C lib/ft_printf
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/libft
	#@make fclean -C lib/ft_printf
	@rm -f $(NAME)

re: fclean all

debug: all

.PHONY: all clean fclean re