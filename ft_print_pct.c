/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 19:58:25 by tbondare          #+#    #+#             */
/*   Updated: 2018/08/02 17:40:58 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_if_print_pct(t_fl_tp *lst, char *str, int *i)
{
	if (check_fl(lst->flg, fl_minus) || (check_fl(lst->flg, fl_minus) &&
				(check_fl(lst->flg, fl_null))))
	{
		str[(*i)++] = '%';
		while (lst->wdth > *i)
			str[(*i)++] = ' ';
	}
	else if (check_fl(lst->flg, fl_null))
	{
		while (*i < lst->wdth - 1)
			str[(*i)++] = '0';
		str[(*i)++] = '%';
	}
	else if (lst->wdth > 0 || check_fl(lst->flg, fl_space))
	{
		while (*i < lst->wdth - 1)
			str[(*i)++] = ' ';
		str[(*i)++] = '%';
	}
	else
		str[(*i)++] = '%';
}

char	*print_pct(t_fl_tp *lst)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (lst->wdth == 0)
		str = (char*)malloc(sizeof(char) * 2);
	str = (char*)malloc(sizeof(char) * lst->wdth + 1);
	ft_if_print_pct(lst, str, &i);
	str[i] = '\0';
	return (str);
}
