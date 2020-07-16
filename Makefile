# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 14:38:04 by ivalenti          #+#    #+#              #
#    Updated: 2020/02/22 22:05:01 by hbespin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

SOURCES = utils2.c main.c utils.c fillit_read.c fillit_lst.c fillit_solver.c create_figure.c

CFLAGS = -Wall -Wextra -Werror

OBJECTS = $(SOURCES:.c=.o)

STL = libft/

all: $(NAME)

$(NAME): $(OBJECTS)
	make -C $(STL)
	$(CC) $(OBJECTS) -I fillit.h -L. $(STL)/libft.a -o $(NAME)
.c.o:
	$(CC) $(CFLAGS) -I fillit.h -c $< -o $@

clean:
	make -C $(STL) clean
	/bin/rm -f $(OBJECTS)
fclean: clean
	/bin/rm -f $(NAME) $(STL)libft.a

re: fclean all
