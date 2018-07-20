/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determ_types.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:10:17 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/23 17:25:01 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		lst->val.ulng = va_arg(args, size_t);
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
	{
		lst->val.ulng = (unsigned char)va_arg(args, int);
		if (lst->val.ulng == 0)
			lst->val.lng = -1;
	}
/*	else if (check_flg(lst->types, TP_c) && lst->md_lengh == 0)
		lst->val.ulng = (unsigned char)va_arg(args, int); */
	else if ((check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l)) || (check_flg(lst->types, TP_C)))
		lst->val.win = (wint_t)va_arg(args, wint_t);
	else if (check_flg(lst->types, TP_s) && lst->md_lengh == 0)
		lst->val.str = va_arg(args, char*);
	else if ((check_flg(lst->types, TP_s) && check_flg(lst->md_lengh, LN_l)) || (check_flg(lst->types, TP_S)))
		lst->val.point = va_arg(args, wchar_t*);
	else if (check_flg(lst->types, TP_p))
		lst->val.point = va_arg(args, void*);
}
