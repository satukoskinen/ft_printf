/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:10 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/23 14:40:06 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		test_signed_integers(int use_ftprintf)
{
	int	ret;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;
	
	ret = printf_ptr("testing %% %d %i\n", 42, 42);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %% %d %i\n", 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %o\n", 42);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %o\n", 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %x %X\n", 42, 42);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %% %x %X\n", 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %d %+i % d\n", 42, 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %% %d %+i % d\n", 42, 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %o\n", 42);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %o\n", 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %x %X\n", 42, 42);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %% %x %X\n", 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %d %i %o %u %x %X\n", -42, -42, 42, 42, 42, 42);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %% %d %i %o %u %x %X\n", -42, -42, 42, 42, 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("flag with zero '%-10.8d'\n", -123423);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("flag with zero '%-10.8d'\n", -123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("flag with zero '%#10.5o'\n", 123423);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("flag with zero '%#10.5o'\n", 123423);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("char '%-10c'\n", 'c');
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("char '%-10c'\n", 'c');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print null character '%c'\n", '\0');
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("print null character '%c'\n", '\0');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#x'\n", 0);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("print zero '%#x'\n", 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#o'\n", 0);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("print zero '%#o'\n", 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#-5.x'\n", 0);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("print zero '%#-5.x'\n", 0);
	printf_ptr("ret is %d\n", ret);

/*
	ret = printf_ptr("testing %%p %p\n", test_pointer);
	printf_ptr("ret is %d\n", ret);
	ret = printf_ptr("testing %%p %p\n", test_pointer);
	printf_ptr("ret is %d\n", ret);
*/

	return (0);
}