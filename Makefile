# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agundry <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/10 17:16:55 by agundry           #+#    #+#              #
#    Updated: 2017/02/14 17:00:04 by agundry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	get_next_line

CC = 	gcc

CFLAGS =	-Wall -Wextra -Werror -g

SRC =	shit_next_line.c			\
		test.c

OBJ =	$(patsubst %.c,%.o,$(SRC))

$(NAME) :	
			make -C libft/ fclean && make -C libft/
			$(CC) $(CFLAGS) -c $(SRC) -I libft/ get_next_line.h
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

all	:	$(NAME)

clean	:
	make -C libft/ fclean
	/bin/rm -f $(OBJ)

fclean	:	clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re	:	fclean all
