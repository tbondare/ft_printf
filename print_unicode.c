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
	char *allstr = NULL;
	int cnt;
	int i;
	int mem_cnt;
	int j;

	i = 0;
	cnt = 1;
	j = 0;
	mem_cnt = 0;
	if ((check_flg(lst->types, TP_c) && (check_flg(lst->md_lengh, LN_l))) || (check_flg(lst->types, TP_C)))
	{
		str = (char *) malloc(sizeof(char) * 4 + 1);
		bin_op_for_unicode(lst, &cnt, i, str);
		str[cnt] = '\0';
	}
	else if ((check_flg(lst->types, TP_s) && (check_flg(lst->md_lengh, LN_l))) || (check_flg(lst->types, TP_S)))
	{
		if ((wchar_t *) lst->val.point == NULL)
		{
			str = (char *) malloc(sizeof(char) * 7);
			str[0] = '(';
			str[1] = 'n';
			str[2] = 'u';
			str[3] = 'l';
			str[4] = 'l';
			str[5] = ')';
			str[6] = '\0';
			return (str);
		}
		if (lst->prec == 0 && lst->prec_star == '-')
		{
			str = (char *) malloc(sizeof(char));
			mem_cnt = 0;
		}
		else
		{
			if (lst->prec > 0)
				str = (char *) malloc(sizeof(char) * lst->prec + 4 + 1);
			else
			{
				while (((wchar_t *) lst->val.point)[i] != '\0')
					i++;
				str = (char *) malloc(sizeof(char) * i * 4 + 1);
				i = 0;
			}
			while (((wchar_t *) lst->val.point)[i] != '\0')
			{
				cnt = 1;
				bin_op_for_unicode(lst, &cnt, i, &str[j]);
				mem_cnt = cnt + mem_cnt;
				j = j + cnt;
				if (lst->prec < mem_cnt && lst->prec > 0)
				{
					mem_cnt = mem_cnt - cnt;
					break;
				}
				i++;
			}
		}
		str[mem_cnt] = '\0';
		if (lst->width > mem_cnt)
		{
			i = 0;
			j = 0;
			allstr = (char *) malloc(sizeof(char) * lst->width + 1);
			lst->width = lst->width - mem_cnt;
			if (check_flg(lst->flags, FL_NULL))
				while (lst->width--)
					allstr[i++] = '0';
			else if (check_flg(lst->flags, FL_MINUS))
			{
				while (str[j] != '\0')
					allstr[i++] = str[j++];
				while (lst->width--)
					allstr[i++] = ' ';
				allstr[i] = '\0';
				free(str);
				return (allstr);
			}
			else
				while (lst->width--)
					allstr[i++] = ' ';
			while (str[j] != '\0')
				allstr[i++] = str[j++];
			free(str);
			allstr[i] = '\0';
			return (allstr);
		}
	}
	return (str);
}
