/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determ_argc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:30:29 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/25 17:14:32 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		cnt_args(t_fl_tp *lst)
{
	int cnt;
	
	cnt = 0;
	while (lst)
	{
		if (lst->typ)
			cnt++;
		if (lst->prc_star)
			cnt++;
		if (lst->wdth_star)
			cnt++;
		lst = lst->next;
	}
	return (cnt);
}

void	ft_if_detetm(t_fl_tp *lst, va_list args, va_list *next, int *i)
{
	if (lst->ind_arg == *i)
	{
		va_end(*next);
		va_copy(*next, args);
		dtrm_args_with_if(lst, *next);
	}
	if (lst->ind_arg_wdth == *i)
	{
		va_end(*next);
		va_copy(*next, args);
		lst->wdth = va_arg(*next, int);
		if (lst->mem > 0)
			lst->wdth = lst->mem;
		if (lst->wdth < 0)
			lst->flg = set_flg(lst->flg, fl_minus);
	}
	if (lst->ind_arg_prc == *i)
	{
		va_end(*next);
		va_copy(*next, args);
		lst->prc = va_arg(*next, int);
        if (lst->prc == 0 && lst->prc_star == '*')
            lst->prc_star = '-';
	}
}

void	if_prc_min_one(t_fl_tp	*lst, va_list args, va_list *next, int *i)
{
	if (lst->prc == -1)
	{
		if (check_fl(lst->typ, tp_d | tp_da | tp_i | tp_x |
				tp_xa | tp_o | tp_oa | tp_u | tp_ua))
			lst->prc = 1;
		else if (check_fl(lst->typ, tp_sa | tp_s) && lst->prc_star != '*')
		{
			lst->prc = 0;
			lst->prc_star = 0;
		}
		else if (check_fl(lst->typ, tp_p))
			lst->prc = -1;
		else
			lst->prc = 0;
	}
	else if (lst->prc < 0 && lst->prc != -1)
		lst->prc = 0;
	if (lst->wdth_star == '*' && lst->wdth < 0)
			lst->wdth = -lst->wdth;
	ft_if_detetm(lst, args, next, i);
}

void	determine_args(t_fl_tp *prm, va_list args)
{
	va_list	next;
	t_fl_tp	*lst;
	int		i;
	int		cnt;

	i = 1;
	lst = prm;
	cnt = cnt_args(lst);
	while (i <= cnt)
	{
		lst = prm;
		  while (lst)
		  {
			if (lst->typ == 0 || check_fl(lst->typ, tp_err))
			{
				lst = lst->next;
				continue ;
			}
			if_prc_min_one(lst, args, &next, &i);
			lst = lst->next;
			va_end(args);
			va_copy(args, next);
			va_end(next);
		  }
		i++;
	}
}
