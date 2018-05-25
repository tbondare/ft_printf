/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:02:42 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/23 17:36:45 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*int cnt_args(t_flgs_types *lst)
{
	int cnt;

	cnt = 0;
	while (lst)
	{
		if (lst->types)
			cnt++;
		if (lst->prec_star)
			cnt++;
		if (lst->wdth_star)
			cnt++;
		lst = lst->next;
	}
	return (cnt);
}

void determine_args(t_flgs_types *prm, va_list args)
{
	va_list next;
	t_flgs_types *lst;
	int i;
	int cnt;

	i = 1;
	lst = prm;
	cnt = cnt_args(lst);
	while(i <= cnt)
	{
		while (lst)
		{
			if (lst->types == 0)
			{
				lst = lst->next;
				continue ;
			}
			if (lst->indx_arg == i)
			{
				va_end(next);
				va_copy(next, args);
				dtrm_args_with_if(lst, next);
			}
			if (lst->indx_arg_wdth == i)
			{
				va_end(next);
				va_copy(next, args);
				lst->width = va_arg(next, int);
				if (lst->width < 0)
					lst->flags = set_flg(lst->flags, FL_MINUS);
			}
			if (lst->indx_arg_prec == i)
			{
				va_end(next);
				va_copy(next, args);
				lst->prec = va_arg(next, int);

			}
			lst = lst->next;
			va_end(args);
			va_copy(args, next);
			va_end(next);
		}
		i++;
	}
} */

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
		print_unicode(lst);
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
