# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/22 17:57:00 by jgarcia           #+#    #+#              #
#    Updated: 2022/08/27 12:49:17 by jgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CURRENT_DIR = $(shell pwd)
LIBPRINTF = $(CURRENT_DIR)/libftprintf/libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -c

INC = -Iminilibx-linux/
LINK = -Lminilibx-linux -lmlx_Linux -lXext -lX11 -lm -lz

SRC = main.c graphic.c init.c mandelbrot_escape.c controls.c julia_escape.c utils.c burning_escape.c mem_clean.c color.c animations.c utils2.c arguments.c

OBJ = $(SRC:.c=.o)

RM = rm -f

all : $(NAME)

$(NAME): $(OBJ) $(CURRENT_DIR)/minilibx-linux/libmlx_Linux.a $(LIBPRINTF)
	$(CC) $(OBJ) $(LIBPRINTF) $(LINK) -o $(NAME)

$(LIBPRINTF):
	make -C $(CURRENT_DIR)/libftprintf

%.o: %.c
	$(CC) $(CFLAGS) $(INC) $< -o $@

$(CURRENT_DIR)/minilibx-linux/libmlx_Linux.a:
	make -C minilibx-linux

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: clean fclean all re
