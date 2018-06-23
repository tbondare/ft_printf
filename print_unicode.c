/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 13:54:43 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:18:23 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void uf_in_ucod(int *cnt, wchar_t wc, char *str)
{
	if (0 <= wc && wc <= 0x7f)
		str[0] = (char)wc;
	else if (0x80 <= wc && wc <= 0x7ff)
	{
		str[0] = (0xc0 | (wc >> 6));
		str[1] = (0x80 | (wc & 0x3f));
		*cnt = 2;
	}
	else if (0x800 <= wc && wc <= 0xffff)
	{
		str[0] = (0xe0 | (wc >> 12));
		str[1] = (0x80 | ((wc >> 6) & 0x3f));
		str[2] = (0x80 | (wc & 0x3f));
		*cnt = 3;
	}
	else if ( 0x10000 <= wc && wc <= 0x1fffff)
	{
		str[0] = (0xf0 | (wc >> 18));
		str[1] = (0x80 | ((wc >> 12) & 0x3f));
		str[2] = (0x80 | ((wc >> 6) & 0x3f));
		str[3] = (0x80 | (wc & 0x3f));
		*cnt = 4;
	}
}

void bin_op_for_unicode(t_flgs_types *lst, int *cnt, int i, char *str)
{
    wchar_t wc;

    if (check_flg(lst->types, TP_c | TP_C))
	{
		wc = lst->val.win;
		uf_in_ucod(cnt, wc, str);
	}
	else if ((check_flg(lst->types, TP_s | TP_S)))
	{
		wc = ((wchar_t*)lst->val.point)[i];
		uf_in_ucod(cnt, wc, str);
	}
}

char *print_unicode(t_flgs_types *lst)
{
	char *str = NULL;
	int cnt;
	int i;
	int mem_cnt;
	int j;
	
	i = 0;
	cnt = 1;
	mem_cnt = 0;
	if ((check_flg(lst->types, TP_c) && (check_flg(lst->md_lengh, LN_l))) || (check_flg(lst->types, TP_C)))
	{
		str = (char*)malloc(sizeof(char) * 4 + 1);
		bin_op_for_unicode(lst, &cnt, i, str);
		str[cnt] = '\0';
	}
	else if ((check_flg(lst->types, TP_s) && (check_flg(lst->md_lengh, LN_l))) || (check_flg(lst->types, TP_S)))
	{
		while (((wchar_t*)lst->val.point)[i] != '\0')
			i++;
		str = (char*)malloc(sizeof(char) * i * 4 + 1);
		i = 0;
		j = 0;
		while (((wchar_t*)lst->val.point)[i] != '\0')
		{
		    cnt = 1;
			bin_op_for_unicode(lst, &cnt, i, &str[j]);
			mem_cnt = cnt + mem_cnt;
/*			while (cnt > 0)
			{
				j++;
				cnt--;
			}*/
			j = j + cnt;
			i++;
		}
		str[mem_cnt] = '\0';
	}
	return (str);
}
