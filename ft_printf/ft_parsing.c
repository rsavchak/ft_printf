#include "libft.h"
#include "ft_printf.h"

char *ft_parsing(const char **format, va_list ap, int *res)
{
	int i;
	i = 0;
	t_form type;
	char *str = NULL; 
	char *mod = NULL;
	int k = 0;

	mod = ft_modificator(*format, &k);
	mod = ft_check_mod(mod, &i, k);
	if (!mod || *mod == 0)
	{
		*format = *format + i;
		return (NULL);
	}
	*format = *format + ft_strlen(mod);
	ft_clear_form(&type);
	ft_pars_mod(&i, mod, &type);
	mod = mod + i;
	ft_check_conv(&type, mod);
	str = ft_chose_type(type, ap, res, mod);
	return (str);
}

void ft_pars_mod(int *i, char *mod, t_form *type)
{
	int k = 0;
	int check = 0;

	while(mod[*i] != '\0')
	{	check = *i;
		k = ft_check_flags(mod + *i, type);
		*i = *i + k;
		k = ft_check_width(mod + *i, type);
		*i = *i + k;
		k = ft_check_precision(mod + *i, type);
		*i = *i + k;
		k = ft_check_size(mod + *i, type);
		*i = *i + k;
		if (check == *i)
			break;
	}
}

char  *ft_check_mod(char *mod, int *i, int k)
{

	const char *formatstr = "sSpdDioOuUxXcC%0123456789.+-0 #hjlz";

	if (mod != NULL)
	{
		while(mod[*i])
		{
			if (!ft_strchr(formatstr, mod[*i]) && k == 1)
			{
				mod = NULL;
				return(mod);
			}		
			*i = *i + 1;	
		}
	}
	*i = 0;
	return (mod);
}

char *ft_modificator(const char *format, int *k)
{
	char *mod = NULL;
	const char *type = "sSpdDioOuUxXcC%";
	int i;
	int j;

	j = 0;
	while(format[j] != '\0')
	{
		i = 0;
		while(type[i])
		{
			if(format[j] == type[i])
			{
				*k = 1;	
				mod = ft_strsub(format, 0, j + 1);
				return(mod);
			}
			i++;
		}
		j++;
	}
	mod = ft_strsub(format, 0, j + 1);
	return(mod);
}