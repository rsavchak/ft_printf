#include "libft.h"
#include "ft_printf.h"

char *ft_chose_type(t_form type, va_list ap, int *res, char *mod)
{
	char *str;

	if (type.conv == 's' || type.conv == 'S')
		str = ft_print_s(ap, type, res);
	if (type.conv == 'p')
		str = ft_print_p(ap, type);
	if (type.conv == 'c' || type.conv == 'C')
		str = ft_print_c(ap, type, res);
	if (type.conv == 'd' || type.conv == 'D' || type.conv == 'i')
		str = ft_print_d(ap, type);	
	if (type.conv == 'u' || type.conv == 'U')
		str = ft_print_u(ap, type);
	if (type.conv == 'o' || type.conv == 'O')
		str = ft_print_o(ap, type);
	if (type.conv == 'x' || type.conv == 'X')
		str = ft_print_x(ap, type);
	if (type.conv == '%')
		str = ft_print_percent(ap, type);
	if (type.conv == 'r')
		str = ft_print_r(type, mod, res);

	return(str);
}

char *ft_print_r(t_form type, char *mod, int *res)
{
	char *str = NULL;
	int i = 0;
	
	if (type. width)
	{
		str = ft_memalloc(type.width);
		if (type.zero)
			ft_memset(str, '0', type.width - 1);
		else
			ft_memset(str, ' ', type.width - 1);
	}
	if (!type.minus) 
	{
		ft_putstr(str);
		ft_putstr(mod);
	}
	if (type.minus)
	{
		ft_putchar(*mod);
		mod = mod + 1;
		ft_putstr(str);
		ft_putstr(mod);
		*res = *res + 1;
	}
	if (str)
		while(str[i++] != '\0')
			*res = *res + 1;
	i = 0;
	while (mod[i++] != '\0')
		*res = *res + 1;
	//free(mod);
	str = "";
	return (str);
}
