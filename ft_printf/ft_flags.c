/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 18:52:39 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/29 18:52:40 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_flags(char *nbr, t_form type)
{
	char	*num;
	int		res;

	res = 0;
	num = ft_strdup(nbr);
	if (type.prec == -1 && !ft_strcmp(nbr, "0") \
		&& ft_strchr("dDipoOuU", type.conv))
		if (!((type.conv == 'o' || type.conv == 'O') && type.hash))
			*num = 0;
	num = ft_flags_add(type, num, nbr);
	if (type.width && type.space && type.zero && !type.plus && type.conv == 'd')
		*num = ' ';
	if (type.plus && type.zero && ft_atoi(nbr) >= 0)
		*num = '+';
	ft_putstr(num);
	res = ft_strlen(num);
	if (nbr != 0)
		free(nbr);
	if (num != 0)
		free(num);
	return (res);
}

char	*ft_flags_add(t_form type, char *num, char *nbr)
{
	char	*z;
	int		len;

	len = ft_strlen(num);
	if (type.prec && type.prec >= len && type.conv != '%')
	{
		z = num;
		num = ft_precision(num, nbr, type, &len);
		free(z);
	}
	if ((type.conv == 'o' || type.conv == 'O')\
		&& (type.prec <= 0 || type.prec < len))
		num = ft_add_sharp(num, &len, type);
	if (type.plus && type.conv != 'u' && (type.width <= len || !type.zero))
		num = ft_add_plus(num, &len, type);
	if (type.space && (type.conv == 'd' || type.conv == 'D' \
		|| type.conv == 'i')\
		&& (!type.width || type.width <= len) && !type.plus)
		num = ft_one_space(num, &len);
	if (type.width && type.width > len)
		num = ft_add_space_or_zero(num, type.width, type.width - len, type);
	return (num);
}

int		ft_flags_p(char *nbr, t_form type)
{
	char	*num;
	int		len;
	int		res;

	res = 0;
	num = ft_strdup(nbr);
	if (type.prec == -1 && !ft_strcmp(nbr, "0") && type.conv == 'p')
		*num = 0;
	len = ft_strlen(num);
	num = ft_flags_add_p(type, nbr, num, &len);
	num = ft_add_sharp(num, &len, type);
	len = ft_strlen(num);
	if (type.width && type.width > len)
		num = ft_add_space_or_zero(num, type.width, type.width - len, type);
	ft_putstr(num);
	res = ft_strlen(num);
	if (nbr != 0)
		free(nbr);
	if (num != 0)
		free(num);
	return (res);
}

char	*ft_flags_add_p(t_form type, char *nbr, char *num, int *len)
{
	char	*z;
	int		templen;

	templen = *len;
	if (type.prec && type.prec >= templen && type.conv != '%')
	{
		z = num;
		num = ft_precision(num, nbr, type, &templen);
		free(z);
	}
	if (type.conv == 'p' && type.zero && type.width > templen)
	{
		type.width = type.width - 2;
		num = ft_memalloc(type.width + 1);
		ft_memset(num, '0', type.width - templen);
		num = ft_strcat(num, nbr);
		*len = ft_strlen(num);
	}
	return (num);
}

char	*ft_precision(char *num, char *nbr, t_form type, int *len)
{
	if (nbr[0] != '-')
	{
		num = ft_memalloc(type.prec + 1);
		ft_memset(num, '0', type.prec - *len);
		num = ft_strcat(num, nbr);
		*len = ft_strlen(num);
	}
	else
	{
		num = ft_memalloc(type.prec + 1);
		*num = '-';
		ft_memset(num + 1, '0', type.prec - *len + 1);
		num = ft_strcat(num, nbr + 1);
		*len = ft_strlen(num);
	}
	return (num);
}
