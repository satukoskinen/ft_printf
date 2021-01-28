/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_doubles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:39:23 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/25 21:08:03 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>

char	*parse_double_result(t_data *specs, char *number, size_t result_len)
{
	char	*result;
	size_t	i;

	if (!(result = (char*)malloc(sizeof(char) * (result_len + 1))))
		return (NULL);
	i = 0;
	if (specs->min_field_width > 0 && !specs->zero_padding &&
	!specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	i += add_prefix(specs, &result[i]);
	if (specs->min_field_width > 0 && specs->zero_padding &&
	!specs->neg_field_width)
		i += add_padding(specs->min_field_width, '0', &result[i]);
	i += add_number(specs, number, &result[i]);
	if (specs->min_field_width > 0 && specs->neg_field_width)
		i += add_padding(specs->min_field_width, ' ', &result[i]);
	result[i] = '\0';
	return (result);
}

int		parse_doubles(t_data *specs, va_list *ap, char **result)
{
	long double	value;
	char		*number;
	size_t		result_len;

	result_len = 0;
	if (specs->length_modifier[0] == '\0' || specs->length_modifier[0] == 'l')
		value = (long double)va_arg(*ap, double);
	else
		value = va_arg(*ap, long double);
	if (!specs->has_precision)
		specs->precision = 6;
	specs->is_negative = (value < 0.0) ? 1 : 0;
	number = ft_long_dtoa(value, specs->precision);
	*result = parse_double_result(specs, number, result_len);
	free(number);
	return (result_len);
}
