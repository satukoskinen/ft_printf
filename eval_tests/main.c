#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_printf.h"
#include "tests.h"

int		main(int argc, char **argv)
{
	int		use_ftprintf;
	int		tests;
	int		max_tests;

	tests = 0;
	max_tests = 0;
	if (argc == 1 || (argc > 1 && strcmp(argv[1], "ftprintf") == 0))
		use_ftprintf = 1;
	else
		use_ftprintf = 0;
	if (argc == 1 || (argc > 1 && strcmp(argv[1], "all") == 0) || (argc > 2 && strcmp(argv[2], "all") == 0))
	{
		tests += test_strings(use_ftprintf);
		tests += test_signed_integers(use_ftprintf);
		tests += test_unsigned_integers(use_ftprintf);
	}
	else if ((argc > 1 && strcmp(argv[1], "strings") == 0) || (argc > 2 && strcmp(argv[2], "strings") == 0))
		tests = test_strings(use_ftprintf);
	else if ((argc > 1 && strcmp(argv[1], "ints") == 0) || (argc > 2 && strcmp(argv[2], "ints") == 0))
		tests = test_signed_integers(use_ftprintf);
	else if ((argc > 1 && strcmp(argv[1], "uints") == 0) || (argc > 2 && strcmp(argv[2], "uints") == 0))
		tests = test_unsigned_integers(use_ftprintf);
	
	printf("Passed a total of %d tests out of %d\n", tests, max_tests);
	if (argc > 1 && strcmp(argv[argc - 1], "leaks") == 0)
		system("leaks test_exe");
	return (0);
}
