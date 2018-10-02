#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsavchak <rsavchak@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 17:56:49 by rsavchak          #+#    #+#              #
#    Updated: 2018/10/01 17:56:51 by rsavchak         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJECTS = ft_printf.o\
					ft_print_space.o\
					ft_check_flags.o\
					ft_check.o\
					ft_check_conv.o\
					ft_choose_type.o\
					ft_print_c.o\
					ft_print_s.o\
					ft_print_ls.o\
					ft_unicode.o\
					ft_print_d.o\
					ft_print_p.o\
					ft_flags.o\
					ft_flags_x.o\
					ft_parsing.o\
					ft_add_sharp.o\
					
all: $(NAME)

$(OBJECTS) : %.o: %.c
	$(CC) -g -c $(FLAGS) -I libft/ -I / $< -o $@
	

$(NAME): $(OBJECTS)
	$(MAKE) -C libft/
	ar rc libftprintf.a $(OBJECTS) libft/*.o

clean:
	$(MAKE) -C libft/ clean
	-rm $(OBJECTS)
fclean : clean
	$(MAKE) -C libft/ fclean
	-rm -v $(NAME)
re: fclean all