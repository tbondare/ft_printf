/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_aaa_eea_ffa_gga.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:15:14 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:09:13 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*void outp_eE_aA(t_fl_tp *lst, int cnt, char **newstr, int base) //� ���� �� ������ � � �������� ����� ����
{
	int i;
	int dgt;
	int num_dgt;
	int cnt1;
	char *exp;

	i = 0;
	cnt1 = 0;
	num_dgt = lst->prc + 1;
	*newstr = (char*)malloc(sizeof(char) * (num_dgt + 1 + 4));
	lst->val.lndbl = lst->val.lndbl < 0 ? -lst->val.lndbl : lst->val.lndbl;
	lst->val.lndbl == 0 ? (*newstr)[i] = '0' : 0;
	while (num_dgt)
	{
		dgt = lst->val.lndbl * base;
		lst->val.lndbl = lst->val.lndbl * base - dgt;
		if (check_flg(lst->typ, tp_a) && dgt > 9)
			newstr[(i)++] = dgt + 'a';
		if (check_flg(lst->typ, tp_aa) && dgt > 9)
			newstr[(i)++] = dgt + 'A';
		(*newstr)[(i)++] = dgt + '0';
		if (num_dgt == lst->prc + 1)
			(*newstr)[(i)++] = ',';
		num_dgt--;
	}
//	i++;
	if (check_flg(lst->typ, tp_e))
		(*newstr)[i++] = 'e';
	else if (check_flg(lst->typ, tp_ea))
		(*newstr)[i++] = 'E';
	else if (check_flg(lst->typ, tp_a))
		(*newstr)[i++] = 'p';
	else if (check_fl(lst->typ, tp_aa))
		(*newstr)[i++] = 'P';
	if (cnt < 0)
	{
		(*newstr)[i++] = '-';
		cnt = -cnt;
	}
	else
	{
		(*newstr)[i++] = '+';
		cnt--;
	}
	if (cnt < 9)
	{
		(*newstr)[i++] = '0';
		(*newstr)[i] = cnt + '0';
	}
	else
	{
		(*newstr)[i] = '\0';
		exp = ft_itoa(cnt);
		newstr = rejoin(newstr, exp);
		free(exp);
	}
}*/

/*char *outp_gG(t_fl_tp *lst, int cnt)
{
	if (lst->prc == 0)
		lst->prc = 1;
	if (cnt >= 0)
	{
		if (cnt >= lst->prc)
			return outp_eE_aA(lst, cnt, 10);
		else
			return outp_float(lst, cnt + lst->prc);
	}
	else
	{
		if (cnt < -4)
			return outp_eE_aA(lst, cnt, 10);
		else
			return (outp_float(lst, cnt + lst->prc));
	}
} */

/*char *output_float_base(t_fl_tp *lst, int cnt, int base)
{
//	int i;
//	struct lconv *lc;
	char *newstr;

//	i = 0;
	if (check_flg(lst->typ, tp_a | tp_aa))
		newstr = outp_eE_aA(lst, cnt, 16);
	else if (check_flg(lst->typ, tp_f | tp_fa))
		newstr = outp_float(lst, cnt + lst->prc);
	else if (check_flg(lst->typ, tp_e | tp_ea))
		newstr = outp_eE_aA(lst, cnt, 10);
	else if (check_flg(lst->typ, tp_g | tp_ga))
		newstr = outp_gG(lst, cnt);
	lc = localeconv();
	lst->val.uln == 0 ? newstr[*mem_w] = '0' : 0;
		while (lst->val.uln)
		{
			if (check_flg(lst->flg, fl_quote) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
				newstr[(*mem_w)--] = *(lc->thousands_sep);
			if (check_flg(lst->typ, tp_x) && lst->val.uln % base > 9)
				newstr[(*mem_w)--] = lst->val.uln % base + 'a' - 10;
			else if(check_fl(lst->typ, tp_xa) && lst->val.uln % base > 9)
				newstr[(*mem_w)--] = lst->val.uln % base + 'A' - 10;
			else
				newstr[(*mem_w)--] = lst->val.uln % base + '0';
			lst->val.uln  = lst->val.uln / base;
			i++;
		}
		return (newstr);
}*/

