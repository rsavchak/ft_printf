#include "libft.h"
#include "ft_printf.h"

char *ft_print_percent(va_list ap, t_form type)
{
	char *str = NULL;

	str = ft_strdup("%");
	ap = ap + 2;
	str = ft_flags(str, type);
	return (str);
}

char *ft_print_c(va_list ap, t_form type, int *res)
{
	char *str = NULL;
	char c;

	// if ((ft_strchr(type.size, 'l') || type.conv == 'C'))
	// {
	// 	str = ft_printC(ap, type, res);
	// 	return(str);
	// }
	c = (char)va_arg(ap, int);
	if (c)
	{
		str = ft_strdup(&c);
		if (type.width && type.width > 1)
			str = ft_add_space_or_zero(str, type.width, type.width - 1, type);
	}
	else
	{	
		if (type.width && type.width > 1)
		{

			str = ft_memalloc(type.width);
			if (type.zero && !type.minus)
				ft_memset(str, '0', type.width - 1);
			else 
				ft_memset(str, ' ', type.width - 1);
			ft_putstr(str);
			str = "";
			*res = *res + type.width - 1;
		}
		else
			str = ft_strdup(&c);
		ft_putchar(c);
		*res = *res + 1; 	
	}
	return (str);
}

char *ft_printC(va_list ap, t_form type, int *res)
{
	wint_t c;
	char *str = NULL;
	int len;

	c = (wchar_t)va_arg(ap, wint_t);
	len = ft_unicode_len(c);
	if (type.width && type.width > len)
	{
		str = ft_memalloc(type.width);
		ft_memset(str, ' ', type.width - len);
		if (!type.minus)
		{
			ft_putstr(str);
			str = NULL;
		}
		*res = *res + type.width;
	}
	else
		*res = *res + len;
	ft_unicode_print(c);
	return(str);
}
