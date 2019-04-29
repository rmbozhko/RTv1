#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yvasin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/05 19:45:15 by yvasin            #+#    #+#              #
#    Updated: 2017/04/05 19:45:16 by yvasin           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = RTv1

SRC = main.c initializing.c interacting_handlers.c entities_math.c optimization.c send_beams.c matrix_operations.c xyz_movement.c object_initialization.c print_screen.c
OBJ = $(SRC:.c=.o)

CFLAGS = -O3 -Wall -Wextra -Werror
GLIBS = -L./libft -lft -L./jpeglib -ljpeg -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C jpeglib/
	@make -C libft/
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(GLIBS)
	@echo "\033[0;32m${NAME} is compiled\033[0m"

%.o: %.c
	@gcc -c $(CFLAGS) -o $@ $<
clean:
	@make clean -C jpeglib/
	@make clean -C libft/
	@/bin/rm -f *.o

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all