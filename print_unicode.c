/*
 * print_unicode.c
 *
 *  Created on: 17 апр. 2018 г.
 *      Author: Татьяна
 */

#include <wchar.h>
#include "libftprintf.h"

void bin_op_for_unicode(char onec, wchar_t *uc, t_flgs_types *lst, int *i)
{
	if ((onec & 0x80) == 0)
	{
		*uc = onec;
	    i = i + 1;
	}

/*	else if ((onec & 0xE0) == 0xC0)
	{
		*uc = (lst->val.win[i] & 0x1F) << 6;
	    *uc = *uc | (lst->val.win[i+1] & 0x3F);
	    i = i + 2;
	}
	else if ((onec & 0xF0) == 0xE0)
	{
	    *uc = (lst->val.win[i] & 0xF) << 12;
	    *uc = *uc | (lst->val.win[i+1] & 0x3F) << 6;
	    *uc = *uc | (lst->val.win[i+2] & 0x3F);
	    i = i + 3;
	}
	else if ((onec & 0xF8) == 0xF0)
	{
		*uc = (lst->val.win[i] & 0x7) << 18;
	    *uc = *uc | (lst->val.win[i+1] & 0x3F) << 12;
	    *uc = *uc | (lst->val.win[i+2] & 0x3F) << 6;
	    *uc = *uc | (lst->val.win[i+3] & 0x3F);
	    i = i + 4;
	}
}

print_unicode(t_flgs_types *lst)
{
	char *str;
	wchar_t uc;
	int i;
	int j;
	char onec;

	i = 0;
	j = 0;
	if (check_flg(lst->types, TP_s) && (check_flg(lst->md_lengh, LN_l)))
	{
		while (lst->val.win[i] != '\0')
		{
			onec = lst->val.win[i];
			uc = bin_op_for_unicode(onec, &uc, lst, &i);
			str = (char*)malloc(sizeof(char) * i);
			str[j] = uc;
		}
	}
	else if (check_flg(lst->types, TP_c) && (check_flg(lst->md_lengh, LN_l)))
	{
		onec = lst->val.win[i];
		uc = bin_op_for_unicode(onec, uc, lst, i);
	} */
}
