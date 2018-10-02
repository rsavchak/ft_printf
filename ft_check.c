/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 18:47:51 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/29 18:47:54 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_width(char *mod, t_form *type)
{
	int i;

	i = 0;
	if (ft_isdigit(mod[i]))
	{
		type->width = ft_atoi(mod);
		while (ft_isdigit(mod[i]) == 1)
			i++;
	}
	return (i);
}

int	ft_check_precision(char *mod, t_form *type)
{
	int i;

	i = 0;
	if (mod[i] == '.')
	{
		mod = mod + 1;
		type->prec = ft_atoi(mod);
		while (ft_isdigit(mod[i]) == 1)
			i++;
		i = i + 1;
		if (type->prec == 0)
			type->prec = -1;
	}
	return (i);
}

int	ft_check_size(char *mod, t_form *type)
{
	const char	*sizes = "hljz";
	char		size[3];
	int			j;

	j = 0;
	while (*mod)
	{
		if (ft_strchr(sizes, *mod))
		{
			size[j] = *mod;
			j++;
		}
		mod++;
	}
	size[j] = '\0';
	if (type->size == NULL)
		type->size = ft_strdup(size);
	return (j);
}
