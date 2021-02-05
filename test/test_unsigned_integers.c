/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned_integers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/02 20:37:17 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	test_unsigned_integers(int use_ftprintf)
{
	int	ret;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;

	/* Test octal %o */

	ret = printf_ptr("testing %o\n", 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#o'\n", 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("flag with zero '%#10.5o'\n", 123423);
	printf_ptr("ret is %d\n", ret);

	/* Test unsigned decimal %u */

	/* Test hexadecimals %x %X */

	ret = printf_ptr("print zero '%#x'\n", 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#-5.x'\n", 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing %% %x %X\n", 42, 42);
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