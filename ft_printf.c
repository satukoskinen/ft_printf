/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:35:01 by skoskine          #+#    #+#             */
/*   Updated: 2021/02/02 09:57:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	parse_conversion(t_data *specs, va_list *ap, char **result)
{
	int		ret;

	ret = 1;
	if (specs->conversion == '%')
		ret = parse_percentage(specs, result);
	else if (specs->conversion == 'c')
		ret = parse_char(specs, va_arg(*ap, int), result);
	else if (specs->conversion == 's')
		ret = parse_string(specs, va_arg(*ap, char*), result);
	else if (specs->conversion == 'p')
		ret = parse_pointer(specs, va_arg(*ap, void*), result);
	else if (ft_strchr("di", specs->conversion))
		ret = parse_signed_ints(specs, ap, result);
	else if (ft_strchr("ouxX", specs->conversion))
		ret = parse_unsigned_ints(specs, ap, result);
	else if (ft_strchr("fF", specs->conversion))
		ret = parse_doubles(specs, ap, result); 
	else
		ret = -1;
	return (ret);
}

static int	append_to_result(char **result, int ret, int str_len, char *str)
{
	static int	arr_size = 100;

	if (str_len == -1)
		return (-1);
	if (*result == NULL)
	{
		if (!(*result = ft_memalloc(arr_size + 1)))
			return (-1);
	}
	if (ret + str_len > arr_size)
	{
		if (!(*result = ft_realloc(*result, arr_size,
		arr_size * 2 + str_len + 1)))
			return (-1);
		arr_size = arr_size * 2 + str_len;
	}
	ft_memcpy(&(*result)[ret], str, str_len);
	return (str_len);
}

static int	parse(const char *format, va_list *ap, char **result)
{
	int		i;
	int		ret;
	int		conv_len;
	char	*conversion;
	t_data	*conversion_specs;

	i = 0;
	ret = 0;
	if (!(conversion_specs = (t_data*)malloc(sizeof(t_data))))
		return (-1);
	while (format[i] && ret != -1)
	{
		if (format[i] == '%')
		{
			ft_memset((void*)conversion_specs, 0, sizeof(t_data));
			i += get_conversion_specs(conversion_specs, &format[i + 1]);
			conv_len = parse_conversion(conversion_specs, ap, &conversion);
			conv_len = append_to_result(result, ret, conv_len, conversion);
			free(conversion);
		}
		else
			conv_len = append_to_result(result, ret, 1, (char*)&format[i]);
		i++;
		ret = (conv_len == -1) ? -1 : ret + conv_len;
	}
	if (i == 0)
		*result = ft_strdup("");
	free(conversion_specs);
	return (ret);
}

int			ft_vasprintf(char **ret, const char *format, va_list ap)
{
	int		ret_value;
	va_list	ap_copy;

	va_copy(ap_copy, ap);
	ret_value = parse(format, &ap_copy, ret);
	va_end(ap_copy);
	return (ret_value);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*result;
	int		ret;

	result = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(&result, format, ap);
	va_end(ap);
	if (ret != 1)
		write(1, result, ret);
	free(result);
	return (ret);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	*result;
	int		ret;

	result = NULL;
	va_start(ap, format);
	ret = ft_vasprintf(&result, format, ap);
	va_end(ap);
	if (ret != 1)
		write(fd, result, ret);
	free(result);
	return (ret);
}

int			ft_asprintf(char **ret, const char *format, ...)
{
	va_list	ap;
	int		ret_value;

	va_start(ap, format);
	ret_value = ft_vasprintf(ret, format, ap);
	va_end(ap);
	return (ret_value);
}
