/*
 * ft_printf.c
 *
 *  Created on: 9 февр. 2018 г.
 *      Author: Татьяна
 */


#include "libftprintf.h"

int cnt_args(t_flgs_types *lst)
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

void determ_args_d_i(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.lng = va_arg(args, int);
	else if (check_flg(lst->md_lengh, LN_hh))
		lst->val.lng = (signed char)va_arg(args, int);
	else if (check_flg(lst->md_lengh, LN_h))
		lst->val.lng = (short int)va_arg(args, int);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.lng = va_arg(args, long int);
	else if (check_flg(lst->md_lengh, LN_ll))
		lst->val.lng = va_arg(args, long long int);
	else if (check_flg(lst->md_lengh, LN_j))
		lst->val.imax = va_arg(args, intmax_t);
	else if(check_flg(lst->md_lengh, LN_z))
		lst->val.lng = va_arg(args, size_t);
}

void determ_args_o_u_xX(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.ulng = va_arg(args, unsigned int);
	else if (check_flg(lst->md_lengh, LN_hh))
		lst->val.ulng = (unsigned char)va_arg(args, int);
	else if (check_flg(lst->md_lengh, LN_h))
		lst->val.ulng = (unsigned short)va_arg(args, int);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.ulng = va_arg(args, unsigned long int);
	else if (check_flg(lst->md_lengh, LN_ll))
		lst->val.ulng = va_arg(args, unsigned long long int);
	else if (check_flg(lst->md_lengh, LN_j))
		lst->val.uimax = va_arg(args, uintmax_t);
	else if (check_flg(lst->md_lengh, LN_z))
		lst->val.lng = va_arg(args, size_t);
}

void determ_args_n(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.point = va_arg(args, int*);
	else if (check_flg(lst->md_lengh, LN_hh))
		lst->val.point = va_arg(args, signed char*);
	else if (check_flg(lst->md_lengh, LN_h))
		lst->val.point = va_arg(args, short int*);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.point = va_arg(args, long int*);
	else if (check_flg(lst->md_lengh, LN_ll))
		lst->val.point = va_arg(args, long long int*);
	else if (check_flg(lst->md_lengh, LN_j))
		lst->val.point = va_arg(args, intmax_t*);
	else if (check_flg(lst->md_lengh, LN_z))
		lst->val.point = va_arg(args, size_t*);
}

void determ_args_aA_eE_fF_gG(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.lndbl = va_arg(args, double);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.lndbl = va_arg(args, double);
	else if (check_flg(lst->md_lengh, LN_L))
		lst->val.lndbl = va_arg(args, long double);
}

/*void determ_args_c(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.ulng = va_arg(args, unsigned char);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.win = va_arg(args, wint_t);
}

void determ_args_s(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.str = va_arg(args, char*);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.point = va_arg(args, wchar_t*);
} */

void dtrm_args_with_if(t_flgs_types *lst, va_list args)
{
	if (check_flg(lst->types, TP_i | TP_d))
		determ_args_d_i(lst, args);
	else if (check_flg(lst->types, TP_D))
		lst->val.lng = va_arg(args, long int);
	else if (check_flg(lst->types, TP_O | TP_U))
			lst->val.ulng = va_arg(args, unsigned long int);
	else if (check_flg(lst->types, TP_o | TP_u | TP_x | TP_X))
		determ_args_o_u_xX(lst, args);
	else if (check_flg(lst->types, TP_n))
		determ_args_n(lst, args);
	else if (check_flg(lst->types, TP_a | TP_A | TP_e | TP_E
			| TP_f | TP_F | TP_g | TP_G))
		determ_args_aA_eE_fF_gG(lst, args);
	else if (check_flg(lst->types, TP_c) && lst->md_lengh == 0)
		lst->val.ulng = (unsigned char)va_arg(args, int);
	else if (check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l))
		lst->val.win = (wint_t)va_arg(args, int);
	else if (check_flg(lst->types, TP_s) && lst->md_lengh == 0)
		lst->val.str = va_arg(args, char*);
	else if (check_flg(lst->types, TP_s) && check_flg(lst->md_lengh, LN_l))
		lst->val.point = va_arg(args, wchar_t*);
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
}

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
		if (check_flg(lst->types, TP_d | TP_i | TP_D | TP_u | TP_U) ||
				(check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l)))
		{
			str = itoa_printf(lst);
			print_str(str);
		}
		else if (check_flg(lst->types, TP_o | TP_O | TP_x | TP_X | TP_b))
		{
			str = itoa_printf_oO_xX_b(lst);
			print_str(str);
		}
		else if (check_flg(lst->types, TP_a | TP_A | TP_e | TP_E | TP_f | TP_F | TP_g | TP_G))
		{
			str = itoa_aA_eE_fF_gG(lst);
			print_str(str);
		}
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
