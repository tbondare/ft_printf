/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:13:51 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/29 17:14:33 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char *pointer(t_fl_tp *lst)
{
  unsigned long long int dir;
  int cnt;
  char *str;

  cnt = 0;
  dir = (unsigned long long int)lst->val.pnt;
  if (lst->val.pnt == 0)
      cnt = 6;
  while (dir)
  {
	  dir = dir / 16;
	  cnt++;
  }
  str = (char*)malloc(sizeof(char) * (cnt + 1));
  str[cnt--] = '\0';
  if (lst->val.pnt == 0)
  {
      str[0] = '(';
      str[1] = 'n';
      str[2] = 'u';
      str[3] = 'l';
      str[4] = 'l';
      str[5] = ')';
  }
  else
  {
      cnt = cnt + 2;
      dir = (unsigned long long int)lst->val.pnt;
      while (dir)
      {
          if (dir % 16 > 9)
              str[cnt--] = dir % 16 + 'a' - 10;
          else
              str[cnt--] = dir % 16 + '0';
          dir = dir / 16;
      }
      str[cnt--] = 'x';
      str[cnt--] = '0';
  }
  return (str);
}
