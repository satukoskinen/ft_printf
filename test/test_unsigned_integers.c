/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned_integers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/05 21:53:58 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

void	test_unsigned_integers(int use_ftprintf)
{
	int	ret;
	int	o_u_x_X;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;

	/* Basic tests for %o %u %x %X */

	o_u_x_X = 0;

	ret = printf_ptr("7 '%o' '%u' '%x' '%X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("8 '%10o' '%10u' '%10x' '%10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10o' '%.10u' '%.10x' '%.10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1o' '%5.1u'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0o' '%5.0u' '%5.0x' '%5.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010o' '%010u' '%010x' '%010X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0o' '%05.0u' '%05.0x' '%05.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5o' '%01.5u' '%01.5x' '%01.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5o' '%+1.5u' '%+1.5x' '%+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5o' '%#+1.5u' '%#+1.5x' '%#+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5o' '%-#+1.5u' '%-#+1.5x' '%-#+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("18 '%-#+ 1.5o' '%-#+ 1.5u' '%-#+ 1.5x' '%-#+ 1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5o' '%#-+ 1.5u' '%#-+ 1.5x' '%#-+ 1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5o' '% #-1.5u' '% #-1.5x' '% #-1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0o' '% #-1.0u' '% #-1.0x' '% #-1.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10o' '% #-10.10u' '% #-10.10x' '% #-10.10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10o' '% #-10u' '% #-10x' '% #-10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.o' '%.u' '%.x' '%.X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	o_u_x_X = 392082;

	ret = printf_ptr("7 '%o' '%u' '%x' '%X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("8 '%10o' '%10u' '%10x' '%10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10o' '%.10u' '%.10x' '%.10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1o' '%5.1u'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0o' '%5.0u' '%5.0x' '%5.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010o' '%010u' '%010x' '%010X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0o' '%05.0u' '%05.0x' '%05.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5o' '%01.5u' '%01.5x' '%01.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5o' '%+1.5u' '%+1.5x' '%+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5o' '%#+1.5u' '%#+1.5x' '%#+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5o' '%-#+1.5u' '%-#+1.5x' '%-#+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("18 '%-#+ 1.5o' '%-#+ 1.5u' '%-#+ 1.5x' '%-#+ 1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5o' '%#-+ 1.5u' '%#-+ 1.5x' '%#-+ 1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5o' '% #-1.5u' '% #-1.5x' '% #-1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0o' '% #-1.0u' '% #-1.0x' '% #-1.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10o' '% #-10.10u' '% #-10.10x' '% #-10.10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10o' '% #-10u' '% #-10x' '% #-10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.o' '%.u' '%.x' '%.X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	o_u_x_X = UINT_MAX;

	ret = printf_ptr("7 '%o' '%u' '%x' '%X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("8 '%10o' '%10u' '%10x' '%10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10o' '%.10u' '%.10x' '%.10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1o' '%5.1u'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0o' '%5.0u' '%5.0x' '%5.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010o' '%010u' '%010x' '%010X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0o' '%05.0u' '%05.0x' '%05.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5o' '%01.5u' '%01.5x' '%01.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5o' '%+1.5u' '%+1.5x' '%+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5o' '%#+1.5u' '%#+1.5x' '%#+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5o' '%-#+1.5u' '%-#+1.5x' '%-#+1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("18 '%-#+ 1.5o' '%-#+ 1.5u' '%-#+ 1.5x' '%-#+ 1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5o' '%#-+ 1.5u' '%#-+ 1.5x' '%#-+ 1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5o' '% #-1.5u' '% #-1.5x' '% #-1.5X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0o' '% #-1.0u' '% #-1.0x' '% #-1.0X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10o' '% #-10.10u' '% #-10.10x' '% #-10.10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10o' '% #-10u' '% #-10x' '% #-10X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.o' '%.u' '%.x' '%.X'\n", o_u_x_X, o_u_x_X, o_u_x_X, o_u_x_X);
	printf_ptr("ret is %d\n", ret);

	// Test octal %o 

	ret = printf_ptr("testing %o\n", 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#o'\n", 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form '%#10.5o'\n", 123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#10.8o'\n", 123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#.o'\n", 123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("octal alt form zero '%#o'\n", 123423);
	printf_ptr("ret is %d\n", ret);

	// Test unsigned decimal %u 

	

	// Test hexadecimals %x %X

	ret = printf_ptr("print zero '%#x' '%#X'\n", 0, 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print zero '%#-5.x' '%#-5.X'\n", 0, 0);
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