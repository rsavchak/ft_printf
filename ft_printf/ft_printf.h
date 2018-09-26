#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <unistd.h>
# include <wchar.h>
# include "libft.h"
#include <stdarg.h>

typedef struct s_form
{
	int minus;
	int plus;
	int zero;
	int space;
	int prec;
	int hash;
	int width;
	char conv;
	char *size;
}	t_form;

int	ft_ptintf(const char *format, ...);
int	vprint(const char *format, va_list ap);
char	*ft_parsing(const char **format, va_list ap, int *res);
char	*ft_chose_type(t_form type, va_list ap, int *res, char *mod);
char	*ft_print_s(va_list ap, t_form type, int *res);
char	*ft_print_d(va_list ap, t_form type);
char	*ft_print_u(va_list ap, t_form type);
char	*ft_print_c(va_list ap, t_form type, int *res);
char	*ft_print_o(va_list ap, t_form type);
char	*ft_print_x(va_list ap, t_form type);
char	*ft_print_p(va_list ap, t_form type);
int	ft_check_flags(char *mod, t_form *type);
void	ft_flag(char mod, char flag, t_form *type, int *count);
void	ft_check_conv(t_form *type, char *mod);
char	*ft_modificator(const char *format, int *k);
int	ft_check_width(char *mod, t_form *type);
int	ft_check_precision(char *mod, t_form *type);
void	ft_clear_form(t_form *type);
int	ft_check_size(char *mod, t_form *type);
char	*ft_add_space(char *src,int len, int nbrSpace, t_form *type);
char	*ft_printC(va_list ap, t_form type, int *res);
char	*ft_printS(va_list ap, t_form type, int *res);
void	ft_unicode_print(wchar_t value);
size_t	ft_unicode_len(wchar_t chr);
char	*ft_flags(char *nbr, t_form type);
char	*ft_add_plus(char *nbr, int *len, t_form type);
char	*ft_add_space_or_zero(char *src,int len, int nbrSpace, t_form type);
char	*ft_big(char *str);
char 	*ft_add_sharp(char *num, int *len, t_form type);
char 	*ft_one_space(char *nbr, int *len);
char	*ft_print_percent(va_list ap, t_form type);
char 	*ft_flags_x(char *nbr, t_form type);
char *ft_precision(char *num, char *nbr, t_form type, int *len);
char  *ft_check_mod(char *mod, int *i, int k);
char *ft_flags_p(char *nbr, t_form type);
void ft_prints_prec(wchar_t* string, t_form type, int *res);
void ft_pars_mod(int *i, char *mod, t_form *type);
char	*ft_conncat(char *res, char *src, size_t l1, size_t l2);


char *ft_print_r(t_form type, char *mod, int *res);

#endif