/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_validator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:29:07 by katakada          #+#    #+#             */
/*   Updated: 2024/10/14 18:13:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	has_invalid_char(const char **format, char valid_type)
{
	char	*format_pos;
	int		check_result;

	format_pos = (char *)*format;
	check_result = 0;
	while (*format_pos != valid_type)
	{
		if (!(is_field_digit(*format_pos) || is_precision_dot(*format_pos)
				|| is_format_type(*format_pos) || is_format_flag(*format_pos)))
			check_result = 1;
		format_pos++;
	}
	return (check_result);
}

int	is_format_flag_after_dot(const char **format, char valid_type)
{
	char	*format_pos;
	int		check_result;

	format_pos = (char *)*format;
	check_result = 0;
	while (*format_pos != valid_type)
	{
		if (*format_pos == '.')
			if (is_not_zero_format_flag(*(format_pos + 1)))
				check_result = 1;
		format_pos++;
	}
	return (check_result);
}

int	has_only_format_flag_after_dot(const char **format, char valid_type)
{
	char	*format_pos;

	format_pos = (char *)*format;
	while ((*format_pos) && (*format_pos) != '.')
		format_pos++;
	while ((*format_pos) && *format_pos != valid_type)
	{
		if (!(is_field_digit(*format_pos) || is_precision_dot(*format_pos)
				|| is_format_type(*format_pos) || is_format_flag(*format_pos)))
			return (0);
		if (is_not_zero_format_flag(*format_pos))
			return (1);
		format_pos++;
	}
	return (0);
}

int	has_no_zero_digit(const char **format)
{
	while ((**format) && ft_isdigit(**format))
	{
		if (**format != '0')
			return (1);
		(*format)++;
	}
	return (0);
}
