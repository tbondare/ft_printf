/*
 * init_arr.c
 *
 *  Created on: 11 февр. 2018 г.
 *      Author: Татьяна
 */

# include "libftprintf.h"

void init_flags(t_arr_el *arr)
{
	arr['+' - arr_first].flg_or_tp_or_ln = AR_fl;
	arr['+' - arr_first].bit_flg = FL_PLUS;
	arr['-' - arr_first].flg_or_tp_or_ln = AR_fl;
	arr['-' - arr_first].bit_flg = FL_MINUS;
	arr['0' - arr_first].flg_or_tp_or_ln = AR_fl;
	arr['0' - arr_first].bit_flg = FL_NULL;
	arr['#' - arr_first].flg_or_tp_or_ln = AR_fl;
	arr['#' - arr_first].bit_flg = FL_GRILL;
	arr[' ' - arr_first].flg_or_tp_or_ln = AR_fl;
	arr[' ' - arr_first].bit_flg = FL_SPACE;
	arr['\'' - arr_first].flg_or_tp_or_ln = AR_fl;
	arr['\'' - arr_first].bit_flg = FL_QUOTE;
}

void init_length(t_arr_el *arr)
{
	arr['L' - arr_first].flg_or_tp_or_ln = AR_ln;
	arr['L' - arr_first].bit_flg = LN_L;
	arr['h' - arr_first].flg_or_tp_or_ln = AR_ln;
	arr['h' - arr_first].bit_flg = LN_h;
	arr['l' - arr_first].flg_or_tp_or_ln = AR_ln;
	arr['l' - arr_first].bit_flg = LN_l;
	arr['j' - arr_first].flg_or_tp_or_ln = AR_ln;
	arr['j' - arr_first].bit_flg = LN_j;
	arr['z' - arr_first].flg_or_tp_or_ln = AR_ln;
	arr['z' - arr_first].bit_flg = LN_z;
}

void init_types_1(t_arr_el *arr)
{
	arr['s' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['s' - arr_first].bit_flg = TP_s;
	arr['S' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['S' - arr_first].bit_flg = TP_S;
	arr['p' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['p' - arr_first].bit_flg = TP_p;
	arr['d' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['d' - arr_first].bit_flg = TP_d;
	arr['D' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['D' - arr_first].bit_flg = TP_D;
	arr['i' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['i' - arr_first].bit_flg = TP_i;
	arr['o' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['o' - arr_first].bit_flg = TP_o;
	arr['O' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['O' - arr_first].bit_flg = TP_O;
	arr['u' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['u' - arr_first].bit_flg = TP_u;
	arr['U' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['U' - arr_first].bit_flg = TP_U;
	arr['x' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['x' - arr_first].bit_flg = TP_x;
	arr['X' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['X' - arr_first].bit_flg = TP_X;
}

void init_types_2(t_arr_el *arr)
{
	arr['c' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['c' - arr_first].bit_flg = TP_c;
	arr['C' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['C' - arr_first].bit_flg = TP_C;
	arr['e' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['e' - arr_first].bit_flg = TP_e;
	arr['E' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['E' - arr_first].bit_flg = TP_E;
	arr['f' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['f' - arr_first].bit_flg = TP_f;
	arr['F' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['F' - arr_first].bit_flg = TP_F;
	arr['g' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['g' - arr_first].bit_flg = TP_g;
	arr['G' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['G' - arr_first].bit_flg = TP_G;
	arr['a' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['a' - arr_first].bit_flg = TP_a;
	arr['A' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['A' - arr_first].bit_flg = TP_A;
	arr['n' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['n' - arr_first].bit_flg = TP_n;
}

void init_arr(t_arr_el *arr)
{
	int i;

	i = 0;
	while (i < 91)
	{
		arr[i].flg_or_tp_or_ln = AR_not;
		i++;
	}
	init_flags(arr);
	init_length(arr);
	init_types_1(arr);
	init_types_2(arr);
	arr['b' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['b' - arr_first].bit_flg = TP_b;
	arr['r' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['r' - arr_first].bit_flg = TP_r;
	arr['k' - arr_first].flg_or_tp_or_ln = AR_tp;
	arr['k' - arr_first].bit_flg = TP_k;
}
