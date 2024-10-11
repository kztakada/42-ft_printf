/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_validator.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 23:29:07 by katakada          #+#    #+#             */
/*   Updated: 2024/10/11 21:11:23 by katakada         ###   ########.fr       */
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

int	is_format_flag_after_field_size(const char **format)
{
	char	*format_pos;

	format_pos = (char *)*format;
	if (!ft_isdigit(*format_pos))
		return (0);
	while (ft_isdigit(*format_pos))
	{
		format_pos++;
	}
	while (*format_pos != 's')
	{
		if (is_not_zero_format_flag(*format_pos))
			return (1);
		format_pos++;
	}
	return (0);
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

int	can_use_precision_number(const char **format, t_flags *flags)
{
	if (is_not_zero_format_flag(**format))
		return (0);
	if (flags->precision == -1)
		return (0);
	if (!((**format == '*') || ft_isdigit(**format)))
	{
		flags->precision = -1;
		return (0);
	}
	return (1);
}
