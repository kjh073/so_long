# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joohekim <joohekim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 18:33:11 by joohekim          #+#    #+#              #
#    Updated: 2023/02/03 16:00:05 by joohekim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c \
	ft_memmove.c ft_memset.c ft_strlcat.c ft_strchr.c ft_strncmp.c ft_strlcpy.c \
	ft_strdup.c ft_strjoin.c ft_strlen.c \
	ft_strnstr.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_strrchr.c ft_substr.c ft_calloc.c \
	ft_strmapi.c ft_split.c ft_itoa.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c get_next_line_utils.c \
	ft_printf.c ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_str.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

NAME = libft.a

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

ifdef WITH_BONUS
	FILES = $(OBJ) $(OBJ_BONUS)
else
	FILES = $(OBJ)
endif

all: $(NAME)

$(NAME): $(FILES)
	ar rcus $(NAME) $(FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	make WITH_BONUS=1 all
	
clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus