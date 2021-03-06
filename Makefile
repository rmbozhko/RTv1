NAME = RTv1

SRC = main.c initializing.c interacting_handlers.c entities_math.c optimization.c send_beams.c matrix_operations.c xyz_movement.c object_initialization.c print_screen.c audio.c
OBJ = $(SRC:.c=.o)

CFLAGS = -O3 -Wall -Wextra -Werror
GLIBS = -L./libft -lft -L./jpeglib -ljpeg -lmlx -framework OpenGL -framework AppKit

INCLUDES =  -I ./frameworks/SDL2.framework/Versions/A/Headers \
			-I ./frameworks/SDL2_mixer.framework/Versions/A/Headers \
			-F ./frameworks

FRAMEWORKS =  -F ./frameworks \
			  -rpath ./frameworks \
			  -framework SDL2 \
			  -framework SDL2_mixer

all: $(NAME)

$(NAME): $(OBJ)
	@make -C jpeglib/
	@make -C libft/
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(GLIBS) $(FRAMEWORKS)
	@echo "\033[0;32m${NAME} is compiled\033[0m"

%.o: %.c
	@gcc -c $(CFLAGS) $(INCLUDES) -o $@ $<
clean:
	@make clean -C jpeglib/
	@make clean -C libft/
	@/bin/rm -f *.o

fclean: clean
	@make fclean -C libft/
	@/bin/rm -f $(NAME)

re: fclean all