/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 17:39:57 by rsavchak          #+#    #+#             */
/*   Updated: 2018/10/01 17:39:58 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parsing(const char **format, va_list ap, int *res)
{
	int		i;
	int		resstr;
	char	*mod;
	char	*z;
	t_form	type;

	i = 0;
	resstr = 0;
	mod = ft_modificator(*format, &resstr);
	if (ft_check_mod(mod, &i, resstr) == 0)
	{
		*format = *format + i;
		return (0);
	}
	*format = *format + ft_strlen(mod);
	ft_clear_form(&type);
	ft_pars_mod(&i, mod, &type);
	z = mod;
	mod = mod + i;
	ft_check_conv(&type, mod);
	resstr = ft_chose_type(type, ap, res, mod);
	free(z);
	if (type.size != 0)
		free(type.size);
	return (resstr);
}

void	ft_pars_mod(int *i, char *mod, t_form *type)
{
	int	k;
	int	check;

	k = 0;
	check = 0;
	while (mod[*i] != '\0')
	{
		check = *i;
		k = ft_check_flags(mod + *i, type);
		*i = *i + k;
		k = ft_check_width(mod + *i, type);
		*i = *i + k;
		k = ft_check_precision(mod + *i, type);
		*i = *i + k;
		k = ft_check_size(mod + *i, type);
		*i = *i + k;
		if (check == *i)
			break ;
	}
}

int		ft_check_mod(char *mod, int *i, int k)
{
	const char	*formatstr = "sSpdDioOuUxXcC%0123456789.+-0 #hjlz";

	if (mod != NULL)
	{
		while (mod[*i])
		{
			if (!ft_strchr(formatstr, mod[*i]) && k == 1)
			{
				mod = NULL;
				break ;
			}
			*i = *i + 1;
		}
		if (!mod || *mod == 0)
			return (0);
	}
	*i = 0;
	return (1);
}

char	*ft_modificator(const char *format, int *k)
{
	char		*mod;
	const char	*type = "sSpdDioOuUxXcC%";
	int			i;
	int			j;

	mod = NULL;
	j = 0;
	while (format[j] != '\0')
	{
		i = 0;
		while (type[i])
		{
			if (format[j] == type[i])
			{
				*k = 1;
				mod = ft_strsub(format, 0, j + 1);
				return (mod);
			}
			i++;
		}
		j++;
	}
	mod = ft_strsub(format, 0, j + 1);
	return (mod);
}

void	ft_clear_form(t_form *type)
{
	type->minus = 0;
	type->plus = 0;
	type->zero = 0;
	type->space = 0;
	type->prec = 0;
	type->hash = 0;
	type->width = 0;
	type->conv = 0;
	type->size = NULL;
}
