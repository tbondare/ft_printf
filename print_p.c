/*
 * print_p.c
 *
 *  Created on: 27 ���. 2018 �.
 *      Author: �������
 */

#include "libftprintf.h"

char *pointer(t_flgs_types *lst)
{
  unsigned long long int dir;
  int cnt;
  char *str;

  cnt = 0;
  dir = (unsigned long long int)lst->val.point;
  while (dir)
  {
	  dir = dir / 16;
	  cnt++;
  }
  cnt = cnt + 2;
  dir = (unsigned long long int)lst->val.point;
  str = (char*)malloc(sizeof(char) * (cnt + 1));
  str[cnt--] = '\0';
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
  return (str);
}
