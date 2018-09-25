#include "ft_printf.h"

char *ft_print_u(va_list ap, t_form type)
{
	uintmax_t nb;
	char *nbr;

	if (ft_strchr(type.size, 'z'))
		nb = va_arg(ap, size_t);	
	else if (ft_strchr(type.size, 'j'))
		nb = va_arg(ap, uintmax_t);
	else if (ft_strequ(type.size, "ll"))
		nb = va_arg(ap, unsigned long long);
	else if (ft_strequ(type.size, "l") || type.conv == 'U')
		nb = va_arg(ap, unsigned long);
	else if (ft_strequ(type.size, "h"))
		nb = (unsigned short) va_arg(ap, int);
	else if (ft_strequ(type.size, "hh"))
		nb = (unsigned char) va_arg(ap, int);
	else
		nb = va_arg(ap, unsigned int);
	nbr = ft_itoa_base(nb, 10);
	nbr = ft_flags(nbr, type);
	return(nbr);
} 

char *ft_print_d(va_list ap, t_form type)
{
	intmax_t nb;
	char *nbr;

	if (ft_strchr(type.size, 'z'))
		nb = va_arg(ap, size_t);
	else if (ft_strchr(type.size, 'j'))
		nb = va_arg(ap, intmax_t);
	else if (ft_strequ(type.size, "ll"))
		nb = va_arg(ap, long long);
	else if (ft_strequ(type.size, "l") || type.conv == 'D')
		nb = va_arg(ap, long);
	else if (ft_strequ(type.size, "h"))
		nb = (short) va_arg(ap, int);
	else if (ft_strequ(type.size, "hh"))
		nb = (signed char) va_arg(ap, int);
	else //(*type.size == '\0' && type.conv == 'd')
		nb = va_arg(ap, signed int);
	nbr = ft_itoa(nb);
	nbr = ft_flags(nbr, type);
	return(nbr);
}

char *ft_print_o(va_list ap, t_form type)
{
	uintmax_t nb;
	char *nbr;
	
	if (ft_strchr(type.size, 'z'))
		nb = va_arg(ap, size_t);	
	else if (ft_strchr(type.size, 'j'))
		nb = va_arg(ap, uintmax_t);
	else if (ft_strequ(type.size, "ll"))
		nb = va_arg(ap, unsigned long long);
	else if (ft_strequ(type.size, "l") || type.conv == 'O')
		nb = va_arg(ap, unsigned long);
	else if (ft_strequ(type.size, "h"))
		nb = (unsigned short) va_arg(ap, int);
	else if (ft_strequ(type.size, "hh"))
		nb = (unsigned char) va_arg(ap, int);
	else //(*type.size == '\0' && type.conv == 'o')
		nb = va_arg(ap, unsigned int);
	nbr = ft_itoa_base(nb, 8);
	nbr = ft_flags(nbr, type);
	return(nbr);
}

char *ft_print_x(va_list ap, t_form type)
{
	uintmax_t nb;
	char *nbr;
	
	if (ft_strchr(type.size, 'z'))
		nb = va_arg(ap, size_t);
	else if (ft_strchr(type.size, 'j'))
		nb = va_arg(ap, uintmax_t);
	else if (ft_strequ(type.size, "ll"))
		nb = va_arg(ap, unsigned long long);
	else if (ft_strequ(type.size, "l"))
		nb = va_arg(ap, unsigned long);
	else if (ft_strequ(type.size, "h"))
		nb = (unsigned short) va_arg(ap, int);
	else if (ft_strequ(type.size, "hh"))
		nb = (unsigned char) va_arg(ap, int);
	else //(*type.size == '\0' && (type.conv == 'x' || type.conv == 'X'))
		nb = va_arg(ap, unsigned int);
	nbr = ft_itoa_base(nb, 16);
	nbr = ft_flags_x(nbr, type);
	return(nbr);
}
