/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 09:35:48 by skoskine          #+#    #+#             */
/*   Updated: 2021/01/22 10:03:47 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <inttypes.h>
# include <stdarg.h>
# include <stddef.h>

typedef	struct	s_data
{
	int			is_percentage;
	int			alt_form;
	int			zero_padding;
	int			neg_field_width;
	int			blank_signed;
	int			plus_signed;
	int			is_negative;
	size_t		min_field_width;
	size_t		precision;
	char		length_modifier[3];
	char		conversion;
}				t_data;

int				ft_printf(const char *format, ...);

int				get_conversion_specs(t_data *specs, const char *format);
int				parse_string(t_data *specs, char *str);
int				parse_char(t_data *specs, char c);
int				parse_pointer(t_data *specs, va_list *ap);
int				parse_ints(t_data *specs, va_list *ap);
int				parse_unsigned_ints(t_data *specs, va_list *ap);
int				parse_signed_ints(t_data *specs, va_list *ap);
int				parse_doubles(t_data *specs, va_list *ap);
int				parse_double(t_data *specs, double value);
int				parse_long_double(t_data *specs, long double value);

char			*parse_int_result(t_data *specs, char *number, size_t result_len);
size_t			add_padding(size_t len, char c, char *result);


#endif
