/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt_i_d_uU_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:43:53 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/25 18:55:42 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

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

int ft_cnt_i_d_uU_c(t_flgs_types *lst)
{
	int cnt;
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
