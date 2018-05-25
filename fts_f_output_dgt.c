/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_f_output_dgt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 18:16:44 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/25 18:33:06 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void outp_id_j(t_flgs_types *lst, char *newstr, int *mem_w)
{
	int i;
	struct lconv *lc;
	lc = localeconv();
	
	i = 0;
	lst->val.imax = lst->val.imax < 0 ? -lst->val.imax : lst->val.imax;
	lst->val.imax == 0 ? newstr[*mem_w] = '0' : 0;
	while (lst->val.imax)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		newstr[(*mem_w)--] = lst->val.imax % 10 + '0';
		lst->val.imax  = lst->val.imax / 10;
		i++;
	}
}

void outp_uoxX_j(t_flgs_types *lst, char *newstr, int *mem_w, int base)
{
	int i;
	struct lconv *lc;
	
	lc = localeconv();
	i = 0;
	lst->val.uimax == 0 ? newstr[*mem_w] = '0' : 0;
	while (lst->val.uimax)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		if (check_flg(lst->types, TP_x) && lst->val.uimax % base > 9)
			newstr[(*mem_w)--] = lst->val.uimax % base + 'a' - 10;
		else if(check_flg(lst->types, TP_X) && lst->val.uimax % base > 9)
			newstr[(*mem_w)--] = lst->val.uimax % base + 'A' - 10;
		else
			newstr[(*mem_w)--] = lst->val.uimax % base + '0';
		lst->val.uimax  = lst->val.uimax / base;
		i++;
	}
}

void outp_idD(t_flgs_types *lst, char *newstr, int *mem_w)
{
	int i;
	struct lconv *lc;
	
	lc = localeconv();
	i = 0;
	lst->val.lng = lst->val.lng < 0 ? -lst->val.lng : lst->val.lng;
	lst->val.lng == 0 ? newstr[*mem_w] = '0' : 0;
	while (lst->val.lng)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		newstr[(*mem_w)--] = lst->val.lng % 10 + '0';
		lst->val.lng  = lst->val.lng / 10;
		i++;
	}
}

void outp_c_l(t_flgs_types *lst, char *newstr, int *mem_w)
{
	int i;
	struct lconv *lc;
	
	lc = localeconv();
	i = 0;
	lst->val.win == 0 ? newstr[*mem_w] = '0' : 0;
	lst->val.win = lst->val.win < 0 ? -lst->val.win : lst->val.win;
	while (lst->val.win)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		newstr[(*mem_w)--] = lst->val.win % 10 + '0';
		lst->val.win  = lst->val.win / 10;
		i++;
	}
}

void outp_uU_oO_xX(t_flgs_types *lst, char *newstr, int *mem_w)
{
	int i;
	struct lconv *lc;
	
	lc = localeconv();
	lst->val.ulng == 0 ? newstr[*mem_w] = '0' : 0;
	while (lst->val.ulng)
	{
		if (check_flg(lst->flags, FL_QUOTE) && i != 0 && i % 3 == 0 && lc->thousands_sep[0] != '\0')
			newstr[(*mem_w)--] = *(lc->thousands_sep);
		if (check_flg(lst->types, TP_x) && lst->val.ulng % base > 9)
			newstr[(*mem_w)--] = lst->val.ulng % base + 'a' - 10;
		else if(check_flg(lst->types, TP_X) && lst->val.ulng % base > 9)
			newstr[(*mem_w)--] = lst->val.ulng % base + 'A' - 10;
		else
			newstr[(*mem_w)--] = lst->val.ulng % base + '0';
		lst->val.ulng  = lst->val.ulng / base;
		i++;
	}
}