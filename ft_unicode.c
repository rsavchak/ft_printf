/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:07:59 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/30 16:08:01 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_unicode_len(wchar_t chr)
{
	size_t count;

	count = 0;
	if (chr <= 127)
		count++;
	else if (chr <= 2047)
		count = count + 2;
	else if (chr <= 65535)
		count = count + 3;
	else
		count = count + 4;
	return (count);
}

void	ft_unicode_print(wchar_t value)
{
	if (value <= 127)
		ft_putchar(value);
	else if (value <= 2047)
	{
		ft_putchar(192 | (value >> 6));
		ft_putchar(128 | (value & 63));
	}
	else if (value <= 65535)
	{
		ft_putchar(224 | (value >> 12));
		ft_putchar(128 | ((value >> 6) & 63));
		ft_putchar(128 | (value & 63));
	}
	else
	{
		ft_putchar(240 | (value >> 18));
		ft_putchar(128 | ((value >> 12) & 63));
		ft_putchar(128 | ((value >> 6) & 63));
		ft_putchar(128 | (value & 63));
	}
}
