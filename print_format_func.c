/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:13:27 by katakada          #+#    #+#             */
/*   Updated: 2024/10/10 19:04:10 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_format_flags(const char **format, t_flags *flags)
{
	while (is_format_flag(**format))
	{
		if (**format == '-')
			flags->is_minus = 1;
		if (**format == '0' && (*(*format + 1) != '.'))
		{
			flags->is_zero = 1;
		}
		if (**format == '#')
			flags->is_sharp = 2;
		if (**format == ' ')
			flags->is_space = 1;
		if (**format == '+')
			flags->is_plus = 1;
		(*format)++;
	}
	if (flags->is_minus)
		flags->is_zero = 0;
	if (flags->is_plus)
		flags->is_space = 0;
}

int	ascii_to_field_size(const char *str_pos)
{
	unsigned long	int_value;
	int				digit_value;
	unsigned long	max_limit;

	int_value = 0;
	max_limit = (unsigned long)INT_MAX;
	while (ft_isdigit(*str_pos))
	{
		digit_value = *str_pos - '0';
		if (int_value > ((max_limit - digit_value) / 10))
			return (-1);
		int_value = int_value * 10 + digit_value;
		str_pos++;
	}
	return ((int)int_value);
}

void	set_format_field_size(const char **format, t_flags *flags,
		va_list *args)
{
	if (**format == '*')
	{
		flags->blank_size = va_arg(*args, int);
		(*format)++;
	}
	else
	{
		flags->blank_size = ascii_to_field_size(&**format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

int	is_precheck_flag(int c)
{
	return (c == '-' || c == '#' || c == ' ' || c == '+');
}
void	flag_precheck_loop(const char **format, t_flags *flags)
{
	while (**format && (is_precheck_flag(**format)))
	{
		if (is_format_flag(**format))
		{
			set_format_flags(format, flags);
			flags->precision = -1;
		}
		if (is_precision_dot(**format))
			(*format)++;
	}
}

void	set_format_precision(const char **format, t_flags *flags, va_list *args)
{
	(*format)++;
	if (flags->precision == -3 && flags->type == 's')
	{
		while (ft_isdigit(**format) || **format == '*')
			(*format)++;
		return ;
	}
	flags->precision = 0;
	while ((**format) == '.')
	{
		(*format)++;
	}
	if (is_precheck_flag(**format))
		return ;
	if (flags->precision == -1)
		return ;
	if (!((**format == '*') || ft_isdigit(**format)))
	{
		flags->precision = -1;
		return ;
	}
	if (**format == '*')
	{
		flags->precision = va_arg(*args, int);
		(*format)++;
		// return ;
	}
	else
		flags->precision = ft_atoi(&**format);
	flags->is_zero = 0;
	while (ft_isdigit(**format))
		(*format)++;
	if (flags->precision == 0)
		flags->precision = -2;
	if (is_number_type(**format))
		flags->is_zero = 0;
}

void	set_format_type(const char *format, t_flags *flags)
{
	if (*format)
		flags->type = *format;
}
