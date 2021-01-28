/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_doubles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 12:55:43 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/25 19:12:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	test_doubles(int use_ftprintf)
{
	int	ret;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;

	ret = printf_ptr("basic double %f", (double)3.14159265);
	printf_ptr("ret is %d\n", ret);
}