/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:54:23 by rsavchak          #+#    #+#             */
/*   Updated: 2018/10/01 17:54:24 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include "libft.h"
# include <wchar.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_form
{
	int			minus;
	int			plus;
	int			zero;
	int			space;
	int			prec;
	int			hash;
	int			width;
	char		conv;
	char		*size;
}				t_form;

int				ft_ptintf(const char *format, ...);
int				vprint(const char *format, va_list ap, int total, int i);
int				ft_parsing(const char **format, va_list ap, int *res);
int				ft_chose_type(t_form type, va_list ap, int *res, char *mod);
int				ft_print_d(va_list ap, t_form type);
int				ft_print_u(va_list ap, t_form type);
int				ft_print_o(va_list ap, t_form type);
int				ft_print_x(va_list ap, t_form type);
int				ft_print_p(va_list ap, t_form type);
int				ft_check_flags(char *mod, t_form *type);
int				ft_check_width(char *mod, t_form *type);
int				ft_check_precision(char *mod, t_form *type);
int				ft_check_size(char *mod, t_form *type);
int				ft_flags(char *nbr, t_form type);
int				ft_check_mod(char *mod, int *i, int k);
int				ft_flags_p(char *nbr, t_form type);
int				ft_print_percent(va_list ap, t_form type);
int				ft_flags_x(char *nbr, t_form type);
int				ft_negative_prec(va_list ap, t_form type, int *res);
int				ft_prec_positive(wchar_t *string, t_form type,\
	int *len, int *k);
void			ft_print_s(va_list ap, t_form type, int *res);
void			ft_print_s_2(char *string, t_form type, int *res, char o);
void			ft_print_c(va_list ap, t_form type, int *res);
void			ft_flag(char mod, char flag, t_form *type, int *count);
void			ft_check_conv(t_form *type, char *mod);
void			ft_clear_form(t_form *type);
void			ft_print_lc(va_list ap, t_form type, int *res);
void			ft_print_ls(va_list ap, t_form type, int *res);
void			ft_unicode_print(wchar_t value);
void			ft_prints_prec(wchar_t *string, t_form type, int *res);
void			ft_pars_mod(int *i, char *mod, t_form *type);
void			ft_print_ls_2(wchar_t *string, t_form type, int *res, char o);
void			ft_print_r(t_form type, char *mod, int *res);
char			*ft_modificator(const char *format, int *k);
char			*ft_add_space(char *src, int len, int nbrspace, t_form *type);
char			*ft_add_plus(char *nbr, int *len, t_form type);
char			*ft_add_space_or_zero(char *src, int len, int nbrspace, \
	t_form type);
char			*ft_big(char *str);
char			*ft_add_sharp(char *num, int *len, t_form type);
char			*ft_one_space(char *nbr, int *len);
char			*ft_precision(char *num, char *nbr, t_form type, int *len);
char			*ft_str_add(char *res, char *src, size_t len1, size_t len2);
char			*ft_flags_add(t_form type, char *num, char *nbr);
char			*ft_flags_add_p(t_form type, char *nbr, char *num, int *len);
char			*ft_flags_add_x(t_form type, char *nbr, char *num, int *len);
char			*ft_big(char *num);
char			*ft_add_sharp_ox(char *num, int *len);
char			*ft_add_zero(char *src, char *str, int nbrspace, int len);
char			*ft_print_r_minus(t_form type, char *str, char *mod, int *res);
size_t			ft_unicode_len(wchar_t chr);

#endif
