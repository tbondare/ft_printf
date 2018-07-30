/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_printf_ooa_xxa_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:08:48 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:15:20 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

int cnt_ox_xa_j(t_fl_tp *lst, int *cnt, int base)
{
	uintmax_t n;

	n = lst->val.uimx;
	while (n)
	{
		n = n / base;
		(*cnt)++;
	}
	return (*cnt);
}
int cnt_ox_xa(t_fl_tp *lst, int *cnt, int base)
{
	unsigned long long int n;

	n = lst->val.uln;
	if (lst->val.uln == 0)
		*cnt = 1;
	else if (check_fl(lst->flg, fl_grill) && !(check_fl(lst->typ, tp_x | tp_xa)))
		*cnt = 1;
	else if (check_fl(lst->flg, fl_grill) && lst->val.uln != 0 && check_fl(lst->typ, tp_x | tp_xa))
		*cnt = 2;
	while (n)
	{
		n = n / base;
		(*cnt)++;
	}
	return (*cnt);
}

int cnt_p(t_fl_tp *lst, int *cnt, int base)
{
	unsigned long long int n;

	n = (unsigned long long int)lst->val.pnt;
/*	if (lst->val.pnt == 0 && lst->prc == 0)
		*cnt = 6; */
    if (lst->val.pnt == 0 && lst->prc == -1)
        *cnt = 3;
	else
	{
		while (n)
		{
			n = n / base;
			(*cnt)++;
		}
		*cnt = *cnt + 2;
	}
    return (*cnt);
}

int ft_cnt_oo_xx_b(t_fl_tp *lst, int base)
{
	int	cnt;

	cnt = 0;
	if (check_fl(lst->typ, tp_o | tp_x | tp_xa) && check_fl(lst->md_len, ln_j))
		return (cnt_ox_xa_j(lst, &cnt, base));
	else if (check_fl(lst->typ, tp_p))
		return (cnt_p(lst, &cnt, base));
	else
		return (cnt_ox_xa(lst, &cnt, base));
}

void if_fl_minus_ooxxb(char *newstr, t_fl_tp *lst, int cnt, int base)
{
	int res;
	int mem_w;
	unsigned long long mem_val;

	mem_w = lst->wdth;
	mem_val = lst->val.uln;
	newstr[mem_w--] = '\0';
/*	if (lst->prc == 0)
		res = lst->wdth;
	else*/
		res = lst->wdth - cnt;
	while (res)
	{
		newstr[mem_w--] = ' ';
		res--;
	}
	output_dgt(lst, newstr, &mem_w, base);
	if (check_fl(lst->flg, fl_grill) && mem_val != 0)
	{
		if (check_fl(lst->typ, tp_xa))
			newstr[mem_w--] = 'X';
		else if (check_fl(lst->typ, tp_x))
			newstr[mem_w--] = 'x';
		newstr[mem_w--] = '0';
	}
}

void if_flg_null_ooxxb(char *newstr, t_fl_tp *lst, int cnt, int base)
{
	int mem_w;
	int res;
	unsigned long long mem_val;

	mem_w = lst->wdth;
	mem_val = lst->val.uln;
	newstr[mem_w--] = '\0';
	if (check_fl(lst->typ, tp_p) && lst->val.pnt == 0)
	{
		lst->wdth = lst->wdth - cnt;
		while (lst->wdth-- > 0)
			newstr[mem_w--] = '0';
		output_dgt(lst, newstr, &mem_w, base);
	}
	else
	{
		output_dgt(lst, newstr, &mem_w, base);
		res = lst->wdth - cnt;
		while (res) {
			newstr[mem_w--] = '0';
			res--;
		}
		if (check_fl(lst->flg, fl_grill) && mem_val != 0) {
			if (check_fl(lst->typ, tp_xa))
				newstr[mem_w--] = 'X';
			else
				newstr[mem_w--] = 'x';
			newstr[mem_w--] = '0';
		}
	}
}

void if_flg_not_null_oOxXb(char *newstr, t_fl_tp *lst, int base)
{
	int mem_w;
	unsigned long long mem_val;
    mem_w = lst->wdth;
	mem_val = lst->val.uln;
	newstr[mem_w--] = '\0';
	if (lst->prc != 0 || (check_fl(lst->typ, tp_p) && lst->prc != 0))
		output_dgt(lst, newstr, &mem_w, base);
    else if (check_fl(lst->typ, tp_p) && lst->prc == 0)
    {
        newstr[mem_w--] = 'x';
        newstr[mem_w--] = '0';
    }
	if (check_fl(lst->flg, fl_grill) && mem_val != 0)
	{
		if (check_fl(lst->typ, tp_xa))
			newstr[mem_w--] = 'X';
		else if (check_fl(lst->typ, tp_x))
			newstr[mem_w--] = 'x';
		newstr[mem_w--] = '0';
	}
	while (mem_w >= 0)
		newstr[mem_w--] = ' ';
}

