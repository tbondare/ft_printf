# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbondare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 17:27:01 by tbondare          #+#    #+#              #
#    Updated: 2018/08/04 18:58:41 by tbondare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

SRC = print_cca_ssa.c ft_determine_flgs.c ft_printf.c fns_for_fl.c lib_printf.c fts_f_output_dgt.c ft_outp_float.c fill_struct.c init_arr.c ft_cnt_i_d_u_ua_c.c print_unicode.c determ_types.c ft_print_pct.c ft_for_print_args.c ft_with_flags.c cnt_o_x_b.c ft_for_pr_cca_ssa.c ft_f_prn_unicd.c if_flgs_o_x_b.c itoa_a_e_f_g.c fns_for_ddgt.c ft_determ_argc.c itoa_printf_o_x_b.c itoa_printf.c

OBJ	= $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		make -C $(LIBFT)
		ranlib $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
		mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
		gcc -Wall -Werror -Wextra -c $< -o $@ -I $(INC_DIR)
clean:
		make clean -C $(LIBFT)
		rm -f $(OBJ)

fclean: clean
		make fclean -C $(LIBFT)
		rm -f $(NAME)
		rm -rf $(OBJ_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
