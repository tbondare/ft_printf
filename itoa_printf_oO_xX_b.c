/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_printf_oO_xX_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:08:48 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:15:20 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

int cnt_oxX_j(t_flgs_types *lst, int *cnt, int base)
{
	uintmax_t n;

	n = lst->val.uimax;
	while (n)
	{
		n = n / base;
		(*cnt)++;
	}
	return (*cnt);
}
int cnt_oxX(t_flgs_types *lst, int *cnt, int base)
{
	unsigned long long int n;

	n = lst->val.ulng;
	if (lst->val.ulng == 0)
		*cnt = 1;
	else if (check_flg(lst->flags, FL_GRILL) && !(check_flg(lst->types, TP_x | TP_X)))
		*cnt = 1;
	else if (check_flg(lst->flags, FL_GRILL) && lst->val.ulng != 0 && check_flg(lst->types, TP_x | TP_X))
		*cnt = 2;
	while (n)
	{
		n = n / base;
		(*cnt)++;
	}
	return (*cnt);
}

int ft_cnt_oO_xX_b(t_flgs_types *lst, int base)
{
	int	cnt;

	cnt = 0;
	if (check_flg(lst->types, TP_o | TP_x | TP_X) && check_flg(lst->md_lengh, LN_j))
		return (cnt_oxX_j(lst, &cnt, base));
	else
		return (cnt_oxX(lst, &cnt, base));
}

void if_fl_minus_oOxXb(char *newstr, t_flgs_types *lst, int cnt, int base)
{
	int res;
	int mem_w;
	unsigned long long mem_val;

	mem_w = lst->width;
	mem_val = lst->val.ulng;
	newstr[mem_w--] = '\0';
	res = lst->width - cnt;
	while (res)
	{
		newstr[mem_w--] = ' ';
		res--;
	}
	output_dgt(lst, newstr, &mem_w, base);
	if (check_flg(lst->flags, FL_GRILL) && mem_val != 0)
	{
		if (check_flg(lst->types, TP_X))
			newstr[mem_w--] = 'X';
		else if (check_flg(lst->types, TP_x))
			newstr[mem_w--] = 'x';
		newstr[mem_w--] = '0';
	}
}

void if_flg_null_oOxXb(char *newstr, t_flgs_types *lst, int cnt, int base)
{
	int mem_w;
	int res;
	unsigned long long mem_val;

	mem_w = lst->width;
	mem_val = lst->val.ulng;
	newstr[mem_w--] = '\0';
	output_dgt(lst, newstr, &mem_w, base);
	res = lst->width - cnt;
	while (res)
	{
		newstr[mem_w--] = '0';
		res--;
	}
	if (check_flg(lst->flags, FL_GRILL) && mem_val != 0)
	{
		if (check_flg(lst->types, TP_X))
			newstr[mem_w--] = 'X';
		else
			newstr[mem_w--] = 'x';
		newstr[mem_w--] = '0';
	}
}

void if_flg_not_null_oOxXb(char *newstr, t_flgs_types *lst, int base)
{
	int mem_w;
	unsigned long long mem_val;

	mem_w = lst->width;
	mem_val = lst->val.ulng;
	newstr[mem_w--] = '\0';
	output_dgt(lst, newstr, &mem_w, base);
	if (check_flg(lst->flags, FL_GRILL) && mem_val != 0)
	{
		if (check_flg(lst->types, TP_X))
			newstr[mem_w--] = 'X';
		else if (check_flg(lst->types, TP_x))
			newstr[mem_w--] = 'x';
		newstr[mem_w--] = '0';
	}
	while (mem_w >= 0)
		newstr[mem_w--] = ' ';
}

char *itoa_printf_oO_xX_b(t_flgs_types *lst)
{
	char* newstr = NULL;
	int	cnt;
	int base;

	base = 0;
	if (check_flg(lst->types, TP_o | TP_O))
		base = 8;
	else if (check_flg(lst->types, TP_x | TP_X))
		base = 16;
	else if (check_flg(lst->types, TP_b))
		base = 2;
	cnt = ft_cnt_oO_xX_b(lst, base);
	if (lst->prec == 0)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * 1)))
			return (0);
		newstr[0] = '\0';
	}
	else if (lst->width > cnt && lst->prec <= cnt && lst->width > lst->prec) // w>cnt, cnt>p, p<w (1)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->width + 1))))
			return (0);
		if (check_flg(lst->flags, FL_MINUS))
			if_fl_minus_oOxXb(newstr, lst, cnt, base);
		else
		{
			if (check_flg(lst->flags, FL_NULL))
				if_flg_null_oOxXb(newstr, lst, cnt, base);
			else
				if_flg_not_null_oOxXb(newstr, lst, base);
		}
	}
	else if (lst->width <= cnt && lst->prec <= cnt) // cnt > p, cnt > w (3)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (cnt + 1))))
			return (0);
		lst->width = cnt;
		if_flg_not_null_oOxXb(newstr, lst, base);
	}
	else if (lst->width > cnt && lst->prec > cnt && lst->width > lst->prec) // w>cnt, cnt <p, w>p (2)
	{
			if (check_flg(lst->flags, FL_MINUS))
			{
				if (!(newstr = (char*)malloc(sizeof(char) * (lst->width + 1))))
					return (0);
				int mem_w = lst->width;
				int res;
				newstr[mem_w--] = '\0';
				res = lst->width - lst->prec;
				while (res)
				{
					newstr[mem_w--] = ' ';
					res--;
				}
				output_dgt(lst, newstr, &mem_w, base);
				res = lst->prec - cnt;
				while (res)
				{
					newstr[mem_w--] = '0';
					res--;
				}
			}
	}
	else if (lst->prec > lst->width)
	{
		int mem_w = lst->prec;
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->prec + 1))))
			return (0);
		newstr[mem_w--] = '\0';
		output_dgt(lst, newstr, &mem_w, base);
		while (mem_w >= 0)
			newstr[mem_w--] = '0';
	}
	return (newstr);
}
