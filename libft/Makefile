NAME	= libft.a

HEAD	= ./libft.h

SRC_1	= ./ft_strlen.c ./ft_strdup.c ./ft_strcpy.c ./ft_strncpy.c ./ft_putchar.c ./ft_putstr.c ./ft_putendl.c ./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_memalloc.c ./ft_memdel.c ./ft_strnew.c ./ft_strdel.c ./ft_strclr.c ./ft_striter.c ./ft_striteri.c ./ft_strmap.c ./ft_strmapi.c ./ft_strequ.c ./ft_strnequ.c ./ft_strsub.c ./ft_strjoin.c ./ft_strtrim.c ./ft_strsplit.c ./ft_putnbr.c ./ft_putnbr_fd.c ./ft_itoa.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memccpy.c ./ft_memmove.c ./ft_memchr.c ./ft_memcmp.c ./ft_strcat.c ./ft_strncat.c ./ft_strlcat.c ./ft_strchr.c ./ft_strrchr.c ./ft_strstr.c ./ft_strcmp.c ./ft_strncmp.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_toupper.c ./ft_tolower.c ./ft_strnstr.c ./ft_isspace.c ./ft_atoi.c ./ft_lstnew.c ./ft_lstdelone.c ./ft_lstdel.c ./ft_lstadd.c ./ft_lstiter.c ./ft_lstmap.c ./ft_lstsize.c ./ft_revstr.c ./ft_isupper.c ./ft_islower.c ./ft_hex_to_int.c ./ft_swap_value.c ./ft_abs.c ./ft_strdel2.c

SRC_2	= $(SRC_1:.c=.o)



all: $(NAME)

$(NAME): $(SRC_2)
	@ ar rc $(NAME) $(SRC_2)
	@ ranlib $(NAME)

%.o: %.c $(HEADER)
	@ gcc -c -Wall -Wextra -Werror -o $@ $<

clean:
	@ /bin/rm  -f  $(SRC_2)

fclean: clean
	@ /bin/rm  -f  $(NAME)

re: fclean  all