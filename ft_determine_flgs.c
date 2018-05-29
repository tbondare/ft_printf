/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_determine_flgs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:19:36 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:07:28 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

char *create_dgt_str(const char *frmt, int *i)
{
	char *num;
	char str[2];
	
	str[1] = '\0';
	num = ft_strnew(0);
	while(frmt[*i] && (frmt[*i] >= '0' && frmt[*i] <= '9'))
	{
		str[0] = frmt[*i];
		num = rejoin(num, str[1]);
		(*i)++;
	}
	return (num);
}

void determine_dgt_data(const char *frmt, int *i, t_flgs_types *lst)
{
	char *num;
	
	num = create_dgt_str(frmt, i);
	if (frmt[*i] == '$')
		lst->indx_arg = ft_atoi(num);
	else
	{
		lst->width = ft_atoi(num);
		(*i)--;
	}
	free(num);
}

void determine_precision(const char *frmt, int *i, t_flgs_types *lst)
{
	char *num;
	
	(*i)++;
	if ((frmt[*i] < '0' || frmt[*i] > '9') && frmt[*i] != '*')
	{
		lst->prec = 0;
		(*i)--;
		return ;
	}
	if ((frmt[*i] == '*'))
	{
		lst->prec_star = '*';
		if (frmt[(*i) + 1] < '0' || frmt[(*i) + 1] > '9')
			return ;
		(*i)++;
	}
	num = create_dgt_str(frmt, i);
	lst->prec = ft_atoi(num);
	free(num);
	if (lst->prec_star != '*')
		(*i)--;
}

void determine_width(const char *frmt, int *i, t_flgs_types *lst)
{
	char *num;
	
	lst->wdth_star = '*';
	if ((frmt[(*i) + 1] < '0' || frmt[(*i) + 1] > '9'))
		return ;
	(*i)++;
	num = create_dgt_str(frmt, i);
	lst->width = ft_atoi(num);
	free(num);
}

void determine_md_len(const char *frmt, int *i, t_flgs_types *lst, t_arr_el *arr)
{
	if (frmt[*i] == 'h' && frmt[(*i) + 1] == 'h')
	{
		(*lst).md_lengh = set_flg((*lst).md_lengh, LN_hh);
		(*i)++;
	}
	else if (frmt[*i] == 'l' && frmt[(*i) + 1] == 'l')
	{
		(*lst).md_lengh = set_flg((*lst).md_lengh, LN_ll);
		(*i)++;
	}
	else
		(*lst).md_lengh = set_flg((*lst).md_lengh, arr[frmt[*i] - arr_first].bit_flg);
}
