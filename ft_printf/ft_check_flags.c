#include "libft.h"
#include "ft_printf.h"

int ft_check_flags(char *mod, t_form *type)
{
	const char *flags = "-+0 #";
	int i;
	int j = 0;
	int count = 0;
	while(mod[j] != '\0')
	{
		i = 0;
		while(flags[i])
		{
			ft_flag(mod[j], flags[i], type, &count);
			i++;
		}
		if (count <= j)
			break;
		j++;
	}
	if (type->plus)
		type->space = 0;	
	return(j);
}

void	ft_flag(char mod, char flag, t_form *type, int *count)
{
	if (mod == flag)
	{	
		*count = *count + 1;
		if (mod == '-')
			type->minus = 1;
		if (mod == '+')
			type->plus = 1;
		if (mod== '0')
			type->zero = 1;
		if (mod == ' ')
			type->space = 1;
		if (mod == '#')
			type->hash = 1;
	}
}