# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 09:43:48 by skoskine          #+#    #+#              #
#    Updated: 2021/02/28 19:59:39 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/
LIBFT_DIR = libft/

SRCS = $(addprefix $(SRC_DIR), ft_printf.c ft_vasprintf.c ft_asprintf.c \
ft_dprintf.c parser.c conversion_specs.c parse_chars.c \
parse_doubles.c dtoa.c round_double.c \
parse_signed_integers.c parse_unsigned_integers.c parse_pointers.c \
parse_helpers.c)
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:$(SRC_DIR)%.c=%.o))
HEADER = include/ft_printf.h

LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
LIBFT_OBJS = $(wildcard libft/*.o)

INCLUDES = -I include -I libft

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	@ar rcs $@ $(OBJS) $(LIBFT_OBJS)

$(LIBFT):
	@$(MAKE) -C libft

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -o $@ $< $(INCLUDES)

$(OBJ_DIR):
	@mkdir $@

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C libft clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean

re: fclean all
	
.PHONY: all clean fclean re