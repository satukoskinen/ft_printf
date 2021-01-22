/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_signed_integers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:39:54 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/22 09:44:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static intmax_t	get_signed_arg(t_data *specs, va_list *ap)
{
	intmax_t	value;

	if (ft_strcmp(specs->length_modifier, "hh") == 0)
		value = (intmax_t)va_arg(*ap, int);
	else if (ft_strcmp(specs->length_modifier, "h") == 0)
		value = (intmax_t)va_arg(*ap, int);
	else if (ft_strcmp(specs->length_modifier, "ll") == 0)
		value = (intmax_t)va_arg(*ap, long long);
	else if (ft_strcmp(specs->length_modifier, "l") == 0)
		value = (intmax_t)va_arg(*ap, long);
	else
		value = (intmax_t)va_arg(*ap, int);
	return (value);
}

int				parse_signed_ints(t_data *specs, va_list *ap)
{
	intmax_t	value;
	char		*number;
	char		*result;
	size_t		result_len;

	value = get_signed_arg(specs, ap);
	number = ft_intmax_itoa_base(value, 10);
	result_len = ft_strlen(number);
	specs->is_negative = value < 0 ? 1 : 0;
	if (specs->precision > 0)
		specs->zero_padding = 0;
	specs->precision = (specs->precision > result_len - specs->is_negative) ?
		(specs->precision - result_len + specs->is_negative) : 0;
	result_len += specs->precision;
	if (value >= 0 && (specs->plus_signed || specs->blank_signed))
		result_len += 1;
	specs->min_field_width = (specs->min_field_width > result_len) ?
		(specs->min_field_width - result_len) : 0;
	result_len += specs->min_field_width;
	result = parse_int_result(specs, number, result_len);
	free(number);
	ft_putstr(result);
	return (result_len);
}
