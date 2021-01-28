#!/bin/sh

### CONFIG ###

CFLAGS="-Wall -Wextra -Werror -g" #compiler flags
#CFLAGS="-g"
INCLUDES="-I . -I libft" #ft_printf.h and libft.h locations
LDFLAGS="-L libft -l ft -L . -l ftprintf" #static libraries and their locations

###

test_srcs="test/*.c"

### test make ###

make && make clean
#make all && make re && make fclean && make && make clean

### basic tests ###

printf "\nBasic tests...\n"

gcc -o test_exe $CFLAGS $test_srcs $INCLUDES $LDFLAGS

printf "\nTesting strings... "
{ ./test_exe ft_printf strings > user_output1; } 2> err_output
if [ $? != 0 ]
then
	printf "seg fault: run './test_exe ftprintf strings' for more info"
	#cat err_output
	exit 1
fi
./test_exe printf strings > test_output1
diff --text user_output1 test_output1 > diff
if [ -s diff ]
then
	printf "error\n\n"
	cat diff
	exit 1
else
	printf "diff OK\n"
fi

printf "\nTesting signed integers... "
{ ./test_exe ft_printf ints > user_output2; } 2> err_output
if [ $? != 0 ]
then
	printf "seg fault: run `./test_exe ftprintf ints` for more info"
	#cat err_output
	exit 1
fi
./test_exe printf ints > test_output2
diff --text user_output2 test_output2 > diff
if [ -s diff ]
then
	printf "error\n\n"
	cat diff
	exit 1
else
	printf "diff OK\n"
fi

printf "\nTesting unsigned integers... "
{ ./test_exe ft_printf uints > user_output; } 2> err_output
if [ $? != 0 ]
then
	printf "seg fault"
	#cat err_output
	exit 1
fi
./test_exe printf uints > test_output
diff --text user_output test_output > diff
if [ -s diff ]
then
	printf "Error"
	cat diff
	exit 1
else
	printf "diff OK\n"
fi

rm test_output user_output diff err_output diff test_output1 test_output2 user_output1 user_output2

printf "\nTesting leaks...\n\n"
./test_exe ft_printf all leaks > leaks_output
grep -a -e "nodes malloced" -A 1 leaks_output

rm leaks_output