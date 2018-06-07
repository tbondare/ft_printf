/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cC_sS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:12:55 by tbondare          #+#    #+#             */
/*   Updated: 2018/06/07 16:20:19 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *print_cC_sS(t_flgs_types *lst)
{
	 int i;
	 int j;
	 char sgn;
	 char *newstr;

	 i = 0;
	 j = 0;
	 sgn = ' ';
	 newstr = NULL;
	 if (lst->val.ulng == NULL)
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
	 if (check_flg(lst->types, TP_c))
	 {
		 if (check_flg(lst->flags, FL_MINUS) && lst->width > 1)
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->width + 1);
			 newstr[i++] = lst->val.ulng + '0';
			 lst->width--;
			 while (lst->width--)
				 newstr[i++] = sgn;
		  }
		 else if (lst->width > 1)
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->width + 1);
			 if (check_flg(lst->flags, FL_NULL))
				 sgn = '0';
			 lst->width--;
			 while (lst->width--)
				 newstr[i++] = sgn;
			 newstr[i++] = lst->val.ulng + '0';
		 }
		 else
		 {
			 newstr = (char*)malloc(sizeof(char) * 2);
			 newstr[i++] = lst->val.ulng + '0';
		 }
		 newstr[i] = '\0';
	 }
	 else if (check_flg(lst->types, TP_s) && lst->val.str != 0)
	 {
		 if (check_flg(lst->flags, FL_MINUS) && lst->width > (int)ft_strlen(lst->val.str))
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->width + 1);
			 if (lst->prec == 0)
				 lst->prec = ft_strlen(lst->val.str);
			 while (lst->val.str[i] && lst->prec > 0)
			 {
				 newstr[i] = lst->val.str[i];
				 lst->prec--;
				 i++;
				 lst->width--;
			  }
			  while (lst->width--)
				  newstr[i++] = sgn;
		 }
		 else if (lst->width > (int)ft_strlen(lst->val.str))
		 {
			 newstr = (char*)malloc(sizeof(char) * lst->width + 1);
			 if (check_flg(lst->flags, FL_NULL))
				 sgn = '0';
			 if (lst->prec < (int)ft_strlen(lst->val.str) && lst->prec > 0)
				 lst->width = lst->width - lst->prec;
			 else
				 lst->width = lst->width - ft_strlen(lst->val.str);
			 while (lst->width--)
				 newstr[i++] = sgn;
			 if (lst->prec == 0)
				 lst->prec = ft_strlen(lst->val.str);
			 while (lst->val.str[j] && lst->prec > 0)
			 {
				 newstr[i] = lst->val.str[j];
				 lst->prec--;
				 i++;
				 j++;
			 }
		  }
		  else
		  {
			  newstr = (char*)malloc(sizeof(char) * (int)ft_strlen(lst->val.str) + 1);
			  if (lst->prec == 0)
				  lst->prec = ft_strlen(lst->val.str);
			  while (lst->val.str[i] && lst->prec > 0)
			  {
				  newstr[i] = lst->val.str[i];
				  lst->prec--;
				  i++;
			  }
		  }
		  newstr[i] = '\0';
	  }
	 return (newstr);
}
