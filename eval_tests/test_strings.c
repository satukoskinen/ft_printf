/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:50 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/23 14:31:26 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		test_strings(int use_ftprintf)
{
	int	ret;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;

	ret = printf_ptr("print without arguments\n");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print percentage: %%\n");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%s' %%\n", "tester123456789");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("harder tests for %%.5s: '%.5s' %%s: '%s'\n%s\n%.100s\n", "adfghjklö", "asdfghjklö", "#saldka384972384edslnaclsalkc", "asdfg");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%.5s' %%\n", "tester123456789");
	printf_ptr("ret is %d\n", ret);

	return (0);
}