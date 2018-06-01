/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fns_for_ddgt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:49:20 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:26:35 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

int check_sign_dif_tp(t_flgs_types *lst)
{
	if (check_flg(lst->types, TP_i | TP_d) && check_flg(lst->md_lengh, LN_j))
		return (lst->val.imax < 0);
	else if (check_flg(lst->types, TP_u) && check_flg(lst->md_lengh, LN_j))
		return (0);
	else if (check_flg(lst->types, TP_i | TP_d | TP_D))
		return (lst->val.lng < 0);
	else if (check_flg(lst->types, TP_u | TP_U))
		return (0);
	else if (check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l))
		return (lst->val.win < 0);
	return (0);
}

int check_is_sign(t_flgs_types *lst, char *neg)
{
	int sign;
	
	sign = 0;
	if (check_flg(lst->flags, FL_PLUS))
	{
		*neg = check_sign_dif_tp(lst) ? '-' : '+';
		sign = 1;
	}
	else if (check_flg(lst->flags, FL_SPACE))
	{
		*neg = check_sign_dif_tp(lst) ? '-' : ' ';
		sign = 1;
	}
	else if (check_sign_dif_tp(lst))
	{
		*neg = '-';
		sign = 1;
	}
	else
		*neg = 0;
	return (sign);
}

int num_qv(t_flgs_types *lst, int cnt)
{
	int num_q;
	struct lconv *lc;

	lc = localeconv();
	num_q = 0;
	if (lc->thousands_sep[0] == '\0')
		return (num_q);
	if (check_flg(lst->flags, FL_QUOTE))
	{
		if (cnt > 3)
		{
			if (cnt % 3 == 0)
				num_q = cnt / 3 - 1;
			else
				num_q = cnt / 3;
		}
	}
	return (num_q);
}

 void output_dgt(t_flgs_types *lst, char *newstr, int *mem_w, int base)
{
//	int i;
//	struct lconv *lc;
	
//	i = 0;
	if (check_flg(lst->types, TP_i | TP_d) && check_flg(lst->md_lengh, LN_j))
		outp_id_j(lst, newstr, mem_w);
	else if (check_flg(lst->types, TP_u | TP_o | TP_x | TP_X) 
			&& check_flg(lst->md_lengh, LN_j))
		outp_uoxX_j(lst, newstr, mem_w, base);
	else if (check_flg(lst->types, TP_i | TP_d | TP_D))
		outp_idD(lst, newstr, mem_w);
	else if (check_flg(lst->types, TP_u | TP_U | TP_o | TP_O | TP_x | TP_X))
		outp_uU_oO_xX(lst, newstr, mem_w, base);
	else if (check_flg(lst->types, TP_c) && check_flg(lst->md_lengh, LN_l))
		outp_c_l(lst, newstr, mem_w);
}
