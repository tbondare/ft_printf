/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:02:42 by tbondare          #+#    #+#             */
/*   Updated: 2018/06/01 18:58:40 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_str(char *str)
{
	write(1, str, ft_strlen(str));
	free(str);
}

int printing_args(t_flgs_types *prm)
{
	char *str;
	int total_strlen;
	t_flgs_types *lst;

	total_strlen = 0;
	lst = prm;
	while (lst)
	{
		if (check_flg(lst->types, TP_d | TP_i | TP_D | TP_u | TP_U))
			str = itoa_printf(lst);
		else if (check_flg(lst->types, TP_o | TP_O | TP_x | TP_X | TP_b))
			str = itoa_printf_oO_xX_b(lst);
		else if (check_flg(lst->types, TP_a | TP_A | TP_e | TP_E | TP_f 
					| TP_F | TP_g | TP_G))
			str = itoa_aA_eE_fF_gG(lst);
		else if (check_flg(lst->types, TP_C | TP_S) ||
				(check_flg(lst->types, TP_c | TP_s) &&
						check_flg(lst->md_lengh, LN_l)))
			str = print_unicode(lst);
		else if (check_flg(lst->types, TP_p))
			str = pointer(lst);
		else
			str = lst->str_out;
		total_strlen = total_strlen + ft_strlen(str);
		print_str(str);
		lst = lst->next;
	}
	return (total_strlen);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	t_flgs_types *prm;
	int total_strlen;

	va_start(args, format);
	if(fill_struct(&prm, format) == 0)
		return(-1);
	determine_args(prm, args);
	total_strlen = printing_args(prm);
	return (total_strlen);
}
