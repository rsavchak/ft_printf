#include "libft.h"
#include "ft_printf.h"

char *ft_print_p(va_list ap, t_form type)
{
	char *str = NULL;
	long long p;

	p =  va_arg(ap, long long);
	str = ft_itoa_base(p, 16);
	str = ft_flags_p(str, type);
	return(str);
}

char	*ft_big(char *str)
{
	int i;
	char *s;

	i = 0;
	s = ft_memalloc(ft_strlen(str) + 1);
	while (str[i] != '\0')
	{
		s[i] = ft_toupper(str[i]);
		i++;
	}
	//free(str);
	return (s);	
}
