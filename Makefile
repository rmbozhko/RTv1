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

SRC = main.c image_manager.c vec_m.c abc.c find_normals.c ray_trace.c matrix_operations.c xyz_movement.c object_initialization.c
SRCO = $(SRC:.c=.o)

LIBFT = libft/libft.a

FLAGS = -O3 -Wall -Wextra -Werror
GRAPHICS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRCO)
	make -C libft/
	gcc -o $(NAME) $(SRCO) $(LIBFT) $(FLAGS) $(GRAPHICS)

%.o: %.c
	gcc -c $(FLAGS) -o $@ $<
clean:
	make clean -C libft/
	/bin/rm -f *.o

fclean: clean
	make fclean -C libft/
	/bin/rm -f $(NAME)

re: fclean all