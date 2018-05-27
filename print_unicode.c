/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:54:43 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/25 16:59:05 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *uf_in_ucod(int *cnt, wchar_t wc, char *str)
{
	if (0 <= wc && wc <= 0x7f)
		str[0] = (char)wc;
	else if ( 0x80 <= wc && wc <= 0x7ff)
	{
		str[0] = (0xc0 | (wc >> 6));
		str[1] = (0x80 | (wc & 0x3f));
		*cnt = 2;
	}
	else if ( 0x800 <= wc && wc <= 0xffff)
	{
		str[0] = ( 0xe0 | (wc >> 12));
		str[1] = ( 0x80 | ((wc >> 6) & 0x3f));
		str[2] = ( 0x80 | (wc & 0x3f));
		*cnt = 3;
	}
	else if ( 0x10000 <= wc && wc <= 0x1fffff)
	{
		str[0] = ( 0xf0 | (wc >> 18));
		str[1] = ( 0x80 | ((wc >> 12) & 0x3f));
		str[2] = ( 0x80 | ((wc >> 6) & 0x3f));
		str[3] = ( 0x80 | (wc & 0x3f));
		*cnt = 4;
	}
	return (str);
}

void bin_op_for_unicode(t_flgs_types *lst, int *cnt, int i, char *str)
{
    wchar_t wc;

    if (check_flg(lst->types, TP_c))
	{
		wc = lst->val.win;
		str = uf_in_ucod(cnt, wc, str);
	}
	else if ((check_flg(lst->types, TP_s)))
	{
		wc = ((wchar_t*)lst->val.point)[i];
		str = uf_in_ucod(&cnt, wc, str);
	}
}

char *print_unicode(t_flgs_types *lst)
{
	char *str;
	int cnt;
	int i;
	int mem_cnt;
	int j;
	
	i = 0;
	cnt = 1;
	mem_cnt = 0;
	if (check_flg(lst->types, TP_c) && (check_flg(lst->md_lengh, LN_l)))
	{
		str = (char*)malloc(sizeof(char) * 4 + 1);
		str = bin_op_for_unicode(lst, &cnt, &i, str);
		str[cnt] = '\0';
	}
	else if (check_flg(lst->types, TP_s) && (check_flg(lst->md_lengh, LN_l)))
	{
		while (((wchar_t*)lst->val.point)[i] != '\0')
			i++;
		str = (char*)malloc(sizeof(char) * ++i * 4 + 1);
		j = i * 4;
		str[j] = '\0';
		i = 0;
		j = 0;
		while (((wchar_t*)lst->val.point)[i] != '\0')
		{
			while (str[j] != '\0')
			{
				str = bin_op_for_unicode(lst, &cnt, i, &str[j]);
				mem_cnt = cnt + mem_cnt;
				while (cnt != 0);
				{
					j++;
					cnt--;
				}
			}
			i++;
		}
		str[mem_cnt] = '\0';
	}
	return (str);
}
