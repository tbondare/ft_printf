/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 16:04:36 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/25 18:40:29 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

unsigned int set_flg(unsigned int flags, unsigned int flg)
{
	flags = flags | flg;
	return (flags);
}

int check_flg(unsigned int flags, unsigned int flg)
{
	if ((flags & flg) != 0)
		return (1);
	return (0);
}

t_flgs_types *lstnew(void)
{
	t_flgs_types *newlist;

	if (!(newlist = (t_flgs_types*)malloc(sizeof(t_flgs_types))))
		return (NULL);
	newlist->str_out = ft_strnew(0);
	newlist->indx_arg = 0;
	newlist->flags = 0;
	newlist->width = 0;
	newlist->prec = 0;
	newlist->md_lengh = 0;
	newlist->types = 0;
	newlist->wdth_star = 0;
	newlist->prec_star = 0;
	newlist->indx_arg_wdth = 0;
	newlist->indx_arg_prec = 0;
	newlist->next = NULL;
	return (newlist);
} 

char *rejoin(char *s1, const char *s2)
{
	char *tmp;
	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

/*int check_is_sign(t_flgs_types *lst, char *neg)
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
} */
