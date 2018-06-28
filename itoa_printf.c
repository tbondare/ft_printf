/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:03:08 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:12:32 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void if_fl_minus(char *newstr, t_flgs_types *lst, int sum, char neg)
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

void if_flg_null(char *newstr, t_flgs_types *lst, int sum, char neg)
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

void if_flg_not_null (char *newstr, t_flgs_types *lst, int mem_w, char neg)
{
	newstr[mem_w--] = '\0';
	if (lst->val.lng != 0 || lst->prec != 0 || check_flg(lst->types, TP_u | TP_U))
		output_dgt(lst, newstr, &mem_w, 10);
	if (neg != 0)
		newstr[mem_w--] = neg;
	while (mem_w >= 0)
		newstr[mem_w--] = ' ';
}

char *itoa_printf(t_flgs_types *lst)
{
	char *newstr = NULL;
	int	cnt;
	char neg;
	int num_q;
	int sign;

	if (check_flg(lst->types, TP_u | TP_U))
	{
		sign = 0;
		neg = 0;
	}
	else
		sign = check_is_sign(lst, &neg);
	cnt = ft_cnt_i_d_uU_c(lst);
	num_q = num_qv(lst, cnt);
	if (lst->prec == 0 && check_flg(lst->types, TP_d | TP_D | TP_i) && lst->val.lng == 0 && lst->width == 0)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * 1)))
			return (0);
		newstr[0] = '\0';
	}
	else if (lst->width > cnt + num_q + sign && lst->prec <= cnt + num_q && lst->width > lst->prec) // w>cnt, cnt>p, p<w (1)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->width + 1))))
			return (0);
		if (check_flg(lst->flags, FL_MINUS))
			if_fl_minus(newstr, lst, cnt + num_q + sign, neg);
		else
		{
			if (check_flg(lst->flags, FL_NULL))
				if_flg_null(newstr, lst, cnt + num_q + sign, neg);
			else
				if_flg_not_null(newstr, lst, lst->width, neg);
		}
	}
	else if (lst->width <= cnt + sign + num_q && lst->prec <= cnt + num_q) // cnt > p, cnt > w (3)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (cnt + sign + num_q + 1))))
			return (0);
		if_flg_not_null(newstr, lst, cnt + sign + num_q, neg);
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
/*				res = lst->prec - cnt - num_q;
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
				if (!(newstr = (char*)malloc(sizeof(char) * (lst->width + 1))))
					return (0);
				if_flg_not_null(newstr, lst, lst->width, neg);
			}
	}
	else if (lst->prec + sign >= lst->width)
	{
		int mem_w = lst->prec + sign;
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->prec + sign + 1))))
			return (0);
		newstr[mem_w--] = '\0';
		output_dgt(lst, newstr, &mem_w, 10);
/*		while (mem_w > 0)
			newstr[mem_w--] = '0'; */
		if (neg != 0)
			newstr[mem_w] = neg;
//		else if (mem_w > 0)
//			newstr[mem_w] = '0';
	}
	return (newstr);
}
