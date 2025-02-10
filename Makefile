# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctoujana <ctoujana@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 10:23:53 by ctoujana          #+#    #+#              #
#    Updated: 2025/02/10 15:39:42 by ctoujana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = fractol.c fractol_utils1.c close.c hooks.c mandelbrot.c julia.c parse.c ft_atod.c

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)
		
$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -lmlx -lX11 -lXext -o $@

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all