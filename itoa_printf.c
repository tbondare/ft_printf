/*
 * itoa_printf.c
 *
 *  Created on: 1 мар. 2018 г.
 *      Author: Татьяна
 */

# include "libftprintf.h"

int check_sign_dif_tp(t_flgs_types *lst)
{
	if (check_flg(lst->types, TP_i | TP_d) && check_flg(lst->md_lengh, LN_j))
		return (lst->val.imax < 0);
	else if (check_flg(lst->types, TP_u) && check_flg(lst->md_lengh, LN_j))
		return (lst->val.uimax < 0);
	else if (check_flg(lst->types, TP_i | TP_d | TP_D))
		return (lst->val.lng < 0);
	else if (check_flg(lst->types, TP_u | TP_U))
		return (lst->val.ulng < 0);
	else if (check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l))
		return (lst->val.win < 0);
	return (0);
}

int check_is_sign(t_flgs_types *lst, char *neg)
{
	int sign;

	sign = 0;
	if (check_flg(lst->flags, FL_PLUS))
	{
		*neg = check_sign_dif_tp(lst) ? '-' : '+';
		sign = 1;
	}
	else if (check_flg(lst->flags, FL_SPACE))
	{
		*neg = check_sign_dif_tp(lst) ? '-' : ' ';
		sign = 1;
	}
	else if (check_sign_dif_tp(lst))
	{
		*neg = '-';
		sign = 1;
	}
	else
		*neg = 0;
	return (sign);
}

int cnt_idD(t_flgs_types *lst, int *cnt)
{
	long long int n;

	n = lst->val.lng;
	n = n < 0 ? -n : n;
	while (n)
	{
		n = n / 10;
		(*cnt)++;
	}
	return (*cnt);
}

int cnt_id_j(t_flgs_types *lst, int *cnt)
{
	intmax_t n;

	n = lst->val.imax;
	n = n < 0 ? -n : n;
	while (n)
	{
		n = n / 10;
		(*cnt)++;
	}
	return (*cnt);
}

int cnt_u_j(t_flgs_types *lst, int *cnt)
{
	uintmax_t n;

	n = lst->val.uimax;
	while (n)
	{
		n = n / 10;
		(*cnt)++;
	}
	return (*cnt);
}

int cnt_uU(t_flgs_types *lst, int *cnt)
{
	unsigned long long int n;

	n = lst->val.ulng;
	while (n)
	{
		n = n / 10;
		(*cnt)++;
	}
	return (*cnt);
}

int	ft_cnt(t_flgs_types *lst)
{
	int	cnt;
	wint_t n;

	cnt = 0;
	if (check_flg(lst->types, TP_i | TP_d) && check_flg(lst->md_lengh, LN_j))
		return (cnt_id_j(lst, &cnt));
	else if (check_flg(lst->types, TP_u) && check_flg(lst->md_lengh, LN_j))
		return (cnt_u_j(lst, &cnt));
	else if (check_flg(lst->types, TP_i | TP_d | TP_D))
		return (cnt_idD(lst, &cnt));
	else if (check_flg(lst->types, TP_u | TP_U))
		return (cnt_uU(lst, &cnt));
	else if (check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l))
	{
		n = lst->val.win;
		n = n < 0 ? -n : n;
		while (n)
		{
			n = n / 10;
			cnt++;
		}
	}
	return (cnt);
}

int num_qv(t_flgs_types *lst, int cnt)
{
	int num_q;
	struct lconv *lc;
	lc = localeconv();

	num_q = 0;
	if (lc->thousands_sep[0] == '\0')
		return (num_q);
	if (check_flg(lst->flags, FL_QUOTE))
	{
		if (cnt > 3)
		{
			if (cnt % 3 == 0)
				num_q = cnt / 3 - 1;
			else
				num_q = cnt / 3;
		}
	}
	return (num_q);
}

