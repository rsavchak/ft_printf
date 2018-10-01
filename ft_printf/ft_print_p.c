/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:42:05 by rsavchak          #+#    #+#             */
/*   Updated: 2018/10/01 17:42:06 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_print_p(va_list ap, t_form type)
{
	char		*str;
	long long	p;
	int			res;

	str = NULL;
	res = 0;
	p = va_arg(ap, long long);
	str = ft_itoa_base(p, 16);
	res = ft_flags_p(str, type);
	return (res);
}
