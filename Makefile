# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 09:43:48 by skoskine          #+#    #+#              #
#    Updated: 2021/01/23 14:36:56 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c conversion_specs.c parse_chars.c parse_doubles.c \
parse_signed_integers.c parse_unsigned_integers.c \
parse_helpers.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -I . -I libft

LDFLAGS = -L libft -l ft -L . -l ftprintf

TEST_SRCS = eval_tests/main.c

CC = gcc

CFLAGS = -c -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@ar rcs $@ $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ $< $(INCLUDES)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

test: all $(TEST_SRCS)
	$(CC) -o $@ $(TEST_SRCS) $(INCLUDES) $(LDFLAGS)
	@./$@
	
.PHONY: all clean fclean re