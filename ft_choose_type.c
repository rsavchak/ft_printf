/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:02:18 by rsavchak          #+#    #+#             */
/*   Updated: 2018/10/01 17:02:20 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_chose_type(t_form type, va_list ap, int *res, char *mod)
{
	int	resstr;

	resstr = 0;
	if (type.conv == 'S' || (type.conv == 's' && ft_strchr(type.size, 'l')))
		ft_print_ls(ap, type, res);
	else if (type.conv == 's')
		ft_print_s(ap, type, res);
	else if (type.conv == 'p')
		resstr = ft_print_p(ap, type);
	else if (type.conv == 'c' || type.conv == 'C')
		ft_print_c(ap, type, res);
	else if (type.conv == 'd' || type.conv == 'D' || type.conv == 'i')
		resstr = ft_print_d(ap, type);
	else if (type.conv == 'u' || type.conv == 'U')
		resstr = ft_print_u(ap, type);
	else if (type.conv == 'o' || type.conv == 'O')
		resstr = ft_print_o(ap, type);
	else if (type.conv == 'x' || type.conv == 'X')
		resstr = ft_print_x(ap, type);
	else if (type.conv == '%')
		resstr = ft_print_percent(ap, type);
	else if (type.conv == 'r')
		ft_print_r(type, mod, res);
	return (resstr);
}

void	ft_print_r(t_form type, char *mod, int *res)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (type.width)
	{
		str = ft_memalloc(type.width);
		if (type.zero)
			ft_memset(str, '0', type.width - 1);
		else
			ft_memset(str, ' ', type.width - 1);
	}
	mod = ft_print_r_minus(type, str, mod, res);
	if (str)
		while (str[i++] != '\0')
			*res = *res + 1;
	i = 0;
	while (mod[i++] != '\0')
		*res = *res + 1;
	if (type.width)
		free(str);
}

char	*ft_print_r_minus(t_form type, char *str, char *mod, int *res)
{
	if (!type.minus)
	{
		ft_putstr(str);
		ft_putstr(mod);
	}
	if (type.minus)
	{
		ft_putchar(*mod);
		mod = mod + 1;
		ft_putstr(str);
		ft_putstr(mod);
		*res = *res + 1;
	}
	return (mod);
}