/*void if_fl_minus_float(char *newstr, t_fl_tp *lst, int sum, char neg)
{
	int res;
	int mem_w;

	mem_w = lst->wdth;
	newstr[mem_w--] = '\0';
	res = lst->wdth - sum;
	while (res)
	{
		newstr[mem_w--] = ' ';
		res--;
	}
	output_dgt(lst, newstr, &mem_w, 10);
	if (neg != 0)
		newstr[0] = neg;
}

void if_flg_null_float(char *newstr, t_fl_tp *lst, int sum, char neg)
{
	int mem_w;
	int res;

	mem_w = lst->wdth;
	newstr[mem_w--] = '\0';
	output_dgt(lst, newstr, &mem_w, 10);
	res = lst->wdth - sum;
	while (res)
	{
		newstr[mem_w--] = '0';
		res--;
	}
	if (neg != 0)
		newstr[0] = neg;
}

void if_flg_not_null_float(char *newstr, t_fl_tp *lst, int mem_w, char neg)
{
	newstr[mem_w--] = '\0';
	output_dgt(lst, newstr, &mem_w, 10);
	if (neg != 0)
		newstr[mem_w--] = neg;
	while (mem_w)
		newstr[mem_w--] = ' ';
	newstr[mem_w] = ' ';
}
*/
char *itoa_aaa_eea_ffa_gga(t_fl_tp *lst)
{
//	char			*newstr;
	int				cnt;
	char			neg;
	int num_q;
	int sign;
	char *arr = NULL;
	int base;
	long double mem_val;

	num_q = 0;
	sign = check_is_sign_in_float(lst, &neg);
	if (check_fl(lst->typ, tp_a | tp_aa))
		base = 16;
	else
		base = 10;
	mem_val = lst->val.lndbl;
	cnt = cnt_till_aa_ee_ff_gg(base, &mem_val, lst);
	if (check_fl(lst->typ, tp_f | tp_fa | tp_g | tp_ga))
		num_q = num_qv(lst, cnt);
	if (lst->prc == 0)
		lst->prc = 6;
	arr = outp_float(lst, cnt + lst->prc + sign + num_q, cnt, &mem_val);
/*	if (lst->wdth > cnt + num_q + sign && lst->prc <= cnt + num_q && lst->wdth > lst->prc) // w>cnt, cnt>p, p<w (1)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->wdth + 1))))
			return (0);
		if (check_flg(lst->flg, fl_minus))
			if_fl_minus_float(newstr, lst, cnt + num_q + sign, neg);
		else
		{
			if (check_fl(lst->flg, fl_null))
				if_flg_null_float(newstr, lst, cnt + num_q + sign, neg);
			else
				if_flg_not_null_float(newstr, lst, lst->wdth, neg);
		}
	}
	else if (lst->wdth <= cnt + sign + num_q && lst->prc <= cnt + num_q) // cnt > p, cnt > w (3)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (cnt + sign + num_q + 1))))
			return (0);
		if_flg_not_null_float(newstr, lst, cnt + sign + num_q, neg);
	}
	else if (lst->wdth > cnt + num_q + sign && lst->prc > cnt + num_q && lst->wdth > lst->prc + sign) // w>cnt, cnt <p, w>p (2)
	{
			if (check_flg(lst->flg, fl_minus))
			{
				if (!(newstr = (char*)malloc(sizeof(char) * (lst->wdth + 1))))
					return (0);
				int mem_w = lst->wdth;
				int res;
				newstr[mem_w--] = '\0';
				res = lst->wdth - lst->prc - sign;
				while (res)
				{
					newstr[mem_w--] = ' ';
					res--;
				}
				output_dgt(lst, newstr, &mem_w, 10);
				res = lst->prc - cnt - num_q;
				while (res)
				{
					newstr[mem_w--] = '0';
					res--;
				}
				if (neg != 0)
					newstr[0] = neg;
			}
	}
	else if (lst->prc + sign > lst->wdth)
	{
		int mem_w = lst->prc + sign;
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->prc + sign + 1))))
			return (0);
		newstr[mem_w--] = '\0';
		output_dgt(lst, newstr, &mem_w, 10);
		while (mem_w)
			newstr[mem_w--] = '0';
		if (neg != 0)
			newstr[mem_w] = neg;
		else
			newstr[mem_w] = '0';
	}
	return (newstr); */
	return (arr);
}
