/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:50 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/02 20:13:51 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

void	test_strings(int use_ftprintf)
{
	int		ret;
	int 	(*printf_ptr)(const char*, ...);
	char	unterminated_arr[10];

	strncpy(unterminated_arr, "test", 4);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;

	/* Test format strings without arguments */

	ret = printf_ptr("print without arguments\n");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print percentage: '%%'\n");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print percentage: '%-10.10%' and '%05%'\n");
	printf_ptr("ret is %d\n", ret);

	/* Test strings %s */

	ret = printf_ptr("testing string '%s' %%\n", "tester123456789");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("harder tests for %%.5s: '%.5s' %%s: '%s'\n%s\n%.100s\n", "adfghjklö", "asdfghjklö", "#saldka384972384edslnaclsalkc", "asdfg");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%.5s' %%\n", "tester123456789");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing empty string '%s'\n", "");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing empty string '%10s'\n", "");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%.4s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%.0s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%5.4s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%5.0s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%-.4s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing unterm string '%-.0s'\n", unterminated_arr);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%10.100s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%0100.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%-0100.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%0-100.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%0100.s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing string '%-0100s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("testing multiple strings '%%' '%s' '%0-100.100s' '%010.5s' '%.10s'\n", "asfdkoapvifmepcruinuiosnruoawesrxuesxs", "ASDFGÖRESDVX", "sfja sdjasdcasd", "");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("percentage string %s", "%");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("usr:     f f f f:       >>>%s %s %s %s  string. gg!<<<\n", "this", "is", "a", "multi");
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("usr:     f f f f:       >>>%s%s%s%s  string. gg!<<<\n", "this", "is", "a", "multi");
	printf_ptr("ret is %d\n", ret);

	/* Test chars %c */

	ret = printf_ptr("print null character '%c'\n", '\0');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("character tests: '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c'\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("character tests: '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c' '%c'\n", '1', '2', '3', '4', '5', '0', '*', '%', ' ', '\t', '\n', '-', 0, 47, 126, 125, 124, 123, 33, 34);
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print character '%010c'\n", '*');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("print character '%-010c'\n", '*');
	printf_ptr("ret is %d\n", ret);

	ret = printf_ptr("char '%-10c'\n", 'c');
	printf_ptr("ret is %d\n", ret);
}