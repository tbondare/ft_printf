/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:09:38 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/23 16:39:04 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void init_flags(t_arr *arr)
{
	arr['+' - ar_frst].flg_or_tp_or_ln = ar_fl;
	arr['+' - ar_frst].bit_flg = fl_plus;
	arr['-' - ar_frst].flg_or_tp_or_ln = ar_fl;
	arr['-' - ar_frst].bit_flg = fl_minus;
	arr['0' - ar_frst].flg_or_tp_or_ln = ar_fl;
	arr['0' - ar_frst].bit_flg = fl_null;
	arr['#' - ar_frst].flg_or_tp_or_ln = ar_fl;
	arr['#' - ar_frst].bit_flg = fl_grill;
	arr[' ' - ar_frst].flg_or_tp_or_ln = ar_fl;
	arr[' ' - ar_frst].bit_flg = fl_space;
	arr['\'' - ar_frst].flg_or_tp_or_ln = ar_fl;
	arr['\'' - ar_frst].bit_flg = fl_quote;
}

void init_length(t_arr *arr)
{
	arr['L' - ar_frst].flg_or_tp_or_ln = ar_ln;
	arr['L' - ar_frst].bit_flg = ln_la;
	arr['h' - ar_frst].flg_or_tp_or_ln = ar_ln;
	arr['h' - ar_frst].bit_flg = ln_h;
	arr['l' - ar_frst].flg_or_tp_or_ln = ar_ln;
	arr['l' - ar_frst].bit_flg = ln_l;
	arr['j' - ar_frst].flg_or_tp_or_ln = ar_ln;
	arr['j' - ar_frst].bit_flg = ln_j;
	arr['z' - ar_frst].flg_or_tp_or_ln = ar_ln;
	arr['z' - ar_frst].bit_flg = ln_z;
}

void init_types_1(t_arr *arr)
{
	arr['s' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['s' - ar_frst].bit_flg = tp_s;
	arr['S' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['S' - ar_frst].bit_flg = tp_sa;
	arr['p' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['p' - ar_frst].bit_flg = tp_p;
	arr['d' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['d' - ar_frst].bit_flg = tp_d;
	arr['D' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['D' - ar_frst].bit_flg = tp_da;
	arr['i' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['i' - ar_frst].bit_flg = tp_i;
	arr['o' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['o' - ar_frst].bit_flg = tp_o;
	arr['O' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['O' - ar_frst].bit_flg = tp_oa;
	arr['u' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['u' - ar_frst].bit_flg = tp_u;
	arr['U' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['U' - ar_frst].bit_flg = tp_ua;
	arr['x' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['x' - ar_frst].bit_flg = tp_x;
	arr['X' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['X' - ar_frst].bit_flg = tp_xa;
}

void init_types_2(t_arr *arr)
{
	arr['c' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['c' - ar_frst].bit_flg = tp_c;
	arr['C' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['C' - ar_frst].bit_flg = tp_ca;
	arr['e' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['e' - ar_frst].bit_flg = tp_e;
	arr['E' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['E' - ar_frst].bit_flg = tp_ea;
	arr['f' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['f' - ar_frst].bit_flg = tp_f;
	arr['F' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['F' - ar_frst].bit_flg = tp_fa;
	arr['g' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['g' - ar_frst].bit_flg = tp_g;
	arr['G' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['G' - ar_frst].bit_flg = tp_ga;
	arr['a' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['a' - ar_frst].bit_flg = tp_a;
	arr['A' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['A' - ar_frst].bit_flg = tp_aa;
	arr['n' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['n' - ar_frst].bit_flg = tp_n;
}

void init_arr(t_arr *arr)
{
	int i;

	i = 0;
	while (i < 91)
	{
		arr[i].flg_or_tp_or_ln = ar_not;
		i++;
	}
	init_flags(arr);
	init_length(arr);
	init_types_1(arr);
	init_types_2(arr);
	arr['b' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['b' - ar_frst].bit_flg = tp_b;
	arr['r' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['r' - ar_frst].bit_flg = tp_r;
	arr['k' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['k' - ar_frst].bit_flg = tp_k;
	arr['%' - ar_frst].flg_or_tp_or_ln = at_tp;
	arr['%' - ar_frst].bit_flg = tp_pct;
}
