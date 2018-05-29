/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cC_sS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:12:55 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 19:20:03 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void print_cC_sS(t_flgs_types *lst)
{
	 int i;
	 char sgn;

	 i = 0;
	 sgn = ' ';
	 if (check_flg(lst->types, TP_c) && !(check_flg(lst->md_lengh, LN_l)))
	 {
		 if (check_flg(lst->flags, FL_MINUS) && lst->width > 1)
		 {
			 write(1, &lst->val.ulng + '0', 1);
			 if (check_flg(lst->flags, FL_NULL))
				 sgn = '0';
			 lst->width = lst->width - 1;
			 while (lst->width--)
				 write(1, &sgn, 1);
		  }
		 else if (lst->width > 1)
		 {
			 if (check_flg(lst->flags, FL_NULL))
				 sgn = '0';
			 lst->width = lst->width - 1;
			 while (lst->width--)
				 write(1, &sgn, 1);
			 write(1, &lst->val.ulng + '0', 1);
		 }
		 else
			 write(1, &lst->val.ulng + '0', 1);
	 }
	 else if (check_flg(lst->types, TP_s) && !(check_flg(lst->md_lengh, LN_l)))
	 {
		 if (check_flg(lst->flags, FL_MINUS) && lst->width > (int)ft_strlen(lst->val.str))
		 {
			 while (lst->val.str || lst->prec)
			 {
				 write (1, &lst->val.str[i], 1);
				 lst->prec--;
				 i++;
				 lst->width--;
			  }
			  if (check_flg(lst->flags, FL_NULL))
				  sgn = '0';
			  while (lst->width--)
				  write(1, &sgn, 1);
		 }
		 else if (lst->width > (int)ft_strlen(lst->val.str))
		 {
			 if (check_flg(lst->flags, FL_NULL))
				 sgn = '0';
			 if (lst->prec < (int)ft_strlen(lst->val.str))
				 lst->width = lst->width - lst->prec;
			 else
				 lst->width = lst->width - ft_strlen(lst->val.str);
			 while (lst->width)
				 write(1, &sgn, 1);
			 while (lst->val.str || lst->prec)
			 {
				 write (1, &lst->val.str[i], 1);
				 lst->prec--;
				 i++;
			 }
		  }
		  else
		  {
			  while (lst->val.str || lst->prec)
			  {
				  write (1, &lst->val.str[i], 1);
				  lst->prec--;
				  i++;
			  }
		  }
	  }
}
