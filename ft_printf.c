/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:02:42 by tbondare          #+#    #+#             */
/*   Updated: 2018/06/15 15:40:33 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_str(char *str)
{
	write(1, str, ft_strlen(str));
	ft_strdel(&str);
}

void if_f_tp_c(t_fl_tp *lst, int *mem_w, char sgn)
{
	if (lst->wdth_star == '*' && lst->wdth < 0)
	{
		lst->wdth = lst->wdth * -1;
		*mem_w = lst->wdth;
	}
	if (check_fl(lst->flg, fl_minus) && lst->wdth > 1)
	{
		write(1, "\0", 1);
		lst->wdth--;
		while (lst->wdth--)
			write(1, &sgn, 1);
	}
	else if (lst->wdth > 1)
	{
		if (check_fl(lst->flg, fl_null))
			sgn = '0';
		lst->wdth--;
		while (lst->wdth--)
			write(1, &sgn, 1);
		write(1, "\0", 1);
	}
	else
		write(1, "\0", 1);
}

//void if_print_args(t_fl_tp *lst, char *str)
//{
//
//}

int printing_args(t_fl_tp *prm)
{
	char *str;
	int total_strlen;
	t_fl_tp *lst;
	char sgn;
	int mem_w;

	total_strlen = 0;
	lst = prm;
	sgn = ' ';
	while (lst)
	{
        mem_w = lst->wdth;
        if (check_fl(lst->typ, tp_err))
        	lst->typ = set_flg(0, tp_c);
		if (check_fl(lst->typ, tp_d | tp_i | tp_da | tp_u | tp_ua))
			str = itoa_printf(lst);
		else if (check_fl(lst->typ, tp_o | tp_oa | tp_x | tp_xa | tp_p | tp_b))
			str = itoa_printf_ooa_xxa_b(lst);
		else if (check_fl(lst->typ, tp_a | tp_aa | tp_e | tp_ea | tp_f
									  | tp_fa | tp_g | tp_ga))
			str = itoa_aaa_eea_ffa_gga(lst);
		else if (check_fl(lst->typ, tp_c | tp_s) &&
				check_fl(lst->md_len, ln_l))
			str = print_unicode(lst);
        else if (check_fl(lst->typ, tp_ca | tp_sa))
        {
            if (check_fl(lst->typ, tp_ca) && lst->val.win == 0)
            {
                str = 0;
                write(1, "\0", 1);
                total_strlen = total_strlen + 1;
            }
            else
                str = print_unicode(lst);
        }
		else if (check_fl(lst->typ, tp_pct))
			str = print_pct(lst);
		else if (check_fl(lst->typ, tp_c | tp_ca) && lst->val.ln == -1)
		{

			str = 0;
			if_f_tp_c(lst, &mem_w, sgn);
		}
		else if (check_fl(lst->typ, tp_s | tp_c))
			str = print_cca_ssa(lst);
		else
			str = ft_strdup(lst->str_out);
		if (str != 0)
		{
			total_strlen = total_strlen + ft_strlen(str);
			print_str(str);
		}
		else if (str == 0 && check_fl(lst->typ, tp_c) && lst->val.ln == -1)
		{
			if (mem_w != 0)
				total_strlen = total_strlen + mem_w;
			else
				total_strlen = total_strlen + 1;
			lst = lst->next;
			continue ;
		}
		lst = lst->next;
	}
	return (total_strlen);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	t_fl_tp *prm;
	int total_strlen;
	t_fl_tp *mem_var;

    prm = NULL;
	va_start(args, format);
	if(fill_struct(&prm, format) == 0)
		return(0);
	determine_args(prm, args);
	total_strlen = printing_args(prm);
	while (prm)
    {
		ft_strdel(&(prm->str_out));
        mem_var = prm->next;
        free(prm);
        prm = mem_var;
    }
	return (total_strlen);
}
