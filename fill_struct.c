/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:07:31 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/25 17:18:40 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void ft_while_determ(t_flgs_types *lst, const char *frmt, int *i, t_arr_el *arr)
{
	while (frmt[*i] != '\0')
	{
		if (frmt[*i] > '0' && frmt[*i] <= '9')
			determine_dgt_data(frmt, i, lst);
		else if (frmt[*i] == '*')
			determine_width(frmt, i, lst);
		else if (frmt[*i] == '.')
			determine_precision(frmt, i, lst);
		else if (arr[frmt[*i] - arr_first].flg_or_tp_or_ln == AR_fl)
			(lst)->flags = set_flg(lst->flags, arr[frmt[*i] - arr_first].bit_flg);
		else if (arr[frmt[*i] - arr_first].flg_or_tp_or_ln == AR_ln)
			determine_md_len(frmt, i, lst, arr);
		else if (arr[frmt[*i] - arr_first].flg_or_tp_or_ln == AR_tp)
		{
			(lst)->types = set_flg((lst)->types, arr[frmt[*i] - arr_first].bit_flg);
			return ;
		}
		else
		{
			lst->types = set_flg(lst->types, TP_err);
			lst->val.ulng = frmt[*i];
			return ;
		}
		(*i)++;
	}
}

void fill_element(t_flgs_types **lst, const char *frmt, int *i)
{
	static t_arr_el arr[91];
	static char init = 0;

	(*i)++;
	if(init == 0)
	{
		init_arr(arr);
		init = 1;
	}
	if (frmt[*i] == '%')
	{
        if (frmt[*i + 1] != '\0')
            lstnewadd(lst);
		(*lst)->str_out = rejoin((*lst)->str_out, '%');
		return ;
	}
	if (ft_strlen((*lst)->str_out) != 0 || (*lst)->types != 0)
		lstnewadd(lst);
	ft_while_determ(*lst, frmt, i, arr);
}

void lstnewadd(t_flgs_types **lst)
{
	(*lst)->next = lstnew();
	*lst = (*lst)->next;
}

void index_args (t_flgs_types *lst)
{
	int cnt;
	
	cnt = 1;
	while (lst)
	{
		if (lst->wdth_star == '*' && lst->width == 0)
		{
			lst->indx_arg_wdth = cnt;
			cnt++;
		}
		if (lst->prec_star == '*' && lst->prec == -1)
		{
			lst->indx_arg_prec = cnt;
			cnt++;
		}
		if (lst->indx_arg == 0 && lst->types != 0)
		{
			lst->indx_arg = cnt;
			cnt++;
		}
		lst = lst->next;
	}
}

int fill_struct(t_flgs_types **prm, const char *frmt)
{
	int i;
	t_flgs_types *lst;
	
	i = 0;
	if (!(*prm = lstnew()))
		return (0);
	lst = *prm;
	while (frmt[i] != '\0')
	{
		if (frmt[i] == '%' && frmt[i + 1] == '\0')
			return 0;
		else if (frmt[i] == '%' && frmt[i + 1] != '\0')
			fill_element(&lst, frmt, &i);
		else
		{
			if (lst->types != 0)
				lstnewadd(&lst);
			lst->str_out = rejoin(lst->str_out, frmt[i]);
		}
		i++;
	}
	index_args(*prm);
	return (1);
}
