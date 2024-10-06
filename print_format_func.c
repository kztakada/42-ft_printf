/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format_func.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:13:27 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 20:13:28 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_format_flags(const char **format, t_flags *flags)
{
	while (is_format_flag(**format))
	{
		if (**format == '-')
			flags->is_minus = 1;
		if (**format == '0')
			flags->is_zero = 1;
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
		flags->blank_size = ft_atoi(&**format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	set_format_precision(const char **format, t_flags *flags, va_list *args)
{
	(*format)++;
	if (!((**format == '*') || ft_isdigit(**format)))
	{
		flags->precision = -1;
		return ;
	}
	if (**format == '*')
	{
		flags->precision = va_arg(*args, int);
		(*format)++;
		return ;
	}
	flags->precision = ft_atoi(&**format);
	while (ft_isdigit(**format))
		(*format)++;
	if (flags->precision == 0)
		flags->precision = -2;
	if (is_number_type(**format))
		flags->is_zero = 0;
}

void	set_format_type(const char **format, t_flags *flags)
{
	if (**format)
		flags->type = **format;
}