/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:10:56 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/30 16:10:57 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_s(va_list ap, t_form type, int *res)
{
	char	*string;
	char	o;
	int		k;

	string = NULL;
	k = 0;
	o = ' ';
	if (type.zero && !type.minus)
		o = '0';
	if (ft_negative_prec(ap, type, res) == 1)
		return ;
	string = (va_arg(ap, char *));
	if (!string)
	{
		string = ft_strdup("(null)");
		k = 1;
	}
	ft_print_s_2(string, type, res, o);
	if (k == 1)
		free(string);
}

void	ft_print_s_2(char *string, t_form type, int *res, char o)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(string);
	if (type.prec && type.prec < len)
		len = type.prec;
	if (type.width && type.width > len)
	{
		if (type.minus)
		{
			while (i < len)
				ft_putchar(string[i++]);
		}
		*res = *res + type.width;
		type.width = type.width - len;
		while (type.width--)
			ft_putchar(o);
	}
	else
		*res = *res + len;
	while (i < len)
		ft_putchar(string[i++]);
}

int		ft_negative_prec(va_list ap, t_form type, int *res)
{
	char *string;

	string = NULL;
	if (type.prec == -1)
	{
		string = ft_strnew(type.width);
		if (type.zero)
			ft_memset(string, '0', type.width);
		if (!type.zero)
			ft_memset(string, ' ', type.width);
		ft_putstr(string);
		free(string);
		*res = *res + type.width;
		ap = ap + 2;
		return (1);
	}
	return (0);
}

void	ft_prints_prec(wchar_t *string, t_form type, int *res)
{
	int	i;
	int	len;
	int	k;

	len = 0;
	i = ft_prec_positive(string, type, &len, &k);
	if (type.width && type.width > len)
	{
		if (type.width < type.prec || type.minus)
		{
			while (k <= i)
				ft_unicode_print(string[k++]);
		}
		*res = *res + type.width;
		type.width = type.width - len;
		while (type.width)
		{
			ft_putchar(' ');
			type.width--;
		}
	}
	else
		*res = *res + len;
	while (k <= i)
		ft_unicode_print(string[k++]);
}

int		ft_prec_positive(wchar_t *string, t_form type, int *len, int *k)
{
	int i;

	i = 0;
	*k = 0;
	if (type.prec > 0)
	{
		while (string[i])
		{
			*len = *len + ft_unicode_len(string[i]);
			if (*len <= type.prec)
				i++;
			else
			{
				*len = *len - ft_unicode_len(string[i--]);
				break ;
			}
		}
		return (i);
	}
	return (0);
}
