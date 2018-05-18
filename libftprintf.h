/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:44:00 by tbondare          #+#    #+#             */
/*   Updated: 2018/05/18 19:00:35 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H_
#define LIBFTPRINTF_H_

#include <unistd.h>
#include <stdlib.h>
#include <inttypes.h>
#include "libft/libft.h"
#include <stdarg.h>
#include <wchar.h>
#include <locale.h>

typedef struct			s_value
{
	long long			lng;
	unsigned long long	ulng;
	void 				*point;
	intmax_t			imax;
	uintmax_t			uimax;
	char				*str;
	long double			lndbl;
	wint_t				win;
}						t_value;

typedef struct			s_flgs_types
{
	char				*str_out;
	int					indx_arg;
	int					flags;
	int					width;
	int					prec;
	int					md_lengh;
	int					types;
	char				wdth_star;
	char				prec_star;
	int					indx_arg_wdth;
	int					indx_arg_prec;
	t_value				val;
	struct s_flgs_types	*next;
}						t_flgs_types;

typedef struct			s_arr_el
{
	char				flg_or_tp_or_ln;
	unsigned int		bit_flg;
}						t_arr_el;

static const char		arr_first = ' ';
static const char		AR_not = 0;
static const char		AR_fl = 1;
static const char		AR_tp = 2;
static const char		AR_ln = 3;

static const int	FL_PLUS = 1;
static const int	FL_MINUS = 2;
static const int	FL_NULL = 4;
static const int	FL_GRILL = 8;
static const int	FL_SPACE = 16;
static const int	FL_QUOTE = 32;

static const int	LN_L = 1;
static const int	LN_hh = 2;
static const int	LN_h = 4;
static const int	LN_l = 8;
static const int	LN_ll = 16;
static const int	LN_j = 32;
static const int	LN_z = 64;

static const int	TP_s = 1;
static const int	TP_S = 2;
static const int	TP_p = 4;
static const int	TP_d = 8;
static const int	TP_D = 16;
static const int	TP_i = 32;
static const int	TP_o = 64;
static const int	TP_O = 128;
static const int	TP_u = 256;
static const int	TP_U = 512;
static const int	TP_x = 1024;
static const int	TP_X = 2048;
static const int	TP_c = 4096;
static const int	TP_C = 8192;
static const int	TP_e = 16384;
static const int	TP_E = 32768;
static const int	TP_f = 65536;
static const int	TP_F = 131072;
static const int	TP_g = 262144;
static const int	TP_G = 524288;
static const int	TP_a = 1048576;
static const int	TP_A = 2097152;
static const int	TP_n = 4194304;
static const int	TP_b = 8388608;
static const int	TP_r = 16777216;
static const int	TP_k = 33554432;

int ft_printf(const char *format, ...);
unsigned int ft_set_flg(unsigned int flags, unsigned int flg);
int ft_check_flg(unsigned int flags, unsigned int flg);
void init_arr(t_arr_el *arr);
unsigned int set_flg(unsigned int flags, unsigned int flg);
int check_flg(unsigned int flags, unsigned int flg);
int fill_struct(t_flgs_types **prm, const char *frmt);
char *itoa_printf(t_flgs_types *lst);
char *itoa_printf_oO_xX_b(t_flgs_types *lst);
void if_flg_not_null_oOxXb(char *newstr, t_flgs_types *lst, int base);
void output_dgt(t_flgs_types *lst, char *newstr, int *mem_w, int base);
int num_qv(t_flgs_types *lst, int cnt);
char *itoa_aA_eE_fF_gG(t_flgs_types *lst);

#endif /* LIBFTPRINTF_H_ */
