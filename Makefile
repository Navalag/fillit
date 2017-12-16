# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalavan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/15 08:02:32 by agalavan          #+#    #+#              #
#    Updated: 2017/12/15 08:02:34 by agalavan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror -I. -c

SRCS = 	main.c\
		list_func.c\
		solve_algo.c\
		valid_func.c\
		move_func.c\
		print_func.c\

HEADER = fillit.h

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	gcc $(FLAGS) $(SRCS) $(HEADER)
	gcc $(OBJS) -o $(NAME)

%.o: %.c
	gcc $(FLAGS) $<

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
