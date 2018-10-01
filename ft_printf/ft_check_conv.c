/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 18:45:51 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/29 18:46:38 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_check_conv(t_form *type, char *mod)
{
	const char	*convers = "sSpdDioOuUxXcC%";
	int			k;
	int			i;

	k = 0;
	while (convers[k] != '\0')
	{
		i = 0;
		while (mod[i] != '\0')
		{
			if (mod[i] == convers[k])
			{
				type->conv = convers[k];
				break ;
			}
			i++;
		}
		k++;
	}
	if (!type->conv)
		type->conv = 'r';
	if ((type->prec || type->minus) && type->conv != 's' && type->conv != 'S'\
		&& type->conv != 'c' && type->conv != '%' && type->conv != 'r')
		type->zero = 0;
}
