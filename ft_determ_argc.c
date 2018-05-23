/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determ_argc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:30:29 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/23 17:36:42 by tbondare         ###   ########.fr       */
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

void determ_args_c(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.ulng = va_arg(args, unsigned char);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.win = va_arg(args, wint_t);
}

void determ_args_s(t_flgs_types *lst, va_list args)
{
	if (lst->md_lengh == 0)
		lst->val.str = va_arg(args, char*);
	else if (check_flg(lst->md_lengh, LN_l))
		lst->val.point = va_arg(args, wchar_t*);
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
 59     while(i <= cnt)
 60     {
 61         while (lst)
 62         {
 63             if (lst->types == 0)
 64             {
 65                 lst = lst->next;
 66                 continue ;
 67             }
 68             if (lst->indx_arg == i)
 69             {
 70                 va_end(next);
 71                 va_copy(next, args);
 72                 dtrm_args_with_if(lst, next);
 73             }
 74             if (lst->indx_arg_wdth == i)
 75             {
 76                 va_end(next);
 77                 va_copy(next, args);
 78                 lst->width = va_arg(next, int);
 79                 if (lst->width < 0)
 80                     lst->flags = set_flg(lst->flags, FL_MINUS);
 81             }
 82             if (lst->indx_arg_prec == i)
 83             {
 84                 va_end(next);
 85                 va_copy(next, args);
 86                 lst->prec = va_arg(next, int);
 87
 88             }
 89             lst = lst->next;
 90             va_end(args);
 91             va_copy(args, next);
 92             va_end(next);
 93         }
		i++;
 }
 }
