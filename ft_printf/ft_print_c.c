/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 19:03:31 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/29 19:03:33 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_print_percent(va_list ap, t_form type)
{
	char	*str;
	int		res;

	res = 0;
	str = NULL;
	str = ft_strdup("%");
	ap = ap + 2;
	res = ft_flags(str, type);
	return (res);
}

void	ft_print_c(va_list ap, t_form type, int *res)
{
	char c;
	char o;

	o = ' ';
	if (type.zero)
		o = '0';
	if ((ft_strchr(type.size, 'l') || type.conv == 'C'))
	{
		ft_print_lc(ap, type, res);
		return ;
	}
	c = (char)va_arg(ap, int);
	if (type.width && type.width > 1)
	{
		if (type.minus)
			ft_putchar(c);
		*res = *res + type.width;
		type.width = type.width - 1;
		while (type.width--)
			ft_putchar(o);
	}
	else
		*res = *res + 1;
	if (!type.minus)
		ft_putchar(c);
}

void	ft_print_lc(va_list ap, t_form type, int *res)
{
	wint_t	c;
	int		len;
	char	o;

	o = ' ';
	if (type.zero)
		o = '0';
	c = (wchar_t)va_arg(ap, wint_t);
	len = ft_unicode_len(c);
	if (type.width && type.width > len)
	{
		if (type.minus)
			ft_unicode_print(c);
		*res = *res + type.width;
		type.width = type.width - 1;
		while (type.width--)
			ft_putchar(o);
	}
	else
		*res = *res + len;
	if (!type.minus)
		ft_unicode_print(c);
}
