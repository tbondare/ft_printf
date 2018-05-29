/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fns_for_fl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:15:46 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:23:04 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int check_is_sign_in_float(t_flgs_types *lst, char *neg)
{
	int sign;
	sign = 0;
	if (check_flg(lst->flags, FL_PLUS))
	{
		*neg = lst->val.lndbl < 0 ? '-' : '+';
		sign = 1;
	}
	else if (check_flg(lst->flags, FL_SPACE))
	{
		*neg = lst->val.lndbl < 0 ? '-' : ' ';
		sign = 1;
	}
	else if (lst->val.lndbl < 0)
	{
		*neg = '-';
		sign = 1;
	}
	else
		*neg = 0;
	return (sign);
}

int cnt_till_aA_eE_fF_gG(int base, long double *mem_val, t_flgs_types *lst)
{
	int cnt;
	
	cnt = 0;
	*mem_val =  *mem_val < 0 ? -  *mem_val :  *mem_val;
	if (*mem_val >= 1)
	{
		while (*mem_val >= 1)
		{
			*mem_val = *mem_val / base;
			cnt++;
		}
	}
	else
	{
		while (*mem_val < 1)
		{
			*mem_val = *mem_val * base;
			cnt++;
		}
		*mem_val = lst->val.lndbl;
		if (check_flg(*mem_val, TP_e | TP_E | TP_g | TP_G))
			cnt = -cnt;
	}
	return (cnt);
}

char *quote(char *arr, int cnt)
{
	char *str;
	int i;
	int j;
	int multiple;
	struct lconv *lc;
	
	lc = localeconv();
	i = 0;
	if (cnt % 3 == 0)
		cnt = cnt / 3 - 1;
	else if (cnt % 3 != 0)
		cnt = cnt / 3;
	while (arr[i] != '\0')
		i++;
	j = i + cnt;
	str = (char *)malloc(sizeof(char) * j + 1);
	while (arr[i] != *(lc->decimal_point))
		str[j--] = arr[i--];
	str[j--] = arr[i--];
	while (cnt > 0)
	{
		multiple = 3;
		while (multiple--)
			str[j--] = arr[i--];
		str[j--] = *(lc->thousands_sep);
		cnt--;
	}
	str[j] = arr[i];
	free (arr);
	return (str);
}
