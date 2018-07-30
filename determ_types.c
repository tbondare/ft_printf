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

void	determ_args_d_i(t_fl_tp *lst, va_list args)
{
	if (lst->md_len == 0)
		lst->val.ln = va_arg(args, int);
	else if (check_fl(lst->md_len, ln_hh))
		lst->val.ln = (signed char)va_arg(args, int);
	else if (check_fl(lst->md_len, ln_h))
		lst->val.ln = (short int)va_arg(args, int);
	else if (check_fl(lst->md_len, ln_l))
		lst->val.ln = va_arg(args, long int);
	else if (check_fl(lst->md_len, ln_ll))
		lst->val.ln = va_arg(args, long long int);
	else if (check_fl(lst->md_len, ln_j))
		lst->val.imx = va_arg(args, intmax_t);
	else if(check_fl(lst->md_len, ln_z))
		lst->val.ln = va_arg(args, size_t);
}

void	determ_args_o_u_x_xa(t_fl_tp *lst, va_list args)
{
	if (lst->md_len == 0)
		lst->val.uln = va_arg(args, unsigned int);
	else if (check_fl(lst->md_len, ln_hh))
		lst->val.uln = (unsigned char)va_arg(args, int);
	else if (check_fl(lst->md_len, ln_h))
		lst->val.uln = (unsigned short)va_arg(args, int);
	else if (check_fl(lst->md_len, ln_l))
		lst->val.uln = va_arg(args, unsigned long int);
	else if (check_fl(lst->md_len, ln_ll))
		lst->val.uln = va_arg(args, unsigned long long int);
	else if (check_fl(lst->md_len, ln_j))
		lst->val.uimx = va_arg(args, uintmax_t);
	else if (check_fl(lst->md_len, ln_z))
		lst->val.uln = va_arg(args, size_t);
}

void	determ_args_n(t_fl_tp *lst, va_list args)
{
	if (lst->md_len == 0)
		lst->val.pnt = va_arg(args, int*);
	else if (check_fl(lst->md_len, ln_hh))
		lst->val.pnt = va_arg(args, signed char*);
	else if (check_fl(lst->md_len, ln_h))
		lst->val.pnt = va_arg(args, short int*);
	else if (check_fl(lst->md_len, ln_l))
		lst->val.pnt = va_arg(args, long int*);
	else if (check_fl(lst->md_len, ln_ll))
		lst->val.pnt = va_arg(args, long long int*);
	else if (check_fl(lst->md_len, ln_j))
		lst->val.pnt = va_arg(args, intmax_t*);
	else if (check_fl(lst->md_len, ln_z))
		lst->val.pnt = va_arg(args, size_t*);
}

void	else_determ(t_fl_tp *lst, va_list args)
{
	if ((check_fl(lst->typ, tp_c) && check_fl(lst->md_len, ln_l)) ||
            (check_fl(lst->typ, tp_ca)))
		lst->val.win = (wint_t)va_arg(args, wint_t);
	else if (check_fl(lst->typ, tp_da))
		lst->val.ln = va_arg(args, long int);
	else if (check_fl(lst->typ, tp_oa | tp_ua))
		lst->val.uln = va_arg(args, unsigned long int);
	else if (check_fl(lst->typ, tp_s) && lst->md_len == 0)
		lst->val.str = va_arg(args, char*);
	else if ((check_fl(lst->typ, tp_s) && check_fl(lst->md_len, ln_l)) ||
            (check_fl(lst->typ, tp_sa)))
		lst->val.pnt = va_arg(args, wchar_t*);
	else if (check_fl(lst->typ, tp_p))
		lst->val.pnt = va_arg(args, void*);
}

void	dtrm_args_with_if(t_fl_tp *lst, va_list args)
{
	if (check_fl(lst->typ, tp_i | tp_d))
		determ_args_d_i(lst, args);
	else if (check_fl(lst->typ, tp_o | tp_u | tp_x | tp_xa))
        determ_args_o_u_x_xa(lst, args);
	else if (check_fl(lst->typ, tp_n))
		determ_args_n(lst, args);
	else if (check_fl(lst->typ, tp_a | tp_aa | tp_e | tp_ea
                                  | tp_f | tp_fa | tp_g | tp_ga))
	{
		if (lst->md_len == 0)
			lst->val.lndbl = va_arg(args, double);
		else if (check_fl(lst->md_len, ln_l))
			lst->val.lndbl = va_arg(args, double);
		else if (check_fl(lst->md_len, ln_la))
			lst->val.lndbl = va_arg(args, long double);
	}
	else if (check_fl(lst->typ, tp_c) && lst->md_len == 0)
	{
		lst->val.uln = (unsigned char)va_arg(args, int);
		if (lst->val.uln == 0)
			lst->val.ln = -1;
	}
	else_determ(lst, args);
}
