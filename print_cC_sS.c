/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cca_ssa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:12:55 by tbondare          #+#    #+#             */
/*   Updated: 2018/06/14 13:14:42 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *print_cca_ssa(t_fl_tp *lst)
{
	 int i;
	 int j;
	 char sgn;
	 char *newstr;

	 i = 0;
	 j = 0;
	 sgn = ' ';
	 newstr = NULL;
	 if (check_fl(lst->typ, tp_c))
	 {
		 if (check_fl(lst->flg, fl_minus) && lst->wdth > 1)
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->wdth + 1);
			 newstr[i++] = lst->val.uln;
			 lst->wdth--;
			 while (lst->wdth--)
				 newstr[i++] = sgn;
		  }
		 else if (lst->wdth > 1)
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->wdth + 1);
			 if (check_fl(lst->flg, fl_null))
				 sgn = '0';
			 lst->wdth--;
			 while (lst->wdth--)
				 newstr[i++] = sgn;
			 newstr[i++] = lst->val.uln;
		 }
		 else
		 {
			 newstr = (char*)malloc(sizeof(char) * 2);
			 newstr[i++] = lst->val.uln;
		 }
		 newstr[i] = '\0';
	 }
	 else if (lst->val.str == NULL)
	 {
		 if (lst->prc_star == '-' && lst->wdth > 0)
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->wdth + 1);
			 if (check_fl(lst->flg, fl_null))
				 sgn = '0';
			 while (lst->wdth-- > 0)
				 newstr[i++] = sgn;
			 newstr[i] = '\0';
		 }
		 else
		 {
			 newstr = (char*)malloc(sizeof(char) * 7);
			 newstr[i++] = '(';
			 newstr[i++] = 'n';
			 newstr[i++] = 'u';
			 newstr[i++] = 'l';
			 newstr[i++] = 'l';
			 newstr[i++] = ')';
			 newstr[i] = '\0';
		 }
	 }
	 else if (check_fl(lst->typ, tp_s) && lst->val.str != 0)
	 {
		 if (check_fl(lst->flg, fl_minus) && lst->wdth > (int)ft_strlen(lst->val.str))
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->wdth + 1);
			 if (lst->prc == 0 && lst->prc_star != '-')
				 lst->prc = ft_strlen(lst->val.str);
			 while (lst->val.str[i] && lst->prc > 0)
			 {
				 newstr[i] = lst->val.str[i];
				 lst->prc--;
				 i++;
				 lst->wdth--;
			  }
			  while (lst->wdth--)
				  newstr[i++] = sgn;
		 }
		 else if ((lst->wdth > (int)ft_strlen(lst->val.str) || lst->wdth > lst->prc) && lst->prc_star != '-')
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->wdth + 1);
			 if (check_fl(lst->flg, fl_null))
				 sgn = '0';
			 if (lst->prc < (int)ft_strlen(lst->val.str) && lst->prc > 0 && lst->prc_star != '-')
				 lst->wdth = lst->wdth - lst->prc;
			 else
				 lst->wdth = lst->wdth - ft_strlen(lst->val.str);
			 while (lst->wdth--)
				 newstr[i++] = sgn;
			 if (lst->prc == 0 && lst->prc_star != '-')
				 lst->prc = ft_strlen(lst->val.str);
			 while (lst->val.str[j] && lst->prc > 0)
			 {
				 newstr[i] = lst->val.str[j];
				 lst->prc--;
				 i++;
				 j++;
			 }
		  }
          else if (lst->prc == 0 && lst->prc_star == '-' && lst->wdth > (int)ft_strlen(lst->val.str))
          {
              newstr = (char*)malloc(sizeof(char) * lst->wdth + 1);
              if (check_fl(lst->flg, fl_null))
                  sgn = '0';
              while (lst->wdth--)
                  newstr[i++] = sgn;
          }
		  else
		  {
			  newstr = (char*)malloc(sizeof(char) * (int)ft_strlen(lst->val.str) + 1);
			  if (lst->prc == 0 && lst->prc_star != '-')
				  lst->prc = ft_strlen(lst->val.str);
			  while (lst->val.str[i] && lst->prc > 0)
			  {
				  newstr[i] = lst->val.str[i];
				  lst->prc--;
				  i++;
			  }
		  }
		  newstr[i] = '\0';
	  }
	 return (newstr);
}
