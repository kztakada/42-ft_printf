/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:00 by katakada          #+#    #+#             */
/*   Updated: 2024/10/06 15:12:38 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

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

void	prepare_format_flags(const char **format, t_flags *flags, va_list *args)
{
	if (is_format_flag(**format))
		set_format_flags(format, flags);
	if (is_field_digit(**format))
		set_format_field_size(format, flags, args);
	if (is_precision_dot(**format))
		set_format_precision(format, flags, args);
	if (is_format_type(**format))
		set_format_type(format, flags);
}

int	print_by_format_type(int fd, t_flags *flags, va_list *args)
{
	if (flags->type == 'c')
		return (print_char(va_arg(*args, int), flags, fd));
	if (flags->type == 's')
		return (print_str(va_arg(*args, char *), flags, fd));
	if (flags->type == 'd' || flags->type == 'i')
		return (print_int(va_arg(*args, int), flags, fd));
	if (flags->type == 'x')
		return (print_hex_base(va_arg(*args, unsigned int), flags, HEX_LOWER,
				fd));
	if (flags->type == 'X')
		return (print_hex_base(va_arg(*args, unsigned int), flags, HEX_UPPER,
				fd));
	if (flags->type == 'p')
		return (print_ptr((unsigned long long)va_arg(*args, void *), flags,
				fd));
	if (flags->type == 'u')
		return (print_u_int(va_arg(*args, unsigned int), flags, fd));
	if (flags->type == '%')
		return (print_percent(flags, fd));
	return (0);
}

int	print_format(const char **format, t_flags *flags, va_list *args, int fd)
{
	int	is_not_format;

	(*format)++;
	is_not_format = (!(is_format_type(**format) || is_format_flag(**format)
				|| is_field_digit(**format) || is_precision_dot(**format)));
	if (is_not_format)
		return (print_unformat(format, fd));
	prepare_format_flags(format, flags, args);
	if (flags->blank_size == -1)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	return (print_by_format_type(fd, flags, args));
}
