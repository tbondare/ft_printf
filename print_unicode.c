/*
 * print_unicode.c
 *
 *  Created on: 17 апр. 2018 г.
 *      Author: Татьяна
 */

#include <wchar.h>
#include "libftprintf.h"

char *bin_op_for_unicode(t_flgs_types *lst, int *cnt)
{
	char *str;
    wchar_t wc;

    wc = lst->val.win;
    if (0 <= wc && wc <= 0x7f )
    {
    	str = (char *)malloc(sizeof(char) * 1 + 1);
        str[0] = (char)wc;
        *cnt = 1;
    }
    else if ( 0x80 <= wc && wc <= 0x7ff)
    {
    	str = (char *)malloc(sizeof(char) * 2 + 1);
        str[0] = (0xc0 | (wc >> 6));
        str[1] = (0x80 | (wc & 0x3f));
        *cnt = 2;
    }
    else if ( 0x800 <= wc && wc <= 0xffff)
    {
    	str = (char *)malloc(sizeof(char) * 3 + 1);
    	str[0] = ( 0xe0 | (wc >> 12));
    	str[1] = ( 0x80 | ((wc >> 6) & 0x3f));
    	str[2] = ( 0x80 | (wc & 0x3f));
    	*cnt = 3;
    }
    else if ( 0x10000 <= wc && wc <= 0x1fffff)
    {
    	str = (char *)malloc(sizeof(char) * 4 + 1);
    	str[0] = ( 0xf0 | (wc >> 18));
    	str[1] = ( 0x80 | ((wc >> 12) & 0x3f));
    	str[2] = ( 0x80 | ((wc >> 6) & 0x3f));
    	str[3] = ( 0x80 | (wc & 0x3f));
    	*cnt = 4;
    }
	return (str);
}

void print_unicode(t_flgs_types *lst)
{
	char *str;
	int cnt;

	if (check_flg(lst->types, TP_c) && (check_flg(lst->md_lengh, LN_l)))
	{
		str = bin_op_for_unicode(lst, &cnt);
		str[cnt] = '\0';
	}
	print_str(str);
}
