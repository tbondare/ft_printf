/*
 * libftprintf.c
 *
 *  Created on: 9 февр. 2018 г.
 *      Author: Татьяна
 */

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

char *create_dgt_str(const char *frmt, int *i)
{
	char *num;
	char str[2];

	str[1] = '\0';
	num = ft_strnew(0);
	while(frmt[*i] && (frmt[*i] >= '0' && frmt[*i] <= '9'))
	{
		str[0] = frmt[*i];
		num = rejoin(num, str);
		(*i)++;
	}
	return (num);
}

void determine_dgt_data(const char *frmt, int *i, t_flgs_types *lst)
{
	char *num;

	num = create_dgt_str(frmt, i);
	if (frmt[*i] == '$')
		lst->indx_arg = ft_atoi(num);
	else
	{
		lst->width = ft_atoi(num);
		(*i)--;
	}
	free(num);
}

void lstnewadd(t_flgs_types **lst)
{
	(*lst)->next = lstnew();
	*lst = (*lst)->next;
}

void determine_precision(const char *frmt, int *i, t_flgs_types *lst)
{
	char *num;

	(*i)++;
	if ((frmt[*i] < '0' || frmt[*i] > '9') && frmt[*i] != '*')
	{
		lst->prec = 0;
		(*i)--;
		return ;
	}
	if ((frmt[*i] == '*'))
	{
		lst->prec_star = '*';
		if (frmt[(*i) + 1] < '0' || frmt[(*i) + 1] > '9')
			return ;
		(*i)++;
	}
	num = create_dgt_str(frmt, i);
	lst->prec = ft_atoi(num);
	free(num);
	if (lst->prec_star != '*')
		(*i)--;
}

void determine_width(const char *frmt, int *i, t_flgs_types *lst)
{
	char *num;

	lst->wdth_star = '*';
	if ((frmt[(*i) + 1] < '0' || frmt[(*i) + 1] > '9'))
			return ;
	(*i)++;
	num = create_dgt_str(frmt, i);
	lst->width = ft_atoi(num);
	free(num);
}

void determine_md_len(const char *frmt, int *i, t_flgs_types *lst, t_arr_el *arr)
{
	if (frmt[*i] == 'h' && frmt[(*i) + 1] == 'h')
	{
		(*lst).md_lengh = set_flg((*lst).md_lengh, LN_hh);
		(*i)++;
	}
	else if (frmt[*i] == 'l' && frmt[(*i) + 1] == 'l')
	{
		(*lst).md_lengh = set_flg((*lst).md_lengh, LN_ll);
		(*i)++;
	}
	else
		(*lst).md_lengh = set_flg((*lst).md_lengh, arr[frmt[*i] - arr_first].bit_flg);
}

void fill_element(t_flgs_types **lst, const char *frmt, int *i)
{
	static t_arr_el arr[91];
	static char init = 0;

	(*i)++;
	if(init == 0)
	{
		init_arr(arr);
		init = 1;
	}
	if (frmt[*i] == '%')
	{
		(*lst)->str_out = rejoin((*lst)->str_out, "%");
		return ;
	}
	if (ft_strlen((*lst)->str_out) != 0 || (*lst)->types != 0)
		lstnewadd(lst);
	while (frmt[*i] != '\0')
	{
		if (frmt[*i] > '0' && frmt[*i] <= '9')
			determine_dgt_data(frmt, i, *lst);
		else if (frmt[*i] == '*')
			determine_width(frmt, i, *lst);
		else if (frmt[*i] == '.')
			determine_precision(frmt, i, *lst);
		else if (arr[frmt[*i] - arr_first].flg_or_tp_or_ln == AR_fl)
			(*lst)->flags = set_flg((*lst)->flags, arr[frmt[*i] - arr_first].bit_flg);
		else if (arr[frmt[*i] - arr_first].flg_or_tp_or_ln == AR_ln)
			determine_md_len(frmt, i, *lst, arr);
		else if (arr[frmt[*i] - arr_first].flg_or_tp_or_ln == AR_tp)
		{
			(*lst)->types = set_flg((*lst)->types, arr[frmt[*i] - arr_first].bit_flg);
			return ;
		}
		(*i)++;
	}
}

void index_args (t_flgs_types *lst)
{
	int cnt;

	cnt = 1;
	while (lst)
	{
		if (lst->wdth_star == '*' && lst->width == 0) //если есть звезда без $;
		{
			lst->indx_arg_wdth = cnt;
			cnt++;
		}
		if (lst->prec_star == '*' && lst->prec == 0)
		{
			lst->indx_arg_prec = cnt;
			cnt++;
		}
		if (lst->indx_arg == 0 && lst->types != 0)
		{
			lst->indx_arg = cnt;
			cnt++;
		}
		lst = lst->next;
	}
}

int fill_struct(t_flgs_types **prm, const char *frmt)
{
	int i;
	t_flgs_types *lst;

	i = 0;
	if (!(*prm = lstnew()))
		return (0);
	lst = *prm;
	while (frmt[i] != '\0')
	{
		if (frmt[i] == '%')
			fill_element(&lst, frmt, &i);
		else
		{
			if (lst->types != 0)
				lstnewadd(&lst);
			lst->str_out = rejoin(lst->str_out, &frmt[i]);
		}
		i++;
	}
	index_args (lst);
	return (1);
}

