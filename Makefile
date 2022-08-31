# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/05 14:56:42 by bfiguet           #+#    #+#              #
#    Updated: 2022/08/31 17:46:25 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/bash

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Iinc/
CFLAGS += -Ilibft/
CFLAGS += -Imlx_linux/
CFLAGS += -g3

RM = rm -rf
OBJ_DIR = obj/
LIBFT = -Llibft -lft
MLX_LINUX = -Lmlx_linux -lm -lmlx -lXext -lX11

SRCS = $(addsuffix .c, \
			$(addprefix src/,	\
			map \
			move \
			put \
			window \
			init \
			main \
			))	\

OBJS = $(SRCS:src/%.c=obj/%.o)

all: $(NAME)

obj/%.o:src/%.c Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -sC libft
	$(MAKE) -sC mlx_linux
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX_LINUX)

clean:
	$(MAKE) $@ -sC libft
	$(RM) $(OBJ_DIR)

fclean: clean
	$(MAKE) $@ -sC libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re norm
