/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbondare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:44:00 by tbondare          #+#    #+#             */
/*   Updated: 2018/07/27 17:38:10 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <inttypes.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>

typedef struct			s_value
{
	long long			lng;
	unsigned long long	ulng;
	void				*point;
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
	int					mem;
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

static const int		FL_PLUS = 1;
static const int		FL_MINUS = 2;
static const int		FL_NULL = 4;
static const int		FL_GRILL = 8;
static const int		FL_SPACE = 16;
static const int		FL_QUOTE = 32;

static const int		LN_L = 1;
static const int		LN_hh = 2;
static const int		LN_h = 4;
static const int		LN_l = 8;
static const int		LN_ll = 16;
static const int		LN_j = 32;
static const int		LN_z = 64;

static const int		TP_s = 1;
static const int		TP_S = 2;
static const int		TP_p = 4;
static const int		TP_d = 8;
static const int		TP_D = 16;
static const int		TP_i = 32;
static const int		TP_o = 64;
static const int		TP_O = 128;
static const int		TP_u = 256;
static const int		TP_U = 512;
static const int		TP_x = 1024;
static const int		TP_X = 2048;
static const int		TP_c = 4096;
static const int		TP_C = 8192;
static const int		TP_e = 16384;
static const int		TP_E = 32768;
static const int		TP_f = 65536;
static const int		TP_F = 131072;
static const int		TP_g = 262144;
static const int		TP_G = 524288;
static const int		TP_a = 1048576;
static const int		TP_A = 2097152;
static const int		TP_n = 4194304;
static const int		TP_b = 8388608;
static const int		TP_r = 16777216;
static const int		TP_k = 33554432;
static const int		TP_pct = 67108864;
static const int		TP_err = 134217728;

void					init_arr(t_arr_el *arr);
void					init_types_2(t_arr_el *arr);
void					init_types_1(t_arr_el *arr);
void					init_length(t_arr_el *arr);
void					init_flags(t_arr_el *arr);

void					determine_md_len(const char *frmt, int *i, t_flgs_types *lst, t_arr_el *arr);
void					determine_width(const char *frmt, int *i, t_flgs_types *lst);
void					determine_precision(const char *frmt, int *i, t_flgs_types *lst);
void					determine_dgt_data(const char *frmt, int *i, t_flgs_types *lst);
char					*create_dgt_str(const char *frmt, int *i);

int						fill_struct(t_flgs_types **prm, const char *frmt);
void					index_args (t_flgs_types *lst);
void					lstnewadd(t_flgs_types **lst);
void					fill_element(t_flgs_types **lst, const char *frmt, int *i);
void					ft_while_determ(t_flgs_types *lst, const char *frmt, int *i, t_arr_el *arr);

unsigned int			set_flg(unsigned int flags, unsigned int flg);
int						check_flg(unsigned int flags, unsigned int flg);
t_flgs_types			*lstnew(void);
char					*rejoin(char *s1, const char c);
char					*ft_strchar(char const *s1, char const c);

void					determ_args_d_i(t_flgs_types *lst, va_list args);
void					determ_args_o_u_xX(t_flgs_types *lst, va_list args);
void					determ_args_n(t_flgs_types *lst, va_list args);
void					determ_args_aA_eE_fF_gG(t_flgs_types *lst, va_list args);
void					dtrm_args_with_if(t_flgs_types *lst, va_list args);

void					determine_args(t_flgs_types *prm, va_list args);
void					ft_if_detetm (t_flgs_types *lst, va_list args, va_list *next, int *i);
int						cnt_args(t_flgs_types *lst);

void					outp_id_j(t_flgs_types *lst, char *newstr, int *mem_w);
void					outp_uoxX_j(t_flgs_types *lst, char *newstr, int *mem_w, int base);
void					outp_idD(t_flgs_types *lst, char *newstr, int *mem_w);
void					outp_c_l(t_flgs_types *lst, char *newstr, int *mem_w);
void					outp_uU_oO_xX(t_flgs_types *lst, char *newstr, int *mem_w, int base);

int						ft_cnt_i_d_uU_c(t_flgs_types *lst);
int						cnt_uU(t_flgs_types *lst, int *cnt);
int						cnt_u_j(t_flgs_types *lst, int *cnt);
int						cnt_id_j(t_flgs_types *lst, int *cnt);
int						cnt_idD(t_flgs_types *lst, int *cnt);

int						cnt_p(t_flgs_types *lst, int *cnt, int base);

void					determine_args(t_flgs_types *prm, va_list args);
int						cnt_args(t_flgs_types *lst);
void					ft_if_detetm(t_flgs_types *lst, va_list args, va_list *next, int *i);

int						ft_printf(const char *format, ...);
int						printing_args(t_flgs_types *prm);
void					print_str(char *str);

char					*quote(char *arr, int cnt);
int						cnt_till_aA_eE_fF_gG(int base, long double *mem_val, t_flgs_types *lst);
int						check_is_sign_in_float(t_flgs_types *lst, char *neg);

char					*outp_float(t_flgs_types *lst, int num_dgt, int cnt, long double *mem_val);

char					*itoa_aA_eE_fF_gG(t_flgs_types *lst);

void					output_dgt(t_flgs_types *lst, char *newstr, int *mem_w, int base);
int						num_qv(t_flgs_types *lst, int cnt);
int						check_is_sign(t_flgs_types *lst, char *neg);
int						check_sign_dif_tp(t_flgs_types *lst);

void					outp_p(t_flgs_types *lst, char *newstr, int *mem_w, int base);

char					*itoa_printf(t_flgs_types *lst);
void					if_flg_not_null (char *newstr, t_flgs_types *lst, int mem_w, char neg);
void					if_flg_null(char *newstr, t_flgs_types *lst, int sum, char neg);
void					if_fl_minus(char *newstr, t_flgs_types *lst, int sum, char neg);

char					*itoa_printf_oO_xX_b(t_flgs_types *lst);
void					if_flg_not_null_oOxXb(char *newstr, t_flgs_types *lst, int base);
void					if_flg_null_oOxXb(char *newstr, t_flgs_types *lst, int cnt, int base);
void					if_fl_minus_oOxXb(char *newstr, t_flgs_types *lst, int cnt, int base);
int						ft_cnt_oO_xX_b(t_flgs_types *lst, int base);
int						cnt_oxX(t_flgs_types *lst, int *cnt, int base);
int						cnt_oxX_j(t_flgs_types *lst, int *cnt, int base);

char					*print_cC_sS(t_flgs_types *lst);

char					*pointer(t_flgs_types *lst);

char					*print_unicode(t_flgs_types *lst);
void					bin_op_for_unicode(t_flgs_types *lst, int *cnt, int i, char *str);
void					uf_in_ucod(int *cnt, wchar_t wc, char *str);

char					*print_pct(t_flgs_types *lst);

#endif
