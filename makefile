SRC = ft_hexaa_flags.c ft_check_flags.c ft_hexa_flags.c ft_p_flags.c \
        ft_u_flags.c ft_char_flags.c ft_fcts.c ft_i_or_d_flags.c ft_printf.c \
		ft_string_flags.c ft_fcts2.c ft_fcts3.c

OBJECT = $(SRC:.c=.o)

NAME = libftprintf.a

all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJECT)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJECT)

fclean: clean
	@rm -f $(NAME)

re: fclean all