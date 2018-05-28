/*
 * itoa_printf_oO.c
 *
 *  Created on: 1 ���. 2018 �.
 *      Author: �������
 */

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

	mem_w = lst->width;
	newstr[mem_w--] = '\0';
	res = lst->width - cnt;
	while (res)
	{
		newstr[mem_w--] = ' ';
		res--;
	}
	output_dgt(lst, newstr, &mem_w, base);
}

void if_flg_null_oOxXb(char *newstr, t_flgs_types *lst, int cnt, int base)
{
	int mem_w;
	int res;

	mem_w = lst->width;
	newstr[mem_w--] = '\0';
	output_dgt(lst, newstr, &mem_w, base);
	res = lst->width - cnt;
	while (res)
	{
		newstr[mem_w--] = '0';
		res--;
	}
}

void if_flg_not_null_oOxXb(char *newstr, t_flgs_types *lst, int base)
{
	int mem_w;

	mem_w = lst->width;
	newstr[mem_w--] = '\0';
	output_dgt(lst, newstr, &mem_w, base);
	while (mem_w >= 0)
		newstr[mem_w--] = ' ';
}

char *itoa_printf_oO_xX_b(t_flgs_types *lst)
{
	char* newstr;
	int	cnt;
	int base;

	if (check_flg(lst->types, TP_o | TP_O))
		base = 8;
	else if (check_flg(lst->types, TP_x | TP_X))
		base = 16;
	else if (check_flg(lst->types, TP_b))
		base = 2;
	cnt = ft_cnt_oO_xX_b(lst, base);
	if (lst->width > cnt && lst->prec <= cnt && lst->width > lst->prec) // w>cnt, cnt>p, p<w (1)
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
