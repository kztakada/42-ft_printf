/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:07:58 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 20:10:46 by katakada         ###   ########.fr       */
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

t_flags	ft_parse_format(const char **format)
{
	t_flags	flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.star = 0;
	flags.type = 0;
	while (**format == '0' || **format == '-')
	{
		if (**format == '0')
			flags.zero = 1;
		if (**format == '-')
			flags.minus = 1;
		(*format)++;
	}
	if (**format == '*')
	{
		flags.star = 1;
		(*format)++;
	}
	if (**format >= '0' && **format <= '9')
	{
		flags.width = ft_atoi(&**format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		flags.precision = ft_atoi(&**format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	if (**format)
		flags.type = **format;
	return (flags);
}

int	output_format(const char **format, t_flags *flags, va_list *args, int fd)
{
	(*format)++;
	*flags = ft_parse_format(format);
	return (printer(fd, *flags, args));
}
