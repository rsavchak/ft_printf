/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:11:15 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/30 18:11:16 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	ap;
	int		total;
	int		i;

	i = 0;
	total = 0;
	va_start(ap, format);
	count = vprint(format, ap, total, i);
	va_end(ap);
	return (count);
}

int	vprint(const char *format, va_list ap, int total, int i)
{
	int			length;
	static char	*text;
	int			res;

	res = 0;
	while (format[i])
	{
		i = 0;
		length = 0;
		while (format[i] != '%' && format[i] != '\0')
			i++;
		text = ft_strsub(format, length, i);
		ft_putstr(text);
		res = res + ft_strlen(text);
		free(text);
		if (format[i] == '%')
		{
			format = format + i + 1;
			total = ft_parsing(&format, ap, &res);
			res = res + total;
			i = 0;
		}
	}
	return (res);
}
