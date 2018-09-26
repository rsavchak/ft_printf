#include "libft.h"
#include "ft_printf.h"

int ft_check_width(char *mod, t_form *type)
{
	int i = 0;
	
	if (ft_isdigit(mod[i]))
	{
		type->width = ft_atoi(mod);
		while (ft_isdigit(mod[i]) == 1)
			i++;
	}
	return (i);
}

int ft_check_precision(char *mod, t_form *type)
{
	int i = 0;

	if(mod[i] == '.')
	{
		mod = mod + 1;
		type->prec = ft_atoi(mod);
		while (ft_isdigit(mod[i]) == 1)
			i++;
		i = i + 1;
		if (type->prec == 0)
			type->prec = -1;
	}
	return (i);
}

void ft_check_conv(t_form *type, char *mod)
{
	char *convers = "sSpdDioOuUxXcC%";
	int k = 0;
	int i = 0;

	while(convers[k] != '\0')
	{
		i = 0;
		while(mod[i] != '\0')
		{
			if (mod[i] == convers[k])
			{
				type->conv = convers[k];
				break;
			}
			i++;
		}
		k++;
	}
	if (!type->conv)
		type->conv = 'r';
	if ((type->prec || type->minus) && type->conv != 's' && type->conv != 'S' && type->conv != 'c' && type->conv != '%' && type->conv != 'r')
		type->zero = 0;
}

int ft_check_size(char *mod, t_form *type)
{
	char *sizes = "hljz";
	char size[3];
	int j = 0;

	while(*mod)
	{
		if(ft_strchr(sizes, *mod))
		{	
			size[j] = *mod;
			j++;
		}
		mod++;
	}
	size[j] = '\0';
	if (type->size == NULL)
		type->size = ft_strdup(size);
	return(j);
}
