/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:02:42 by tbondare          #+#    #+#             */
/*   Updated: 2018/06/15 15:40:33 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_str(char *str)
{
	write(1, str, ft_strlen(str));
	free(str);
}

char *print_pct(t_flgs_types *lst)
{
	char *str;
	int i;

	str = NULL;
	i = 0;
	if (lst->width == 0)
		str = (char*)malloc(sizeof(char) * 2);
	str = (char*)malloc(sizeof(char) * lst->width + 1);
	if (check_flg(lst->flags, FL_MINUS) || (check_flg(lst->flags, FL_MINUS)
				&& (check_flg(lst->flags, FL_NULL))))
	{
		str[i++] = '%';
		while (lst->width > i)
			str[i++] = ' ';
	}
	else if (check_flg(lst->flags, FL_NULL))
	{
		while (i < lst->width - 1)
			str[i++] = '0';
		str[i++] = '%';
	}
	else if (lst->width > 0 || check_flg(lst->flags, FL_SPACE))
	{
		while (i < lst->width - 1)
			str[i++] = ' ';
		str[i++] = '%';
	}
	else
		str[i++] = '%';
	str[i] = '\0';
	return (str);
}

int printing_args(t_flgs_types *prm)
{
	char *str;
	int total_strlen;
	t_flgs_types *lst;
	char sgn;
	int mem_w;

	total_strlen = 0;
	lst = prm;
	sgn = ' ';
	mem_w = lst->width;
	while (lst)
	{
		if (check_flg(lst->types, TP_d | TP_i | TP_D | TP_u | TP_U))
			str = itoa_printf(lst);
		else if (check_flg(lst->types, TP_o | TP_O | TP_x | TP_X | TP_b))
			str = itoa_printf_oO_xX_b(lst);
		else if (check_flg(lst->types, TP_a | TP_A | TP_e | TP_E | TP_f 
					| TP_F | TP_g | TP_G))
			str = itoa_aA_eE_fF_gG(lst);
		else if (check_flg(lst->types, TP_C | TP_S | TP_c | TP_s) &&
						check_flg(lst->md_lengh, LN_l))
			str = print_unicode(lst);
		else if (check_flg(lst->types, TP_p))
			str = pointer(lst);
		else if (check_flg(lst->types, TP_pct))
			str = print_pct(lst);
		else if (check_flg(lst->types, TP_c | TP_C) && lst->val.lng == -1)
		{
			str = 0;
			if (check_flg(lst->flags, FL_MINUS) && lst->width > 1)
			{
				write(1, "\0", 1);
				lst->width--;
				while (lst->width--)
					write(1, &sgn, 1);
			}
			else if (lst->width > 1)
			{
				if (check_flg(lst->flags, FL_NULL))
					sgn = '0';
				lst->width--;
				while (lst->width--)
					write(1, &sgn, 1);
				write(1, "\0", 1);
			}
			else
				 write(1, "\0", 1);
		}
		else if (check_flg(lst->types, TP_s) || check_flg(lst->types, TP_S)
				||check_flg(lst->types, TP_c) || check_flg(lst->types, TP_C))
			str = print_cC_sS(lst);
		else
			str = lst->str_out;
		if (str != 0)
		{
			print_str(str);
			total_strlen = total_strlen + ft_strlen(str);
		}
		else if (str == 0 && check_flg(lst->types, TP_c) && lst->val.lng == -1)
		{
			if (mem_w != 0)
				total_strlen = mem_w;
			else
				total_strlen = total_strlen + 1;
			lst = lst->next;
			continue ;
		}
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
