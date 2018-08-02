/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_print_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:09:14 by tbondare          #+#    #+#             */
/*   Updated: 2018/08/02 18:02:15 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	if_f_tp_c(t_fl_tp *lst, int *mem_w, char sgn)
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

int		if_print_args(t_fl_tp *lst, char **str)
{
	if (check_fl(lst->typ, tp_d | tp_i | tp_da | tp_u | tp_ua))
	{
		*str = itoa_printf(lst);
		return (1);
	}
	else if (check_fl(lst->typ, tp_o | tp_oa | tp_x | tp_xa | tp_p | tp_b))
	{
		*str = itoa_printf_ooa_xxa_b(lst);
		return (1);
	}
	else if (check_fl(lst->typ, tp_a | tp_aa | tp_e | tp_ea | tp_f
				| tp_fa | tp_g | tp_ga))
	{
		*str = itoa_aaa_eea_ffa_gga(lst);
		return (1);
	}
	else if (check_fl(lst->typ, tp_c | tp_s) &&
			check_fl(lst->md_len, ln_l))
	{
		*str = print_unicode(lst);
		return (1);
	}
	else
		return (0);
}

int		if_print_args2(t_fl_tp *lst, char **str, int *total_strlen)
{
	if (check_fl(lst->typ, tp_ca | tp_sa))
	{
		if (check_fl(lst->typ, tp_ca) && lst->val.win == 0)
		{
			*str = 0;
			write(1, "\0", 1);
			*total_strlen = *total_strlen + 1;
			return (1);
		}
		else
		{
			*str = print_unicode(lst);
			return (1);
		}
	}
	else if (check_fl(lst->typ, tp_pct))
	{
		*str = print_pct(lst);
		return (1);
	}
	else
		return (0);
}

int		if_print_args3(t_fl_tp *lst, char **str, int *mem_w)
{
	char sgn;

	sgn = ' ';
	if (check_fl(lst->typ, tp_c | tp_ca) && lst->val.ln == -1)
	{
		*str = 0;
		if_f_tp_c(lst, mem_w, sgn);
		return (1);
	}
	else if (check_fl(lst->typ, tp_s | tp_c))
	{
		*str = print_cca_ssa(lst);
		return (1);
	}
	else
	{
		*str = ft_strdup(lst->str_out);
		return (1);
	}
}

int		if_str_nul(t_fl_tp **lst, char **str, int *total_strlen, int *mem_w)
{
	if (*str != 0)
	{
		*total_strlen = *total_strlen + ft_strlen(*str);
		print_str(*str);
	}
	else if (*str == 0 && check_fl((*lst)->typ, tp_c) && (*lst)->val.ln == -1)
	{
		if (*mem_w != 0)
			*total_strlen = *total_strlen + *mem_w;
		else
			*total_strlen = *total_strlen + 1;
		*lst = (*lst)->next;
		return (0);
	}
	return (1);
}
