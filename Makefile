CC = cc

CFLAGS = -Wall -Wextra -Werror
MLX_DIR = mlx
FRAME_WORK_FLAGS = -framework OpenGL -framework Appkit
HEADER_FLAGS = -Imlx/mlx.h
LDFLAGS = -L.
LIBS = -lmlx
# LDFLAGS = -L./libft -L$(MLX_DIR)
# LIBS = -lft -lmlx
NAME = a.out 
# SRC_DIR = 

# ifdef compile_bonus
# 	MAIN = main_bonus
# else
# 	MAIN = main
# endif

SRCS = main.c

OBJS = $(SRCS:.c=.o) 
# $(SRC_DIR)/$(MAIN).o

# LIBFT = libft/libft.a

all: $(NAME)

# bonus:
# 	make compile_bonus=1 all

$(NAME): $(OBJS) $(LIBFT) mlx/libmlx.dylib
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) $(FRAME_WORK_FLAGS) -o $@
	-install_name_tool -change libmlx.dylib ./$(MLX_DIR)/libmlx.dylib $(NAME)
$(LIBFT):
	cd libft && (make)
mlx/libmlx.dylib:
	cd mlx; make
%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX_DIR) $(HEADER_FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(SRC_DIR)/main_bonus.o $(SRC_DIR)/main.o && cd libft && make clean
fclean: clean
	rm -f $(NAME); cd libft; make fclean; cd ..; cd mlx; make clean
re: fclean all

.PHONY: all clean fclean re