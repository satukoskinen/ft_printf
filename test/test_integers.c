/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_integers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:10 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/05 22:02:52 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

void	test_signed_integers(int use_ftprintf)
{
	int	ret;
	int	d_i;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;
	
	/* Test signed ints %d %i */
	
	ret = printf_ptr("1 testing %%d %%i '%d' '%i'\n", 42, 42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("2 testing %%d %%i '%d' '%i'\n", -42, -42);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("3 zeros %%d %%i '%d' '%i'\n", 0, 0);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("4 testing %%+i %% d '%+i' '% d'\n", 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("5 testing %%.1d %%+.1i %% d '%.1d' '%+.1i' '% d'\n", 42, 2147483647, -2147483647 - 1);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6a '%-10000.8d'\n", -123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b '%-10.8000d'\n", -123423);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("6b '%010000.8000d'\n", -123423);
	printf_ptr("ret is %d\n", ret);

	d_i = 0;

	ret = printf_ptr("7 '%d' '%i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("8 '%10d' '%10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10d' '%.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1d' '%5.1i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0d' '%5.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010d' '%010i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0d' '%05.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5d' '%01.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5d' '%+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5d' '%#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5d' '%-#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("18 '%-#+ 1.5d' '%-#+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5d' '%#-+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5d' '% #-1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0d' '% #-1.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10d' '% #-10.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10d' '% #-10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.d' '%.i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	d_i = 392082;

	ret = printf_ptr("8 '%10d' '%10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10d' '%.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1d' '%5.1i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0d' '%5.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010d' '%010i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0d' '%05.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5d' '%01.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5d' '%+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5d' '%#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5d' '%-#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("18 '%-#+ 1.5d' '%-#+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5d' '%#-+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5d' '% #-1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0d' '% #-1.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10d' '% #-10.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10d' '% #-10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.d' '%.i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	d_i = -392082;

	ret = printf_ptr("8 '%10d' '%10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10d' '%.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1d' '%5.1i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0d' '%5.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010d' '%010i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0d' '%05.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5d' '%01.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5d' '%+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5d' '%#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5d' '%-#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("18 '%-#+ 1.5d' '%-#+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5d' '%#-+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5d' '% #-1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0d' '% #-1.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10d' '% #-10.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10d' '% #-10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.d' '%.i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	d_i = INT_MAX;

	ret = printf_ptr("8 '%10d' '%10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10d' '%.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1d' '%5.1i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0d' '%5.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010d' '%010i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0d' '%05.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5d' '%01.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5d' '%+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5d' '%#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5d' '%-#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("18 '%-#+ 1.5d' '%-#+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5d' '%#-+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5d' '% #-1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0d' '% #-1.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10d' '% #-10.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10d' '% #-10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.d' '%.i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	d_i = INT_MIN;

	ret = printf_ptr("8 '%10d' '%10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("9 '%.10d' '%.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("10 '%5.1d' '%5.1i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("11 '%5.0d' '%5.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("12 '%010d' '%010i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("13 '%05.0d' '%05.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("14 '%01.5d' '%01.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("15 '%+1.5d' '%+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("16 '%#+1.5d' '%#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("17 '%-#+1.5d' '%-#+1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("18 '%-#+ 1.5d' '%-#+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("19 '%#-+ 1.5d' '%#-+ 1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("20 '% #-1.5d' '% #-1.5i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);
	
	ret = printf_ptr("21 '% #-1.0d' '% #-1.0i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("22 '% #-10.10d' '% #-10.10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("23 '% #-10d' '% #-10i'\n", d_i, d_i);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("24 '%.d' '%.i'\n", d_i, d_i);
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
	