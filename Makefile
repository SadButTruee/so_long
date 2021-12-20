NAME = 		so_long

SRC	=		sl/clear.c \
			sl//mlx_func.c \
			sl//mlx_func2.c \
			sl//go.c \
			sl/key.c \
			sl//key2.c \
			sl//liba.c \
			sl//processing.c \
			sl//processing2.c \
			sl//so_long.c \
			sl//gnl.c \
			sl//liba2.c \
			sl//liba3.c \

SRC_B =		so_long_bonus/clear_bonus.c \
			so_long_bonus/mlx_func_bonus.c \
			so_long_bonus/mlx_func2_bonus.c \
			so_long_bonus/go_bonus.c \
			so_long_bonus/key_bonus.c \
			so_long_bonus/key2_bonus.c \
			so_long_bonus/liba_bonus.c \
			so_long_bonus/processing_bonus.c \
			so_long_bonus/processing2_bonus.c \
			so_long_bonus/so_long_bonus.c \
			so_long_bonus/gnl_bonus.c \
			so_long_bonus/liba2_bonus.c \
			so_long_bonus/liba3_bonus.c \

SRC_H = sl/so_long.h

SRC_H_B = so_long_bonus/so_long_bonus.h

MINILIBX = libmlx.a

OBJ = $(patsubst %.c,%.o,$(SRC))

OBJ_B = $(patsubst %.c,%.o,$(SRC_B))

FLAGS = -Wall -Wextra -Werror -I minilibx -L minilibx -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ) $(SRC_H)
	@make -C minilibx
	@cp minilibx/$(MINILIBX) .
	gcc $(FLAGS) $(SRC) -o $(NAME)

bonus : $(OBJ_B) $(SRC_H_B)
	@make -C minilibx
	@cp minilibx/$(MINILIBX) .
	gcc $(FLAGS) $(SRC_B) -o $(NAME)



clean :
	@rm -f $(OBJ) $(OBJ_B)
	@make clean -C minilibx

fclean : clean
	@rm -f $(NAME)
	@rm -f $(MINILIBX)

re : fclean all

.PHONY : all clean fclean re bonus