# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 13:04:29 by jgarcia           #+#    #+#              #
#    Updated: 2022/08/11 17:10:36 by jgarcia          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME				= libftprintf.a

SOURCES				= ft_printf.c print_str.c print_n.c print_hex.c \
					  print_un.c print_p.c

OBJ					:= $(SOURCES:.c=.o)

CC					= gcc
RM					= rm -rf
CFLAGS				= -Wall -Wextra -Werror -c -g

all:				$(NAME)

$(NAME):			$(OBJ)
					@echo "linking\t\t$(NAME)"
					@ar -rcs $(NAME) $(OBJ)
					@echo "indexing\t$(NAME)"
					@ranlib $(NAME)

%.o:				%.c
					@echo "compilling\t$<"
					$(CC) $(CFLAGS) -o $@ $<

clean:
					$(RM) $(OBJ)

fclean:				clean
					$(RM) $(NAME)

re :				fclean $(NAME)

.PHONY:				all clean fclean re
