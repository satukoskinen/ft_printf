/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:39:23 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/21 16:13:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int		parse_double(t_data *specs, double value)
{
	if (specs && value)
		;
	return (0);
}

int		parse_long_double(t_data *specs, long double value)
{
	if (specs && value)
		;
	return (0);
}

int		parse_doubles(t_data *specs, va_list *ap)
{
	int ret;

	if (specs->length_modifier[0] == '\0' || specs->length_modifier[0] == 'l')
		ret = parse_double(specs, va_arg(*ap, double));
	else
		ret = parse_long_double(specs, va_arg(*ap, long double));
	return (ret);
}
