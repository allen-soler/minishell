# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jallen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/24 13:48:04 by jallen            #+#    #+#              #
#    Updated: 2019/02/11 13:55:34 by jallen           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Werror -Wextra 

NAME = minishell

DIR_S = src

LIBFT = libftprintf

DIR_O = temporary

DIR_H = includes

SOURCES = main.c\
		  ft_binaries.c\
		  ft_tools.c\
		  ft_cd.c\
		  ft_echo.c\
		  ft_env.c\
		  ft_builtins.c\

SRCS = $(addprefix $(DIR_S)/, $(SOURCES))

OBJS = $(addprefix $(DIR_O)/, $(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)/libftprintf.a -I $(DIR_H)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	$(CC) $(FLAGS) -I $(DIR_H) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rm -rf $(DIR_O)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all
