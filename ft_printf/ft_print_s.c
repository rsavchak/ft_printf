#include "libft.h"
#include "ft_printf.h"

char *ft_print_s(va_list ap, t_form type, int *res)
{
	char *string;
	int len;

	if (type.prec == -1)
	{	string = ft_strnew(type.width);
		if (type.zero)
			ft_memset(string, '0', type.width);
		if (!type.zero)
			ft_memset(string, ' ', type.width);
		ap = ap + 2;
		return(string);
	}
	if ((ft_strchr(type.size, 'l') || type.conv == 'S'))
	{
		string = ft_printS(ap, type, res);
		return(string);
	}
	string = (va_arg(ap, char *));
	if (!string)
		string = ft_strdup("(null)");
	len = ft_strlen(string);
	if (type.prec && type.prec < len)
	{
		string = ft_strsub(string, 0, type.prec);
		len = ft_strlen(string);
	}
	if (type.width && type.width > len)
		string = ft_add_space_or_zero(string, type.width, type.width - len, type);
	if (string)
		return(string);
	return (NULL);
}

void ft_unicode_print(wchar_t value)
{
	if (value <= 127)
		ft_putchar(value);
	else if (value <= 2047)
	{
		ft_putchar(192 | (value >> 6)); 
		ft_putchar(128 | (value & 63));
	}
	else if (value <= 65535)
	{
		ft_putchar(224 | (value >> 12));
		ft_putchar(128 | ((value >> 6) & 63));
		ft_putchar(128 | (value & 63));
	}
	else
	{
		ft_putchar(240 | (value >> 18));
		ft_putchar(128 | ((value >> 12) & 63));
		ft_putchar(128 | ((value >> 6) & 63));
		ft_putchar(128 | (value & 63));
	}
}

void ft_prints_prec(wchar_t* string, t_form type, int *res)
{
	int i;
	int len = 0;
	int k = 0;

	i = 0;	
	if (type.prec > 0)
	{
		while (string[i])
		{	
			len = len + ft_unicode_len(string[i]);
			if(len <= type.prec)
				i++;
			else
			{
				len = len - ft_unicode_len(string[i]);
				i--;
				break;
			}
		}
	}
	if (type.width && type.width > len )
	{
		if (type.width < type.prec)
		{
			while (k <= i)
			{
				ft_unicode_print(string[k]);
				k++;
			}
		}
		*res = *res + type.width;
		type.width = type.width - len;
		while(type.width)
		{	
			ft_putchar(' ');
			type.width--;
		}
	}
	else	
		*res = *res + len;
	while (k <= i)
		{
			ft_unicode_print(string[k]);
			k++;
		}
}


char	*ft_printS(va_list ap, t_form type, int *res)
{
	wchar_t *string;
	int len = 0;
	char* str = NULL;
	int i = 0;

	string = va_arg(ap, wchar_t *);
	if (!string)
		return("(null)");
	if (type.prec)
	{
		ft_prints_prec(string, type, res);
		return(str);
	}
	while (string[i])
	{
		len = len + ft_unicode_len(string[i]);
		i++;
	}
		if (type.width && type.width > len)
	{
		str = ft_memalloc(type.width - len + 1);
		if (!type.minus && type.zero)
			ft_memset(str, '0', type.width - len);
		if (!type.zero)
			ft_memset(str, ' ', type.width - len);
		if (!type.minus)
		{
			ft_putstr(str);
			str = NULL;
			*res = *res + type.width;
		}
		else
			*res = *res + len;	
	}
	else
		*res = *res + len;
	i = 0;
	while (string[i] != '\0')
	{
		ft_unicode_print(string[i]);
		i++;
	}
	return(str);
}

size_t ft_unicode_len(wchar_t chr)
{
	size_t count;

	count = 0;
	if (chr <= 127)
		count++;
	else if (chr <= 2047)
		count = count + 2;
	else if (chr <= 65535)
		count = count + 3;
	else
		count = count + 4;
	return(count);
}