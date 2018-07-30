/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:03:08 by tbondare          #+#    #+#             */
/*   Updated: 2018/06/28 19:17:11 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void if_fl_minus(char *newstr, t_fl_tp *lst, int sum, char neg)
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

void if_flg_null(char *newstr, t_fl_tp *lst, int sum, char neg)
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

void if_flg_not_null (char *newstr, t_fl_tp *lst, int mem_w, char neg)
{
	newstr[mem_w--] = '\0';
	if ((lst->val.ln != 0 || lst->prc != 0 || check_fl(lst->typ, tp_u | tp_ua)) && mem_w >= 0)
		output_dgt(lst, newstr, &mem_w, 10);
	if (check_fl(lst->typ, tp_u | tp_ua) && neg == '-')
	{
		neg = 0;
		while (lst->prc-- > 0)
			newstr[mem_w--] = '0';
	}
	if (neg != 0)
		newstr[mem_w--] = neg;
	while (mem_w >= 0)
		newstr[mem_w--] = ' ';
}

char *itoa_printf(t_fl_tp *lst)
{
	char *newstr = NULL;
	int	cnt;
	char neg;
	int num_q;
	int sign;

	if (check_fl(lst->typ, tp_u | tp_ua))
	{
		sign = 0;
		neg = 0;
	}
	else
		sign = check_is_sign(lst, &neg);
	cnt = ft_cnt_i_d_u_ua_c(lst);
	num_q = num_qv(lst, cnt);
	if (lst->wdth_star == '*' && lst->wdth < 0)
		lst->wdth = lst->wdth * -1;
	if (lst->prc == 0 && check_fl(lst->typ, tp_d | tp_da | tp_i) && lst->val.ln == 0 && lst->wdth == 0)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * 1)))
			return (0);
		newstr[0] = '\0';
	}
	else if (lst->wdth > cnt + num_q + sign && lst->prc <= cnt + num_q && lst->wdth > lst->prc) // w>cnt, cnt>p, p<w (1)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->wdth + 1))))
			return (0);
		if (check_fl(lst->flg, fl_minus))
			if_fl_minus(newstr, lst, cnt + num_q + sign, neg);
		else
		{
			if (check_fl(lst->flg, fl_null))
				if_flg_null(newstr, lst, cnt + num_q + sign, neg);
			else
				if_flg_not_null(newstr, lst, lst->wdth, neg);
		}
	}
	else if (lst->wdth <= cnt + sign + num_q && lst->prc <= cnt + num_q) // cnt > p, cnt > w (3)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (cnt + sign + num_q + 1))))
			return (0);
		if_flg_not_null(newstr, lst, cnt + sign + num_q, neg);
	}
	else if (lst->wdth > cnt + num_q + sign && lst->prc > cnt + num_q && lst->wdth > lst->prc + sign) // w>cnt, cnt <p, w>p (2)
	{
			if (check_fl(lst->flg, fl_minus))
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
/*				res = lst->prc - cnt - num_q;
				while (res)
				{
					newstr[mem_w--] = '0';
					res--;
				} */
				if (neg != 0)
					newstr[0] = neg;
				else
					newstr[0] = '0';
			}
			else
			{
				if (!(newstr = (char*)malloc(sizeof(char) * (lst->wdth + 1))))
					return (0);
				if (lst->prc > cnt && check_fl(lst->typ, tp_u | tp_ua))
				{
					neg = '-';
					lst->prc = lst->prc - cnt;
				}
				if_flg_not_null(newstr, lst, lst->wdth, neg);
			}
	}
	else if (lst->prc + sign >= lst->wdth)
	{
		int mem_w = lst->prc + sign;
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->prc + sign + 1))))
			return (0);
		newstr[mem_w--] = '\0';
		output_dgt(lst, newstr, &mem_w, 10);
/*		while (mem_w > 0)
			newstr[mem_w--] = '0'; */
		if (neg != 0)
			newstr[mem_w] = neg;
		else if (mem_w >= 0)
			newstr[mem_w] = '0';
	}
	return (newstr);
}
