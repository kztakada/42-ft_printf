/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:13:00 by katakada          #+#    #+#             */
/*   Updated: 2024/10/10 19:02:26 by katakada         ###   ########.fr       */
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

void	flag_check_loop(const char **format, t_flags *flags, va_list *args)
{
	int	is_search_end;

	is_search_end = 0;
	while (**format && !is_search_end)
	{
		if (is_format_flag(**format))
			set_format_flags(format, flags);
		if (is_field_digit(**format))
			set_format_field_size(format, flags, args);
		if (is_precision_dot(**format))
			set_format_precision(format, flags, args);
		if (is_format_type(**format))
			is_search_end = 1;
		if (**format && !(is_format_flag(**format) || is_field_digit(**format)
				|| is_precision_dot(**format) || is_format_type(**format))
			&& !(flags->precision == -1))
		{
			flags->precision = -1;
			(*format)--;
			break ;
		}
		if (flags->precision == -1)
			is_search_end = 1;
	}
}

int	linux_str_test(const char **format)
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
		if (is_format_flag(*format_pos) && *format_pos != '0')
			return (-1);
		format_pos++;
	}
	return (0);
}

int	str_test(const char **format)
{
	char	*format_pos;
	int		check_result;

	format_pos = (char *)*format;
	check_result = 0;
	while (*format_pos != 's')
	{
		if (*format_pos == '.')
			if (is_format_flag(*(format_pos + 1)) && *(format_pos + 1) != '0')
				check_result = -1;
		format_pos++;
	}
	return (check_result);
}

int	prepare_format_flags(const char **format, t_flags *flags, va_list *args)
{
	char	*format_pos;

	format_pos = (char *)*format;
	while (*format_pos)
	{
		if (is_format_type(*format_pos))
		{
			set_format_type(format_pos, flags);
			break ;
		}
		format_pos++;
	}
	if (ISLINUX == 1 && flags->type == 's')
		if (linux_str_test(format) == -1)
			return (-1);
	if (flags->type == 's')
		if (str_test(format) == -1)
			flags->precision = -3;
	// if (is_field_digit(**format) && **format != '0')
	// 	set_format_field_size(format, flags, args);
	flag_check_loop(format, flags, args);
	return (0);
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
	int	count;
	int	is_not_format;

	(*format)++;
	is_not_format = (!(is_format_type(**format) || is_format_flag(**format)
				|| is_field_digit(**format) || is_precision_dot(**format)));
	if (is_not_format)
		return (print_unformat(format, fd));
	if (prepare_format_flags(format, flags, args) == -1)
	{
		if (ft_putchar_fd('%', fd) < 0)
			return (-1);
		(*format)--;
		return (1);
	}
	if (flags->blank_size == -1)
	{
		errno = EOVERFLOW;
		return (-1);
	}
	count = print_by_format_type(fd, flags, args);
	if (count < 0)
		return (-1);
	return (count);
}
