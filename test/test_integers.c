/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:10 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/02 20:38:31 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	test_signed_integers(int use_ftprintf)
{
	int	ret;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;
	
	/* Test signed ints %d %i */
	
	ret = printf_ptr("testing %% %d %i\n", 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %d %+i % d\n", 42, 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %.1d %+.1i % d\n", 42, 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %d %i %o %u %x %X\n", -42, -42, 42, 42, 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("flag with zero '%-10.8d'\n", -123423);
	printf_ptr("ret is %d\n", ret);

	/*
	* min and max values, 0
	* length modifiers
	* alt form
	* precision
	* minimum field width
	* negative field width
	*/
}
	