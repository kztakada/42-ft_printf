/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_parsers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 18:49:36 by katakada          #+#    #+#             */
/*   Updated: 2024/09/13 23:41:54 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char **format, t_flags *flags)
{
	while (is_flag(**format))
	{
		if (**format == '-')
			flags->is_minus = 1;
		if (**format == '0')
			flags->is_zero = 1;
		if (**format == '#')
			flags->is_sharp = 1;
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

void	parse_width(const char **format, t_flags *flags, va_list *args)
{
	if (**format == '*')
	{
		flags->min_width = va_arg(*args, int);
		(*format)++;
	}
	else
	{
		flags->min_width = ft_atoi(&**format);
		while (ft_isdigit(**format))
			(*format)++;
	}
}

void	parse_precision(const char **format, t_flags *flags, va_list *args)
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

void	parse_format(const char **format, t_flags *flags)
{
	if (**format)
		flags->type = **format;
}
