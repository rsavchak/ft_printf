/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sharp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 18:00:49 by rsavchak          #+#    #+#             */
/*   Updated: 2018/09/30 18:00:51 by rsavchak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_add_sharp(char *num, int *len, t_form type)
{
	char	*sharp;
	int		i;
	int		templen;

	i = 0;
	if ((type.conv == 'o' || type.conv == 'O') \
		&& type.hash && ft_atoi(num) != 0)
	{
		while (num[i] != '\0')
			i++;
		sharp = ft_memalloc(i + 2);
		sharp[0] = '0';
		sharp = ft_strcat(sharp, num);
		*len = *len + 1;
		free(num);
		return (sharp);
	}
	templen = *len;
	if (type.conv == 'p' || (type.hash && ft_atoi(num) != 0))
		num = ft_add_sharp_ox(num, &templen);
	*len = templen;
	return (num);
}

char	*ft_add_sharp_ox(char *num, int *len)
{
	int		i;
	char	*sharp;

	sharp = NULL;
	i = 0;
	while (num[i] != '\0')
		i++;
	sharp = ft_memalloc(i + 3);
	sharp[0] = '0';
	sharp[1] = 'x';
	sharp = ft_strcat(sharp, num);
	*len = *len + 2;
	free(num);
	return (sharp);
}

char	*ft_add_plus(char *nbr, int *len, t_form type)
{
	char	*plus;

	if (nbr[0] != '-' && type.conv != 'o' && type.conv != 'O')
	{
		plus = ft_memalloc(*len + 2);
		plus[0] = '+';
		plus = ft_strcat(plus, nbr);
		*len = *len + 1;
		free(nbr);
		return (plus);
	}
	return (nbr);
}

char	*ft_conncat(char *res, char *src, size_t l1, size_t l2)
{
	char	*str;
	size_t	size;

	size = l1 + l2;
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	if (res)
		ft_strncpy(str, res, l1);
	ft_strncpy(str + l1, src, l2);
	return (str);
}
