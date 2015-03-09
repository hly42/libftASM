# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hly <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/04 15:57:17 by hly               #+#    #+#              #
#    Updated: 2015/02/17 21:13:38 by hly              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
CC = nasm

FLAG = -f macho64

INCLUDES = ./includes/

SRC = ft_bzero.s\
	  ft_strlen.s\
	  ft_strcat.s\
	  ft_isalpha.s\
	  ft_isdigit.s\
	  ft_isalnum.s\
	  ft_isascii.s\
	  ft_isprint.s\
	  ft_toupper.s\
	  ft_tolower.s\
	  ft_puts.s\
	  ft_memset.s\
	  ft_memcpy.s\
	  ft_strdup.s\
	  ft_cat.s

OBJ = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@(ar rc $@ $^)
	@(ranlib $@)
	@echo "\033[32m\"$(NAME)\" created !\033[0m"

%.o: %.s
	@echo "$@ created"
	@($(CC) $(FLAG) $^)

clean:
	@(rm -f $(OBJ))
	@echo "\033[31m$(NAME)'s object files deleted\033[0m"

fclean: clean
	@(rm -f $(NAME))
	@echo "\033[31m\"$(NAME)\" deleted\033[0m"

re: fclean all

main.o: main.c
	@(gcc -Wall -Werror -Wextra -L. -lfts -I$(INCLUDES) -c main.c)

test: main.o $(NAME)
	@(gcc -Wall -Werror -Wextra -L. -lfts -I$(INCLUDES) -o test main.o)
	@echo "\033[32m\"test\" created !\033[0m"

fcleantest: fclean
	@(rm -f main.o test)
	@echo "\033[31m\"test\" deleted\033[0m"
.PHONY: clean fclean all re
