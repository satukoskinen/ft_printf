#!/bin/sh

### CONFIG ###

CFLAGS="-Wall -Wextra -Werror -g" #compiler flags
#CFLAGS="-g"
INCLUDES="-I . -I libft" #ft_printf.h and libft.h locations
LDFLAGS="-L libft -l ft -L . -l ftprintf" #static libraries and their locations

###

test_srcs="eval_tests/*.c"

### test make ###

#make
#make all && make re && make fclean && make && make clean

### basic tests ###

echo "\nBasic tests...\n"

gcc -o test_exe $CFLAGS $test_srcs $INCLUDES $LDFLAGS

echo "Testing strings..."
./test_exe ft_printf strings > user_output
./test_exe printf strings > test_output
diff user_output test_output > diff
if [ -s diff ]
then
	echo "error"
	cat diff
	exit 1
else
	echo "diff OK\n"
fi

echo "Testing signed integers..."
./test_exe ft_printf ints > user_output
./test_exe printf ints > test_output
diff user_output test_output > diff
if [ -s diff ]
then
	echo "error"
	cat diff
	exit 1
else
	echo "diff OK\n"
fi

echo "Testing unsigned integers..."
./test_exe ft_printf uints > user_output
./test_exe printf uints > test_output
diff user_output test_output > diff
if [ -s diff ]
then
	echo "Error"
	cat diff
	exit 1
else
	echo "diff OK\n"
fi

echo "Testing leaks..."
./test_exe ft_printf all leaks > leaks_output
grep -a -e "nodes malloced" -A 1 leaks_output
