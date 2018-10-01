/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 17:00:10 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/30 17:00:12 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_flags_x(char *nbr, t_form type)
{
	char	*num;
	int		len;
	int		res;

	res = 0;
	num = ft_strdup(nbr);
	if (type.prec == -1 && !ft_strcmp(nbr, "0"))
		*num = 0;
	len = ft_strlen(num);
	num = ft_flags_add_x(type, nbr, num, &len);
	num = ft_add_sharp(num, &len, type);
	if (type.conv == 'X' && type.conv != 'x')
		num = ft_big(num);
	if (type.width && type.width > len)
		num = ft_add_space_or_zero(num, type.width, type.width - len, type);
	ft_putstr(num);
	res = ft_strlen(num);
	if (num != 0)
		free(num);
	if (nbr != 0)
		free(nbr);
	return (res);
}

char	*ft_big(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		num[i] = ft_toupper(num[i]);
		i++;
	}
	return (num);
}

char	*ft_flags_add_x(t_form type, char *nbr, char *num, int *len)
{
	char	*z;
	int		templen;

	templen = *len;
	if (type.prec && type.prec > templen)
	{
		z = num;
		num = ft_memalloc(type.prec + 1);
		ft_memset(num, '0', type.prec - templen);
		num = ft_strcat(num, nbr);
		templen = ft_strlen(num);
		free(z);
	}
	if (type.hash && type.zero && type.width > templen)
	{
		z = num;
		type.width = type.width - 2;
		num = ft_memalloc(type.width + 1);
		ft_memset(num, '0', type.width - templen);
		num = ft_strcat(num, nbr);
		templen = ft_strlen(num);
		free(z);
	}
	*len = templen;
	return (num);
}
