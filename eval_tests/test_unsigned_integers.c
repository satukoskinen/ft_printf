/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_unsigned_integers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:07:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/23 14:40:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		test_unsigned_integers(int use_ftprintf)
{
	int	ret;
	int (*printf_ptr)(const char*, ...);

	if (use_ftprintf)
		printf_ptr = ft_printf;
	else
		printf_ptr = printf;
		
	ret = 0;
	return (0);
}