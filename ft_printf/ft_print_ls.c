/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:09:55 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/30 16:09:56 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_print_ls(va_list ap, t_form type, int *res)
{
	wchar_t	*string;
	char	*str;
	char	o;

	if (ft_negative_prec(ap, type, res) == 1)
		return ;
	o = ' ';
	if (type.zero)
		o = '0';
	string = va_arg(ap, wchar_t *);
	if (!string)
	{
		str = ft_strdup("(null)");
		ft_putstr(str);
		*res = *res + 6;
		free(str);
		return ;
	}
	if (type.prec)
	{
		ft_prints_prec(string, type, res);
		return ;
	}
	ft_print_ls_2(string, type, res, o);
}

void	ft_print_ls_2(wchar_t *string, t_form type, int *res, char o)
{
	int i;
	int len;

	i = 0;
	while (string[i])
		len = len + ft_unicode_len(string[i++]);
	i = 0;
	if (type.width && type.width > len)
	{
		if (type.minus)
		{
			while (string[i] != '\0')
				ft_unicode_print(string[i++]);
		}
		*res = *res + type.width;
		type.width = type.width - len;
		while (type.width--)
			ft_putchar(o);
	}
	else
		*res = *res + len;
	while (string[i] != '\0')
		ft_unicode_print(string[i++]);
}