void if_val_null(char *newstr)
{
	newstr[0] = '(';
	newstr[1] = 'n';
	newstr[2] = 'u';
	newstr[3] = 'l';
	newstr[4] = 'l';
	newstr[5] = ')';
	newstr[6] = '\0';
}

char *itoa_printf_ooa_xxa_b(t_fl_tp *lst)
{
	char* newstr = NULL;
	int	cnt;
	int base;

	base = 0;
	if (check_fl(lst->typ, tp_o | tp_oa))
		base = 8;
	else if (check_fl(lst->typ, tp_x | tp_xa | tp_p))
		base = 16;
	else if (check_fl(lst->typ, tp_b))
		base = 2;
	cnt = ft_cnt_oo_xx_b(lst, base);
	if (lst->prc == 0 && lst->wdth == 0 && (!check_fl(lst->typ, tp_p)))
	{
		if (check_fl(lst->flg, fl_grill) && check_fl(lst->typ, tp_o | tp_oa) && lst->val.uln == 0)
		{
			if (!(newstr = (char*)malloc(sizeof(char) * 2)))
				return (0);
			newstr[0] = '0';
			newstr[1] = '\0';
		}
        else if (check_fl(lst->typ, tp_o | tp_oa) && lst->val.uln != 0)
        {
            if (!(newstr = (char*)malloc(sizeof(char) * cnt + 1)))
                return (0);
            newstr[cnt--] = '\0';
            output_dgt(lst, newstr, &cnt, base);
            if (check_fl(lst->flg, fl_grill))
                newstr[cnt] = '0';
        }
		else
		{
			if (!(newstr = (char*)malloc(sizeof(char) * 1)))
				return (0);
			newstr[0] = '\0';
		}
	}
	else if (lst->wdth > cnt && lst->prc <= cnt && lst->wdth > lst->prc) // w>cnt, cnt>p, p<w (1)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->wdth + 1))))
			return (0);
		if (check_fl(lst->flg, fl_minus))
			if_fl_minus_ooxxb(newstr, lst, cnt, base);
		else
		{
			if (check_fl(lst->flg, fl_null))
				if_flg_null_ooxxb(newstr, lst, cnt, base);
			else
				if_flg_not_null_oOxXb(newstr, lst, base);
		}
	}
	else if (lst->wdth <= cnt && lst->prc <= cnt) // cnt > p, cnt > w (3)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (cnt + 1))))
			return (0);
        if (check_fl(lst->typ, tp_p) && lst->prc < 0 && lst->val.pnt == 0)
        {
            lst->wdth = cnt;
            if_flg_not_null_oOxXb(newstr, lst, base);
        }
//		if (check_fl(lst->typ, tp_p) && lst->val.pnt == 0 && lst->prc == 0)
//			if_val_null(newstr);
		else
		{
			lst->wdth = cnt;
			if_flg_not_null_oOxXb(newstr, lst, base);
		}
	}
	else if (lst->wdth > cnt && lst->prc > cnt && lst->wdth > lst->prc) // w>cnt, cnt <p, w>p (2)
	{
		if (!(newstr = (char*)malloc(sizeof(char) * (lst->wdth + 1))))
			return (0);
		if (check_fl(lst->flg, fl_minus))
		{
			int mem_w = lst->wdth;
			int res;
			newstr[mem_w--] = '\0';
			res = lst->wdth - lst->prc;
			while (res)
			{
				newstr[mem_w--] = ' ';
				res--;
			}
			output_dgt(lst, newstr, &mem_w, base);
			res = lst->prc - cnt;
			while (res)
			{
				newstr[mem_w--] = '0';
				res--;
			}
		}
		else
		{
			int mem_w = lst->wdth;
			cnt = lst->prc - cnt;
			newstr[mem_w--] = '\0';
			output_dgt(lst, newstr, &mem_w, base);
			while (cnt--)
				newstr[mem_w--] = '0';
			while (mem_w >= 0)
				newstr[mem_w--] = ' ';
		}
	}
	else if (lst->prc > lst->wdth)
	{
		int mem_w = 0;
        if (check_fl(lst->typ, tp_o | tp_oa | tp_x | tp_xa) && !(check_fl(lst->flg, fl_grill)))
			mem_w = lst->prc;
		else if (check_fl(lst->typ, tp_o | tp_oa))
            mem_w = lst->prc;
        else
			mem_w = lst->prc + 2;
		if (!(newstr = (char*)malloc(sizeof(char) * (mem_w + 1))))
			return (0);
		newstr[mem_w--] = '\0';
		output_dgt(lst, newstr, &mem_w, base);
        if (check_fl(lst->flg, fl_grill) && check_fl(lst->typ, tp_x | tp_xa))
        {
            while (mem_w > 1)
                newstr[(mem_w)--] = '0';
            newstr[(mem_w)--] = 'x';
            newstr[(mem_w)--] = '0';
        }
        else
            while (mem_w >= 0)
                newstr[mem_w--] = '0';
	}
	return (newstr);
}
