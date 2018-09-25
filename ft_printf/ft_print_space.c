#include "ft_printf.h"

char* ft_add_space(char *src,int len, int nbrSpace, t_form *type)
{
	char *str = NULL;
	char *space = NULL;

	space = ft_memalloc (nbrSpace + 1);
	ft_memset(space, ' ', nbrSpace);
	str = ft_memalloc(len + 1);
	if (type->minus)
		str = ft_strcat(src,space);
	else
		str = ft_strcat(space, src);
	free(space);
	return(str);
}

char *ft_add_space_or_zero(char *src,int len, int nbrSpace, t_form type)
{
	char *str = NULL;
	char *zero = NULL;

	if (!type.minus && type.zero)
	{
		zero = ft_memalloc (nbrSpace + 1);
		if (*src == '-')
		{
			*zero = '-';
			ft_memset(zero + 1, '0', nbrSpace);
			str = ft_memalloc(len + 1);
			str = ft_strcat(zero, src + 1);
		}
		else
		{
			ft_memset(zero, '0', nbrSpace);
			str = ft_memalloc(len + 1);
			str = ft_strcat(zero, src);
		}
		free(zero);
	}
	else
		str = ft_add_space(src, len, nbrSpace, &type);
	return(str);
}

char *ft_one_space(char *nbr, int *len)
{	
	char *space;

	if (ft_atoi(nbr) > 0)
	{
		space = ft_memalloc(*len + 2);
		space[0] = ' ';
		space = ft_strcat(space, nbr);
		*len = *len + 1;
		free(nbr);
		return(space);
	}
	return(nbr);
}

char *ft_add_sharp(char *num, int *len, t_form type)
{
	char *sharp = "0";
	int i;

	i = 0;
	if ((type.conv == 'o' || type.conv == 'O') && type.hash && ft_atoi(num) != 0)
	{
		while(num[i] != '\0')
			i++;
		sharp = ft_memalloc(i + 2);
		sharp = ft_strcat(ft_strdup("0"), num);
		*len = *len + 1;
		return (sharp);	
	}
	if (type.conv == 'p' || (type.hash &&  ft_atoi(num) != 0))
	{	
		while(num[i] != '\0')
			i++;
		sharp = ft_memalloc(i + 3);
		sharp = ft_strcat(ft_strdup("0x"), num);
		*len = *len + 2;
		//free(num);
		return (sharp);
	}
	return (num);
}

char *ft_add_plus(char *nbr, int *len, t_form type)
{	
	char *plus;

	if (ft_atoi(nbr) >= 0 && type.conv != 'o' && type.conv != 'O')
	{
		plus = ft_memalloc(*len + 2);
		plus[0] = '+';
		plus = ft_strcat(plus, nbr);
		*len = *len + 1;
		free(nbr);
		return(plus);
	}
	return(nbr);
}