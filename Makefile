# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbondare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 17:27:01 by tbondare          #+#    #+#              #
#    Updated: 2018/06/19 20:56:59 by tbondare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ./*.c

LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a

OBJ = ./*.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	make -C $(LIBFT)
	cp $(LIBFTA) $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
