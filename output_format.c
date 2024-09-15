/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:07:58 by katakada          #+#    #+#             */
/*   Updated: 2024/09/15 15:28:07 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_spaces(int width, int fd, int c)
{
	int	count;

	count = 0;
	while (width-- > 0)
	{
		if (ft_putchar_fd(c, fd) < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	print_char(int c, t_flags *flags, int fd)
{
	int	count;
	int	space_count;

	count = 0;
	space_count = 0;
	flags->charactors = 1;
	set_char_space_conf(flags);
	if (flags->is_minus == 0)
	{
		if (ISLINUX == 1)
			space_count = print_spaces(flags->min_width - 1, fd, ' ');
		if (ISLINUX == 0)
			space_count = print_spaces(flags->min_width - 1, fd, '0');
	}
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	count++;
	if (flags->is_minus == 1)
		space_count = print_spaces(flags->min_width - 1, fd, ' ');
	if (space_count < 0)
		return (-1);
	return (count + space_count);
}

int	printer(int fd, t_flags *flags, va_list *args)
{
	if (flags->type == 'c')
		return (print_char(va_arg(*args, int), flags, fd));
	if (flags->type == 's')
		return (ft_putstr_fd(va_arg(*args, char *), fd));
	if (flags->type == 'd' || flags->type == 'i')
		return (ft_putnbr_fd(va_arg(*args, int), fd));
	if (flags->type == 'x')
		return (ft_putnbr_base((unsigned long)va_arg(*args, unsigned int),
				HEX_LOWER, fd));
	if (flags->type == 'X')
		return (ft_putnbr_base((unsigned long)va_arg(*args, unsigned int),
				HEX_UPPER, fd));
	if (flags->type == 'p')
		return (ft_putnbr_base_p((unsigned long long)va_arg(*args, void *),
				HEX_LOWER, fd));
	if (flags->type == 'u')
		return ((unsigned long)ft_putnbr_unsigned(va_arg(*args, unsigned int),
				fd));
	if (flags->type == '%')
		return (ft_putchar_fd('%', fd));
	return (0);
}

int	print_unformat(const char **format, int fd)
{
	if (ISLINUX == 1)
	{
		if (ft_putchar_fd(*--(*format), fd) < 0)
			return (-1);
		if (ft_putchar_fd(*++(*format), fd) < 0)
			return (-1);
		return (2);
	}
	else
	{
		if (ft_putchar_fd(**format, fd) < 0)
			return (-1);
		return (1);
	}
}

int	output_format(const char **format, t_flags *flags, va_list *args, int fd)
{
	(*format)++;
	if (!(is_format_type(**format) || is_flag(**format)
			|| is_width_digit(**format) || is_precision_dot(**format)))
		return (print_unformat(format, fd));
	if (is_flag(**format))
		parse_flags(format, flags);
	if (is_width_digit(**format))
		parse_width(format, flags, args);
	if (is_precision_dot(**format))
		parse_precision(format, flags, args);
	if (is_format_type(**format))
		parse_format(format, flags);
	return (printer(fd, flags, args));
}
