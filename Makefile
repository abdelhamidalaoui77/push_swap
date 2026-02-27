# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alamrani <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/18 11:58:31 by alamrani          #+#    #+#              #
#    Updated: 2026/02/18 12:05:10 by alamrani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
NAME = push_swap
CFLAGS = -Wall -Wextra -Werror
SRC = main.c ft_split.c ft_strjoin.c parsing.c parsing_utils.c stack.c \
	  stack_utils.c oprs_swap.c oprs_push.c oprs_rotate.c oprs_reverse_rotate.c \
	  sort.c radix_sort.c
OBJ = $(SRC:.c=.o)
HEADER = push_swap.h

all: $(NAME) 

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean