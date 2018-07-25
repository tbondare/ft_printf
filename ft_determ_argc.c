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

int cnt_args(t_flgs_types *lst)
{
	int cnt;
	
	cnt = 0;
	while (lst)
	{
		if (lst->types)
			cnt++;
		if (lst->prec_star)
			cnt++;
		if (lst->wdth_star)
			cnt++;
		lst = lst->next;
	}
	return (cnt);
}

void ft_if_detetm(t_flgs_types *lst, va_list args, va_list *next, int *i)
{
	if (lst->indx_arg == *i)
	{
		va_end(*next);
		va_copy(*next, args);
		dtrm_args_with_if(lst, *next);
	}
	if (lst->indx_arg_wdth == *i)
	{
		va_end(*next);
		va_copy(*next, args);
		lst->width = va_arg(*next, int);
		if (lst->width < 0)
			lst->flags = set_flg(lst->flags, FL_MINUS);
	}
	if (lst->indx_arg_prec == *i)
	{
		va_end(*next);
		va_copy(*next, args);
		lst->prec = va_arg(*next, int);
        if (lst->prec == 0 && lst->prec_star == '*')
            lst->prec_star = '-';
	}
}

void determine_args(t_flgs_types *prm, va_list args)
{
	va_list next;
	t_flgs_types *lst;
	int i;
	int cnt;

	i = 1;
	lst = prm;
	cnt = cnt_args(lst);
	while (i <= cnt)
	{
		lst = prm;
		  while (lst)
		  {
			if (lst->types == 0 || check_flg(lst->types, TP_err))
			{
				lst = lst->next;
				continue ;
			}
			else if (lst->prec == -1)
			{
				if (check_flg(lst->types, TP_d | TP_D | TP_i | TP_x | TP_X | TP_o | TP_O | TP_u | TP_U))
					lst->prec = 1;
				else if (check_flg(lst->types, TP_S | TP_s) && lst->prec_star != '*')
				{
					lst->prec = 0;
					lst->prec_star = 0;
				}
                else if (check_flg(lst->types, TP_p))
                    lst->prec = -1;
				else
					lst->prec = 0;
			}
			ft_if_detetm(lst, args, &next, &i);
			lst = lst->next;
			va_end(args);
			va_copy(args, next);
			va_end(next);
		  }
		i++;
	}
}
