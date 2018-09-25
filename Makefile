NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

OBJECTS = ft_printf/ft_printf.o\
					ft_printf/ft_parsing.o\
					ft_printf/ft_check_flags.o\
					ft_printf/ft_check.o\
					ft_printf/ft_choose_type.o\
					ft_printf/ft_print_c.o\
					ft_printf/ft_print_s.o\
					ft_printf/ft_print_d.o\
					ft_printf/ft_print_space.o\
					ft_printf/ft_flags.o\
					ft_printf/ft_print_p.o\

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