void outp_id_j(t_flgs_types *lst, char *newstr, int *mem_w)
{
	int i;
	struct lconv *lc;
	lc = localeconv();

	i = 0;
	lst->val.imax = lst->val.imax < 0 ? -lst->val.imax : lst->val.imax;
	lst->val.imax == 0 ? newstr[*mem_w] = '0' : 0;
	while (lst->val.imax)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		newstr[(*mem_w)--] = lst->val.imax % 10 + '0';
		lst->val.imax  = lst->val.imax / 10;
		i++;
	}
}

void outp_uoxX_j(t_flgs_types *lst, char *newstr, int *mem_w, int base)
{
	int i;
	struct lconv *lc;
	lc = localeconv();

	i = 0;
	lst->val.uimax == 0 ? newstr[*mem_w] = '0' : 0;
	while (lst->val.uimax)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		if (check_flg(lst->types, TP_x) && lst->val.uimax % base > 9)
			newstr[(*mem_w)--] = lst->val.uimax % base + 'a' - 10;
		else if(check_flg(lst->types, TP_X) && lst->val.uimax % base > 9)
			newstr[(*mem_w)--] = lst->val.uimax % base + 'A' - 10;
		else
			newstr[(*mem_w)--] = lst->val.uimax % base + '0';
		lst->val.uimax  = lst->val.uimax / base;
		i++;
	}
}

void outp_idD(t_flgs_types *lst, char *newstr, int *mem_w)
{
	int i;
	struct lconv *lc;
	lc = localeconv();

	i = 0;
	lst->val.lng = lst->val.lng < 0 ? -lst->val.lng : lst->val.lng;
	lst->val.lng == 0 ? newstr[*mem_w] = '0' : 0;
	while (lst->val.lng)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		newstr[(*mem_w)--] = lst->val.lng % 10 + '0';
		lst->val.lng  = lst->val.lng / 10;
		i++;
	}
}

void outp_c_l(t_flgs_types *lst, char *newstr, int *mem_w)
{
	int i;
	struct lconv *lc;
	lc = localeconv();

	i = 0;
	lst->val.win == 0 ? newstr[*mem_w] = '0' : 0;
	lst->val.win = lst->val.win < 0 ? -lst->val.win : lst->val.win;
	while (lst->val.win)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		newstr[(*mem_w)--] = lst->val.win % 10 + '0';
		lst->val.win  = lst->val.win / 10;
		i++;
	}
}

void output_dgt(t_flgs_types *lst, char *newstr, int *mem_w, int base)
{
	int i;
	struct lconv *lc;

	i = 0;
	if (check_flg(lst->types, TP_i | TP_d) && check_flg(lst->md_lengh, LN_j))
		outp_id_j(lst, newstr, mem_w);
	else if (check_flg(lst->types, TP_u | TP_o | TP_x | TP_X) && check_flg(lst->md_lengh, LN_j))
		outp_uoxX_j(lst, newstr, mem_w, base);
	else if (check_flg(lst->types, TP_i | TP_d | TP_D))
		outp_idD(lst, newstr, mem_w);
	else if (check_flg(lst->types, TP_u | TP_U | TP_o | TP_O | TP_x | TP_X))
	{
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
	}
	else if (check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l))
		outp_c_l(lst, newstr, mem_w);
}

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
	output_dgt(lst, newstr, &mem_w, 10);
	if (neg != 0)
		newstr[mem_w--] = neg;
	while (mem_w)
		newstr[mem_w--] = ' ';
	newstr[mem_w] = ' ';
}

char *itoa_printf(t_flgs_types *lst)
{
	char			*newstr;
	int				cnt;
	char			neg;
	int num_q;
	int sign;

	sign = check_is_sign(lst, &neg);
	cnt = ft_cnt(lst);
	num_q = num_qv(lst, cnt);
	if (lst->width > cnt + num_q + sign && lst->prec <= cnt + num_q && lst->width > lst->prec) // w>cnt, cnt>p, p<w (1)
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
	return (newstr);
}
