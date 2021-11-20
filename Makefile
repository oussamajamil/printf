# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 09:56:28 by ojamil            #+#    #+#              #
#    Updated: 2021/11/20 13:24:29 by ojamil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEAD = ./include/ft_printf.h

SRC_DIR = src

OBJ_DIR = obj

SRC = ft_print_hexa.c\
	ft_putchar.c\
	ft_putnbr_unsigned.c\
	ft_putnbr.c\
	ft_putstr.c\
	ft_printf.c

OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))	
# $(addprefix src/,foo bar)



all : $(NAME) 

$(NAME) : $(OBJ) $(HEAD)
		ar rcs $(NAME) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEAD)
	mkdir -p obj
	$(CC) $(CFLAGS) -o $@ -c $<
		
clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)
		

re : fclean all
