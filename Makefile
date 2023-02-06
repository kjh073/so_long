# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jooheekim <jooheekim@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:37:00 by joohekim          #+#    #+#              #
#    Updated: 2023/02/07 04:14:26 by jooheekim        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIB_DIR = ./libft
MLX_DIR = ./mlx
FRAME_WORK_FLAGS = -framework OpenGL -framework Appkit
HEADER_FLAGS = -Imlx/mlx.h -Ilibft/libft.h
LDFLAGS = -L$(LIB_DIR) -L$(MLX_DIR)
LIBS = -lft -lmlx

NAME = a.out 

SRC_DIR = .
SRCS = main.c check_map.c map_list.c dfs.c error_msg.c
# SRCS_bonus = test_bonus.c

ifdef compile_bonus
	FILES = $(OBJ) $(OBJ_BONUS)
else
	FILES = $(OBJ)
endif

OBJS = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_bonus:.c=.o)

LIBFT = ./libft/libft.a
LIBMLX = ./mlx/libmlx.dylib

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(CC) $(OBJS) $(LDFLAGS) $(LIBS) $(FRAME_WORK_FLAGS) -o $@
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)
	
$(LIBFT):
	cd $(LIB_DIR); $(MAKE)
	
$(LIBMLX):
	cd mlx; $(MAKE)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) $(HEADER_FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean
	$(MAKE) -C $(LIB_DIR) clean
	
fclean: clean
	rm -f $(NAME) $(OBJS)
	$(MAKE) -C $(LIB_DIR) fclean
	
re: fclean all

bonus:
	make compile_bonus=1 all

.PHONY: all clean fclean re bonus