#include "libft.h"
#include "ft_printf.h"

char *ft_flags(char *nbr, t_form type)
{
	char *num;
	int len;

	num = ft_strdup(nbr);
	if (type.prec == -1 && !ft_strcmp(nbr, "0") && ft_strchr("dDipoOuU", type.conv))
		if(!((type.conv == 'o' || type.conv == 'O') && type.hash))
			*num = 0;
	len = ft_strlen(num);
	if (type.prec && type.prec >= len && type.conv != '%')
		num = ft_precision(num, nbr, type, &len);
	if ((type.conv == 'o' || type.conv == 'O') && (type.prec <= 0  || type.prec < len))
		num = ft_add_sharp(num, &len, type);
	if (type.plus  && type.conv != 'u' && (type.width <= len || !type.zero))
		num = ft_add_plus(num, &len, type);
	if (type.space && (type.conv == 'd' || type.conv == 'D' || type.conv == 'i') && (!type.width || type.width <= len) && !type.plus)
		num = ft_one_space(num, &len);
	if (type.width && type.width > len)
		num = ft_add_space_or_zero(num, type.width, type.width - len, type);
	if (type.width && type.space && type.zero && !type.plus && type.conv == 'd')
		*num = ' ';
	if (type.plus && type.zero && ft_atoi(nbr) >= 0)
		*num = '+';
	return (num);
}

char *ft_flags_p(char *nbr, t_form type)
{
	char *num;
	int len;

	num = ft_strdup(nbr);
	if (type.prec == -1 && !ft_strcmp(nbr, "0") && type.conv == 'p')
		*num = 0;
	len = ft_strlen(num);
	if (type.prec && type.prec >= len && type.conv != '%')
		num = ft_precision(num, nbr, type, &len);
	if(type.conv == 'p' && type.zero && type.width > len)
	{
		type.width = type.width - 2;
		num  = ft_memalloc(type.width + 1);
		ft_memset(num, '0', type.width - len);
		num = ft_strcat(num, nbr);
		len = ft_strlen(num);
	}
	num = ft_add_sharp(num, &len, type);
	if (type.width && type.width > len)
		num = ft_add_space_or_zero(num, type.width, type.width - len, type);
	return(num);
}

char *ft_flags_x(char *nbr, t_form type)
{
	char *num;
	int len;
	
	num = ft_strdup(nbr);
	if (type.prec == -1 && !ft_strcmp(nbr, "0"))
		*num = 0;
	len = ft_strlen(num);
	if (type.prec && type.prec > len)
	{
		num  = ft_memalloc(type.prec + 1);
		ft_memset(num, '0', type.prec - len);
		num = ft_strcat(num, nbr);
		len = ft_strlen(num);
	}
	if(type.hash  && type.zero && type.width > len)
	{
		type.width = type.width - 2;
		num  = ft_memalloc(type.width + 1);
		ft_memset(num, '0', type.width - len);
		num = ft_strcat(num, nbr);
		len = ft_strlen(num);
	}
	num = ft_add_sharp(num, &len, type);
	if (type.conv == 'X' && type.conv != 'x')
	 	num = ft_big(num);
	if (type.width && type.width > len)
		num = ft_add_space_or_zero(num, type.width, type.width - len, type);
	return(num);
}

char *ft_precision(char *num, char *nbr, t_form type, int *len)
{
	if (nbr[0] != '-')
	{
		num  = ft_memalloc(type.prec + 1);
		ft_memset(num, '0', type.prec - *len);
		num = ft_strcat(num, nbr);
		*len = ft_strlen(num);
	}
	else
	{
		num  = ft_memalloc(type.prec + 1);
		*num = '-';
		ft_memset(num + 1, '0', type.prec - *len + 1);
		num = ft_strcat(num, nbr + 1);
		*len = ft_strlen(num);

	}
	return(num);
}

void ft_clear_form(t_form *type)
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
