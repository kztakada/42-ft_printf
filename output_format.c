/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:07:58 by katakada          #+#    #+#             */
/*   Updated: 2024/09/15 20:53:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif
#include <stdio.h>

int	print_loop(int loop_times, int fd, int c)
{
	int	count;

	count = 0;
	while (loop_times-- > 0)
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
	set_char_print_conf(flags);
	if (flags->is_minus == 0)
	{
		if (ISLINUX == 1)
			space_count = print_loop(flags->min_width - 1, fd, ' ');
		if (ISLINUX == 0)
			space_count = print_loop(flags->min_width - 1, fd, '0');
	}
	if (space_count < 0)
		return (-1);
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	count++;
	if (flags->is_minus == 1)
		space_count = print_loop(flags->min_width - 1, fd, ' ');
	if (space_count < 0)
		return (-1);
	return (count + space_count);
}

int	print_str(char *str, t_flags *flags, int fd)
{
	int		count;
	int		space_count;
	char	*output_str;

	space_count = 0;
	if (!str)
		str = "(null)";
	set_str_print_conf(flags, str);
	if (flags->is_minus == 0)
		space_count = print_loop(flags->min_width, fd, ' ');
	if (space_count < 0)
		return (-1);
	output_str = ft_substr(str, 0, flags->charactors);
	if (!output_str)
		return (-1);
	count = ft_putstr_fd(output_str, fd);
	free(output_str);
	if (count < 0)
		return (-1);
	if (flags->is_minus == 1)
		space_count = print_loop(flags->min_width, fd, ' ');
	if (space_count < 0)
		return (-1);
	return (count + space_count);
}

int	print_sign(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->sign == -1)
		count += ft_putchar_fd('-', fd);
	else if (flags->is_plus == 1)
		count += ft_putchar_fd('+', fd);
	else if (flags->is_space == 1)
		count += ft_putchar_fd(' ', fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	print_left_shift(int fd, t_flags *flags)
{
	int	count;
	int	cnt_tmp;

	cnt_tmp = 0;
	if (flags->is_minus == 1 || flags->is_zero == 1)
		count = print_sign(flags, fd);
	else
		return (0);
	if (count < 0)
		return (-1);
	if (count == 1)
	{
		if (flags->is_minus == 1)
			cnt_tmp = print_loop(flags->precision, fd, '0');
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
		if (flags->is_zero == 1 && flags->precision != -1)
			cnt_tmp = print_loop(flags->min_width - flags->precision, fd, '0');
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_right_shift(int fd, t_flags *flags)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = 0;
	if (flags->is_minus == 0)
	{
		if (flags->is_zero != 1)
		{
			cnt_tmp = print_loop(flags->min_width, fd, ' ');
			if (cnt_tmp < 0)
				return (-1);
			count += cnt_tmp;
			cnt_tmp = print_sign(flags, fd);
			if (cnt_tmp < 0)
				return (-1);
			count += cnt_tmp;
		}
		cnt_tmp = print_loop(flags->precision, fd, '0');
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}
int	print_put_nbr(int fd, t_flags *flags, long output_nbr)
{
	int	count;
	int	cnt_tmp;

	cnt_tmp = 0;
	if (flags->charactors != 0)
		cnt_tmp = ft_putnbr_fd(output_nbr, fd);
	if (cnt_tmp < 0)
		return (-1);
	count = cnt_tmp;
	if (flags->is_minus == 1)
	{
		cnt_tmp = print_loop(flags->min_width, fd, ' ');
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_nbr(int n, t_flags *flags, int fd)
{
	int		count;
	int		cnt_tmp;
	long	output_nbr;

	count = 0;
	cnt_tmp = 0;
	output_nbr = (long)n;
	set_nbr_print_conf(flags, &output_nbr);
	cnt_tmp = print_left_shift(fd, flags);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_right_shift(fd, flags);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_put_nbr(fd, flags, output_nbr);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}

int	printer(int fd, t_flags *flags, va_list *args)
{
	if (flags->type == 'c')
		return (print_char(va_arg(*args, int), flags, fd));
	if (flags->type == 's')
		return (print_str(va_arg(*args, char *), flags, fd));
	if (flags->type == 'd' || flags->type == 'i')
		return (print_nbr(va_arg(*args, int), flags, fd));
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
