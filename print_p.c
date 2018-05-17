/*
 * print_p.c
 *
 *  Created on: 27 мар. 2018 г.
 *      Author: Татьяна
 */

#include "libftprintf.h"

char *pointer(t_flgs_types *lst)
{
  unsigned long long int dir;
  int n;
  int cnt;
  char *str;
  int i;

  cnt = 0;
  i = 0;
  dir = &(lst->val.point);
  n = dir;
  while (n)
  {
	  n = n / 16;
	  cnt++;
  }
  str = (char*)malloc(sizeof(char) * (cnt + 1));
  while (dir)
  {
	  if (dir % 16 > 9)
		  str[i] = dir % 16 + 'A' - 10;
	  else
		  str[i] = dir % 16;
	  dir = dir / 16;
	  i++;
  }
  str[i] = '\0';
  return (str);
}

void print_p(t_flgs_types *lst)
{

}
