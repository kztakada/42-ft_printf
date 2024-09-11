/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:07:58 by katakada          #+#    #+#             */
/*   Updated: 2024/09/12 00:33:16 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(int fd, t_flags flags, va_list *args)
{
	if (flags.type == 'c')
		return (ft_putchar_fd(va_arg(*args, int), fd));
	if (flags.type == 's')
		return (ft_putstr_fd(va_arg(*args, char *), fd));
	if (flags.type == 'd' || flags.type == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), fd));
	if (flags.type == 'x')
		return (ft_putnbr_base((unsigned long)va_arg(*args, unsigned int),
				HEX_LOWER, fd));
	if (flags.type == 'X')
		return (ft_putnbr_base((unsigned long)va_arg(*args, unsigned int),
				HEX_UPPER, fd));
	if (flags.type == 'p')
		return (ft_putnbr_base_p((unsigned long long)va_arg(*args, void *),
				HEX_LOWER, fd));
	if (flags.type == 'u')
		return ((unsigned long)ft_putnbr_unsigned(va_arg(*args, unsigned int),
				fd));
	if (flags.type == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

void	ft_parse_format(const char **format, t_flags *flags)
{
	if (**format)
		flags->type = **format;
}

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

int	output_format(const char **format, t_flags *flags, va_list *args, int fd)
{
	(*format)++;
	if (is_flag(**format))
		parse_flags(format, flags);
	if (is_width_digit(**format))
		parse_width(format, flags, args);
	if (is_precision_dot(**format))
		parse_precision(format, flags, args);
	ft_parse_format(format, flags);
	return (printer(fd, *flags, args));
}
