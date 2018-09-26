#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int count;
	va_list ap;

	va_start(ap, format);
	count = vprint(format, ap);
	va_end(ap);
	
	return(count);
}

int vprint(const char *format, va_list ap)
{
	int i = 0;
	int length;
	char *part = NULL;
	static char *text;
	int res = 0;

	while (format[i])
	{
		i = 0;
		length = 0;
		while (format[i] != '%' && format[i] != '\0')
			i++;
		text = ft_memalloc(i + 1);
		text = ft_strsub(format, length, i);
		ft_putstr(text);
		res = res + ft_strlen(text);
		free(text);
		if(format[i] == '%')
		{
			format = format + i + 1;
			part = ft_parsing(&format, ap, &res);
			ft_putstr(part);
			if (part != NULL)
				res = res + ft_strlen(part);
			i = 0;
		}
	}
	return (res);
}