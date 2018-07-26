/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outp_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:35:46 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 16:46:57 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *outp_float(t_flgs_types *lst, int num_dgt, int cnt, long double *mem_val)
{
	int i;
	int dgt;
	char *arr;
	int mem_cnt;
	struct lconv *lc;

	lc = localeconv();
	i = 0;
	mem_cnt = cnt;
	arr = (char*)malloc(sizeof(char) * (num_dgt + 2));
	if (lst->val.lndbl < 0)
	{
		lst->val.lndbl = lst->val.lndbl * -1;
		arr[i++] = '-';
		num_dgt--;
	}
	if (lst->val.lndbl < 1)
	{
		arr[i++] = '0';
		mem_cnt--, num_dgt--;
	}
	while (num_dgt)
	{
		dgt = *mem_val * 10;
		*mem_val = *mem_val * 10 - dgt;
		if (mem_cnt > 0)
			mem_cnt--;
		else if (mem_cnt == 0)
		{
			arr[(i)++] = *(lc->decimal_point);
			mem_cnt = -1;
		}
		arr[(i)++] = dgt + '0';
		num_dgt--;
	}
	dgt = *mem_val * 10;
	if (dgt >= 5)
	{
		arr[(i)--] = '\0';
		while (arr[i] == '9')
		{
			arr[i] = 0 + '0';
			i--;
			if (arr[i] == *(lc->decimal_point))
				i--;
		}
		arr[i] = arr[i] + 1;
	}
	else
		arr[i] = '\0';
	if (check_flg(lst->flags, FL_QUOTE) && cnt > 3 && lc->thousands_sep[0] != '\0')
		arr = quote(arr, cnt);
	return (arr);
}
