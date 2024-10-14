/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:03:40 by katakada          #+#    #+#             */
/*   Updated: 2024/10/14 20:32:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_only_format_specifier(const char **format, int fd)
{
	if (ft_putchar_fd('%', fd) < 0)
		return (-1);
	(*format)--;
	return (1);
}

int	print_not_format_char(const char **format, int fd, t_flags *flags)
{
	if (ISLINUX == 1)
	{
		flags->percent_print = 1;
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

int	print_invalid_after_dot(const char **format, int fd)
{
	int	count;

	count = 0;
	if (has_no_zero_digit(format))
	{
		while ((**format) && (**format) == '0')
			(*format)++;
		while ((**format) && ft_isdigit(**format))
		{
			if (ft_putchar_fd((**format), fd) < 0)
				return (-1);
			count++;
			(*format)++;
		}
	}
	else
	{
		if (ft_putchar_fd('0', fd) < 0)
			return (-1);
		count++;
	}
	return (count);
}

int	print_invalid_after_dot_case(const char **format, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	(*format)--;
	while ((**format) && (**format) != '.')
	{
		if (ft_putchar_fd((**format), fd) < 0)
			return (-1);
		count++;
		(*format)++;
	}
	if (ft_putchar_fd((**format), fd) < 0)
		return (-1);
	count++;
	(*format)++;
	cnt_tmp = print_invalid_after_dot(format, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	while ((**format) && ft_isdigit(**format))
		(*format)++;
	(*format)--;
	return (count);
}

int	print_over_flow_case(void)
{
	errno = EOVERFLOW;
	return (-1);
}
