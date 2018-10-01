/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:01:49 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/30 18:01:50 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_add_space(char *src, int len, int nbrspace, t_form *type)
{
	char	*str;
	char	*space;
	char	*z;

	str = NULL;
	space = NULL;
	space = ft_memalloc(nbrspace + 1);
	ft_memset(space, ' ', nbrspace);
	z = src;
	if (type->minus)
		str = ft_conncat(src, space, ft_strlen(src), len);
	else
		str = ft_conncat(space, src, nbrspace, len);
	if (type->conv != 's')
		free(z);
	free(space);
	return (str);
}

char	*ft_add_space_or_zero(char *src, int len, int nbrspace, t_form type)
{
	char	*str;

	str = NULL;
	if (!type.minus && type.zero)
		str = ft_add_zero(src, str, nbrspace, len);
	else
		str = ft_add_space(src, len, nbrspace, &type);
	return (str);
}

char	*ft_add_zero(char *src, char *str, int nbrspace, int len)
{
	char	*z;
	char	*zero;

	zero = ft_memalloc(nbrspace + 1);
	z = src;
	if (*src == '-')
	{
		ft_memset(zero, '0', nbrspace + 1);
		str = ft_strnew(nbrspace + len + 1);
		ft_strncpy(str, zero, nbrspace + 1);
		ft_strncpy(str + nbrspace + 1, src + 1, len - 1);
		str[0] = '-';
	}
	else
	{
		ft_memset(zero, '0', nbrspace);
		str = ft_conncat(zero, src, nbrspace, len);
	}
	free(z);
	free(zero);
	return (str);
}

char	*ft_one_space(char *nbr, int *len)
{
	char	*space;

	if (ft_atoi(nbr) != 0 && nbr[0] != '-')
	{
		space = ft_memalloc(*len + 2);
		space[0] = ' ';
		space = ft_strcat(space, nbr);
		*len = *len + 1;
		free(nbr);
		return (space);
	}
	return (nbr);
}
