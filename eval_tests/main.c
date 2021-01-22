#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int		main(void)
{
	int		ret;
	int		*test_pointer;

	test_pointer = &ret;
	ret = printf("testing %%\n");
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %%\n");
	printf("ret is %d\n", ret);

	ret = printf("testing string '%s' %%\n", "tester123456789");
	printf("ret is %d\n", ret);
	ret = ft_printf("testing string '%s' %%\n", "tester123456789");
	printf("ret is %d\n", ret);
	
	ret = printf("harder tests for %%.5s: '%.5s' %%s: '%s'\n%s\n%.100s\n", "adfghjklö", "asdfghjklö", "#saldka384972384edslnaclsalkc", "asdfg");
	printf("ret is %d\n", ret);
	ret = ft_printf("harder tests for %%.5s: '%.5s' %%s: '%s'\n%s\n%.100s\n", "adfghjklö", "asdfghjklö", "#saldka384972384edslnaclsalkc", "asdfg");
	printf("ret is %d\n", ret);

	ret = printf("testing string '%.5s' %%\n", "tester123456789");
	printf("ret is %d\n", ret);
	ret = ft_printf("testing string '%.5s' %%\n", "tester123456789");
	printf("ret is %d\n", ret);
/*
	ret = printf("non-supported conversion %b\n", "test");
	printf("ret is %d\n", ret);

	ret = printf("wrong argument %s\n", 1);
	printf("ret is %d\n", ret);
*/
	ret = printf("testing %% %d %i\n", 42, 42);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %% %d %i\n", 42, 42);
	printf("ret is %d\n", ret);

	ret = printf("testing %o\n", 42);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %o\n", 42);
	printf("ret is %d\n", ret);

	ret = printf("testing %% %x %X\n", 42, 42);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %% %x %X\n", 42, 42);
	printf("ret is %d\n", ret);

	ret = printf("testing %% %d %+i % d\n", 42, 2147483647, -2147483647 - 1);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %% %d %+i % d\n", 42, 2147483647, -2147483647 - 1);
	printf("ret is %d\n", ret);

	ret = printf("testing %o\n", 42);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %o\n", 42);
	printf("ret is %d\n", ret);

	ret = printf("testing %% %x %X\n", 42, 42);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %% %x %X\n", 42, 42);
	printf("ret is %d\n", ret);

	ret = printf("testing %% %d %i %o %u %x %X\n", -42, -42, 42, 42, 42, 42);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %% %d %i %o %u %x %X\n", -42, -42, 42, 42, 42, 42);
	printf("ret is %d\n", ret);

	printf("test precision '%f'\n", (double)42);

	ret = printf("flag with zero '%-10.8d'\n", -123423);
	printf("ret is %d\n", ret);
	ret = ft_printf("flag with zero '%-10.8d'\n", -123423);
	printf("ret is %d\n", ret);

	ret = printf("flag with zero '%#10.5o'\n", 123423);
	printf("ret is %d\n", ret);
	ret = ft_printf("flag with zero '%#10.5o'\n", 123423);
	printf("ret is %d\n", ret);
	
	ret = printf("char '%-10c'\n", 'c');
	printf("ret is %d\n", ret);
	ret = ft_printf("char '%-10c'\n", 'c');
	printf("ret is %d\n", ret);
	/*
	ret = printf("testing %%p %p\n", test_pointer);
	printf("ret is %d\n", ret);
	ret = ft_printf("testing %%p %p\n", test_pointer);
	printf("ret is %d\n", ret);

	ft_putstr(ft_uintmax_itoa_base((uintmax_t)test_pointer, 16));
*/
//	while(1);
}