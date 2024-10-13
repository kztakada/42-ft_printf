/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_percent_validator.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:39:38 by katakada          #+#    #+#             */
/*   Updated: 2024/10/13 20:40:06 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_no_number_after_format_flags(const char **format)
{
	while ((**format) && is_format_flag(**format))
		(*format)++;
	if (is_field_digit(**format) || **format == '.' || **format == '*'
		|| **format == '%')
		return (0);
	return (1);
}

int	has_no_dot_after_digit(const char **format)
{
	while ((**format) && is_field_digit(**format))
		(*format)++;
	if (**format == '.' || **format == '%')
		return (0);
	return (1);
}

int	has_no_dot_after_star(const char **format)
{
	(*format)++;
	if (**format == '.' || **format == '%')
		return (0);
	return (1);
}

int	has_no_number_after_dot(const char **format)
{
	(*format)++;
	if (is_field_digit(**format) || **format == '*' || **format == '%')
	{
		if (**format == '*')
		{
			(*format)++;
			return (0);
		}
		while ((**format) && is_field_digit(**format))
			(*format)++;
		return (0);
	}
	return (1);
}

int	is_invalid_percent_case(const char **format)
{
	const char	*format_pos;
	int			check_result;

	check_result = 0;
	format_pos = (char *)*format;
	if (is_format_flag(*format_pos))
		check_result = has_no_number_after_format_flags(&format_pos);
	if (ft_isdigit(*format_pos))
		check_result = has_no_dot_after_digit(&format_pos);
	if (*format_pos == '*')
		check_result = has_no_dot_after_star(&format_pos);
	if (*format_pos == '.')
		check_result = has_no_number_after_dot(&format_pos);
	if (*format_pos == '%' && check_result == 0)
		return (0);
	return (1);
}
