# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fself <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/28 17:21:42 by fself             #+#    #+#              #
#    Updated: 2019/11/28 17:21:49 by fself            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
LIB = ./libft/libft.a
HEADERS = $(wildcard *.h)
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	make -C libft/ all
	clang -o fillit $(OBJS) $(LIB) $(FLAGS)

build: $(SRCS) $(HEADERS)
	clang $(FLAGS) -c $(SRCS)

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
