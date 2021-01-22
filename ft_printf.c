/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:35:01 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/22 10:03:22 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int				parse_conversion(t_data *specs, va_list *ap)
{
	int		ret;

	ret = 1;
	if (specs->is_percentage == 1)
		write(1, "%", 1);
	else if (specs->conversion == 'c')
		ret = parse_char(specs, va_arg(*ap, int));
	else if (specs->conversion == 's')
		ret = parse_string(specs, va_arg(*ap, char*));
	else if (specs->conversion == 'p')
		ret = parse_pointer(specs, ap);
	else if (ft_strchr("di", specs->conversion))
		ret = parse_signed_ints(specs, ap);
	else if (ft_strchr("ouxX", specs->conversion))
		ret = parse_unsigned_ints(specs, ap);
	else if (ft_strchr("fF", specs->conversion))
		ret = parse_doubles(specs, ap);
	else
		ret = -1;
	return (ret);
}

static int		parse(const char *format, va_list *ap)
{
	int		i;
	int		ret;
	t_data	*conversion_specs;

	i = 0;
	ret = 0;
	if (!(conversion_specs = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			ft_memset((void*)conversion_specs, 0, sizeof(t_data));
			i += get_conversion_specs(conversion_specs, &format[i + 1]);
			ret += parse_conversion(conversion_specs, ap);
		}
		else
		{
			write(1, &format[i], 1);
			ret++;
		}
		i++;
	}
	free(conversion_specs);
	return (ret);
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = parse(format, &ap);
	va_end(ap);
	return (ret);
}
