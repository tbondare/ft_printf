# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbondare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/29 17:27:01 by tbondare          #+#    #+#              #
#    Updated: 2018/08/04 17:45:07 by tbondare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = ./print_cca_ssa.c ./ft_determine_flgs.c ./ft_printf.c ./fns_for_fl.c ./lib_printf.c ./fts_f_output_dgt.c ./ft_outp_float.c ./fill_struct.c ./init_arr.c ./ft_cnt_i_d_u_ua_c.c ./print_unicode.c ./determ_types.c ./ft_print_pct.c ./ft_for_print_args.c ./ft_with_flags.c ./cnt_o_x_b.c ./ft_for_pr_cca_ssa.c ./ft_f_prn_unicd.c ./if_flgs_o_x_b.c ./itoa_a_e_f_g.c ./fns_for_ddgt.c ./ft_determ_argc.c ./itoa_printf_o_x_b.c ./itoa_printf.c

LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a

OBJ = ./print_cca_ssa.o ./ft_determine_flgs.o ./ft_printf.o ./fns_for_fl.o ./lib_printf.o ./fts_f_output_dgt.o ./ft_outp_float.o ./fill_struct.o ./init_arr.o ./ft_cnt_i_d_u_ua_c.o ./print_unicode.o ./determ_types.o ./ft_print_pct.o ./ft_for_print_args.o ./ft_with_flags.o ./cnt_o_x_b.o ./ft_for_pr_cca_ssa.o ./ft_f_prn_unicd.o ./if_flgs_o_x_b.o ./itoa_a_e_f_g.o ./fns_for_ddgt.o ./ft_determ_argc.o ./itoa_printf_o_x_b.o ./itoa_printf.o

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
