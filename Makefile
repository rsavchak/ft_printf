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

OBJECTS = ft_printf/ft_printf.o\
					ft_printf/ft_print_space.o\
					ft_printf/ft_check_flags.o\
					ft_printf/ft_check.o\
					ft_printf/ft_check_conv.o\
					ft_printf/ft_choose_type.o\
					ft_printf/ft_print_c.o\
					ft_printf/ft_print_s.o\
					ft_printf/ft_print_ls.o\
					ft_printf/ft_unicode.o\
					ft_printf/ft_print_d.o\
					ft_printf/ft_print_p.o\
					ft_printf/ft_flags.o\
					ft_printf/ft_flags_x.o\
					ft_printf/ft_parsing.o\
					ft_printf/ft_add_sharp.o\
					
all: $(NAME)

$(OBJECTS) : %.o: %.c
	$(CC) -g -c $(FLAGS) -I libftprintf/ -I ft_printf/ $< -o $@
	

$(NAME): $(OBJECTS)
	$(MAKE) -C libftprintf/
	ar rc libftprintf.a $(OBJECTS) libftprintf/*.o

clean:
	$(MAKE) -C libftprintf/ clean
	-rm $(OBJECTS)
fclean : clean
	$(MAKE) -C libftprintf/ fclean
	-rm -v $(NAME)
re: fclean all