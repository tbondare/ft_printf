/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:02:42 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/25 17:24:54 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	free(str);
}

int printing_args(t_flgs_types *prm)
{
	char *str;
	int cnt;
	t_flgs_types *lst;

	cnt = 0;
	lst = prm;
	while (lst)
	{
		if (check_flg(lst->types, TP_d | TP_i | TP_D | TP_u | TP_U) 
				|| (check_flg(lst->types, TP_c)
					&& check_flg(lst->md_lengh, LN_l)))
		{
			str = itoa_printf(lst);
			print_str(str);
		}
		else if (check_flg(lst->types, TP_o | TP_O | TP_x | TP_X | TP_b))
		{
			str = itoa_printf_oO_xX_b(lst);
			print_str(str);
		}
		else if (check_flg(lst->types, TP_a | TP_A | TP_e | TP_E | TP_f 
					| TP_F | TP_g | TP_G))
		{
			str = itoa_aA_eE_fF_gG(lst);
			print_str(str);
		}
		str = rint_unicode(lst);
		lst = lst->next;
	}
	return (cnt);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	t_flgs_types *prm;

	va_start(args, format);
	if(fill_struct(&prm, format) == 0)
		return(-1);
	determine_args(prm, args);
	printing_args(prm);
	return (0);
}
