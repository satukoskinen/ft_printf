#!/bin/sh

### CONFIG ###

CFLAGS="-Wall -Wextra -Werror -g" #compiler flags
#CFLAGS="-g"
INCLUDES="-I . -I libft" #ft_printf.h and libft.h locations
LDFLAGS="-L libft -l ft -L . -l ftprintf" #static libraries and their locations

###

test_srcs="eval_tests/main.c"

### test make ###

#make all && make re && make fclean && make && make clean

### basic tests ###

gcc -o test_exe $CFLAGS $test_srcs $INCLUDES $LDFLAGS
./test_exe
