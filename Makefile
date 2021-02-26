# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 09:43:48 by skoskine          #+#    #+#              #
#    Updated: 2021/02/26 13:43:28 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(addprefix $(SRC_DIR), ft_printf.c ft_vasprintf.c ft_asprintf.c ft_dprintf.c \
parser.c conversion_specs.c parse_chars.c parse_doubles.c \
parse_signed_integers.c parse_unsigned_integers.c \
parse_helpers.c parse_pointers.c)

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:$(SRC_DIR)%.c=%.o))

SRC_DIR = src/
OBJ_DIR = obj/

LIBFT = libft/libft.a
LIBFT_DIR = libft

INCLUDES = -I include -I libft

LDFLAGS = -L libft -l ft -L . -l ftprintf

TEST_SRCS = test/*.c

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(LIBFT)
	@ar rcs $@ $(OBJS)

$(LIBFT): $(LIBFT_DIR)
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