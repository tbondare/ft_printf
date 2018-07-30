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

int		check_sign_dif_tp(t_fl_tp *lst)
{
	if (check_fl(lst->typ, tp_i | tp_d) && check_fl(lst->md_len, ln_j))
		return (lst->val.imx < 0);
	else if (check_fl(lst->typ, tp_u) && check_fl(lst->md_len, ln_j))
		return (0);
	else if (check_fl(lst->typ, tp_i | tp_d | tp_da))
		return (lst->val.ln < 0);
	else if (check_fl(lst->typ, tp_u | tp_ua))
		return (0);
	else if (check_fl(lst->typ, tp_c) && check_fl(lst->md_len, ln_l))
		return (lst->val.win < 0);
	return (0);
}

int		check_is_sign(t_fl_tp *lst, char *neg)
{
	int sign;
	
	sign = 0;
	if (check_fl(lst->flg, fl_plus))
	{
		*neg = check_sign_dif_tp(lst) ? '-' : '+';
		sign = 1;
	}
	else if (check_fl(lst->flg, fl_space))
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

int		num_qv(t_fl_tp *lst, int cnt)
{
	int num_q;
	struct lconv *lc;

	lc = localeconv();
	num_q = 0;
	if (lc->thousands_sep[0] == '\0')
		return (num_q);
	if (check_fl(lst->flg, fl_quote))
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

void	output_dgt(t_fl_tp *lst, char *newstr, int *mem_w, int base)
{
	if (check_fl(lst->typ, tp_i | tp_d) && check_fl(lst->md_len, ln_j))
		outp_id_j(lst, newstr, mem_w);
	else if (check_fl(lst->typ, tp_u | tp_o | tp_x | tp_xa | tp_p)
			&& check_fl(lst->md_len, ln_j))
        outp_uox_xa_j(lst, newstr, mem_w, base);
	else if (check_fl(lst->typ, tp_i | tp_d | tp_da))
		outp_id_da(lst, newstr, mem_w);
	else if (check_fl(lst->typ, tp_u | tp_ua | tp_o | tp_oa
								| tp_x | tp_xa))
		outp_uua_ooa_xxa(lst, newstr, mem_w, base);
	else if (check_fl(lst->typ, tp_c) && check_fl(lst->md_len, ln_l))
		outp_c_l(lst, newstr, mem_w);
	else if (check_fl(lst->typ, tp_p))
		outp_p(lst, newstr, mem_w, base);
}
