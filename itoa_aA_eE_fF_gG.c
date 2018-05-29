/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_aA_eE_fF_gG.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 20:15:14 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:09:13 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*void outp_eE_aA(t_flgs_types *lst, int cnt, char **newstr, int base) //� ���� �� ������ � � �������� ����� ����
{
	int i;
	int dgt;
	int num_dgt;
	int cnt1;
	char *exp;

	i = 0;
	cnt1 = 0;
	num_dgt = lst->prec + 1;
	*newstr = (char*)malloc(sizeof(char) * (num_dgt + 1 + 4));
	lst->val.lndbl = lst->val.lndbl < 0 ? -lst->val.lndbl : lst->val.lndbl;
	lst->val.lndbl == 0 ? (*newstr)[i] = '0' : 0;
	while (num_dgt)
	{
		dgt = lst->val.lndbl * base;
		lst->val.lndbl = lst->val.lndbl * base - dgt;
		if (check_flg(lst->types, TP_a) && dgt > 9)
			newstr[(i)++] = dgt + 'a';
		if (check_flg(lst->types, TP_A) && dgt > 9)
			newstr[(i)++] = dgt + 'A';
		(*newstr)[(i)++] = dgt + '0';
		if (num_dgt == lst->prec + 1)
			(*newstr)[(i)++] = ',';
		num_dgt--;
	}
//	i++;
	if (check_flg(lst->types, TP_e))
		(*newstr)[i++] = 'e';
	else if (check_flg(lst->types, TP_E))
		(*newstr)[i++] = 'E';
	else if (check_flg(lst->types, TP_a))
		(*newstr)[i++] = 'p';
	else if (check_flg(lst->types, TP_A))
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

/*char *outp_gG(t_flgs_types *lst, int cnt)
{
	if (lst->prec == 0)
		lst->prec = 1;
	if (cnt >= 0)
	{
		if (cnt >= lst->prec)
			return outp_eE_aA(lst, cnt, 10);
		else
			return outp_float(lst, cnt + lst->prec);
	}
	else
	{
		if (cnt < -4)
			return outp_eE_aA(lst, cnt, 10);
		else
			return (outp_float(lst, cnt + lst->prec));
	}
} */

/*char *output_float_base(t_flgs_types *lst, int cnt, int base)
{
//	int i;
//	struct lconv *lc;
	char *newstr;

//	i = 0;
	if (check_flg(lst->types, TP_a | TP_A))
		newstr = outp_eE_aA(lst, cnt, 16);
	else if (check_flg(lst->types, TP_f | TP_F))
		newstr = outp_float(lst, cnt + lst->prec);
	else if (check_flg(lst->types, TP_e | TP_E))
		newstr = outp_eE_aA(lst, cnt, 10);
	else if (check_flg(lst->types, TP_g | TP_G))
		newstr = outp_gG(lst, cnt);
	lc = localeconv();
	lst->val.ulng == 0 ? newstr[*mem_w] = '0' : 0;
		while (lst->val.ulng)
		{
			if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
				newstr[(*mem_w)--] = *(lc->thousands_sep);
			if (check_flg(lst->types, TP_x) && lst->val.ulng % base > 9)
				newstr[(*mem_w)--] = lst->val.ulng % base + 'a' - 10;
			else if(check_flg(lst->types, TP_X) && lst->val.ulng % base > 9)
				newstr[(*mem_w)--] = lst->val.ulng % base + 'A' - 10;
			else
				newstr[(*mem_w)--] = lst->val.ulng % base + '0';
			lst->val.ulng  = lst->val.ulng / base;
			i++;
		}
		return (newstr);
}*/

/*void if_fl_minus_float(char *newstr, t_flgs_types *lst, int sum, char neg)
{
	int res;
	int mem_w;

	mem_w = lst->width;
	newstr[mem_w--] = '\0';
	res = lst->width - sum;
	while (res)
	{
		newstr[mem_w--] = ' ';
		res--;
	}
	output_dgt(lst, newstr, &mem_w, 10);
	if (neg != 0)
		newstr[0] = neg;
}

void if_flg_null_float(char *newstr, t_flgs_types *lst, int sum, char neg)
{
	int mem_w;
	int res;

	mem_w = lst->width;
	newstr[mem_w--] = '\0';
	output_dgt(lst, newstr, &mem_w, 10);
	res = lst->width - sum;
	while (res)
	{
		newstr[mem_w--] = '0';
		res--;
	}
	if (neg != 0)
		newstr[0] = neg;
}

void if_flg_not_null_float(char *newstr, t_flgs_types *lst, int mem_w, char neg)
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
char *itoa_aA_eE_fF_gG(t_flgs_types *lst)
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
	mem_val = lst->val.lndbl;
	sign = check_is_sign_in_float(lst, &neg);
	if (check_flg(lst->types, TP_a | TP_A))
		base = 16;
	else
		base = 10;
	cnt = cnt_till_aA_eE_fF_gG(base, &mem_val, lst);
	if (check_flg(lst->types, TP_f | TP_F | TP_g | TP_G))
		num_q = num_qv(lst, cnt);
	if (lst->prec == 0)
		lst->prec = 6;
	arr = outp_float(lst, cnt + lst->prec, cnt, &mem_val);
/*	if (lst->width > cnt + num_q + sign && lst->prec <= cnt + num_q && lst->width > lst->prec) // w>cnt, cnt>p, p<w (1)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->width + 1))))
			return (0);
		if (check_flg(lst->flags, FL_MINUS))
			if_fl_minus_float(newstr, lst, cnt + num_q + sign, neg);
		else
		{
			if (check_flg(lst->flags, FL_NULL))
				if_flg_null_float(newstr, lst, cnt + num_q + sign, neg);
			else
				if_flg_not_null_float(newstr, lst, lst->width, neg);
		}
	}
	else if (lst->width <= cnt + sign + num_q && lst->prec <= cnt + num_q) // cnt > p, cnt > w (3)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (cnt + sign + num_q + 1))))
			return (0);
		if_flg_not_null_float(newstr, lst, cnt + sign + num_q, neg);
	}
	else if (lst->width > cnt + num_q + sign && lst->prec > cnt + num_q && lst->width > lst->prec + sign) // w>cnt, cnt <p, w>p (2)
	{
			if (check_flg(lst->flags, FL_MINUS))
			{
				if (!(newstr = (char*)malloc(sizeof(char) * (lst->width + 1))))
					return (0);
				int mem_w = lst->width;
				int res;
				newstr[mem_w--] = '\0';
				res = lst->width - lst->prec - sign;
				while (res)
				{
					newstr[mem_w--] = ' ';
					res--;
				}
				output_dgt(lst, newstr, &mem_w, 10);
				res = lst->prec - cnt - num_q;
				while (res)
				{
					newstr[mem_w--] = '0';
					res--;
				}
				if (neg != 0)
					newstr[0] = neg;
			}
	}
	else if (lst->prec + sign > lst->width)
	{
		int mem_w = lst->prec + sign;
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->prec + sign + 1))))
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
