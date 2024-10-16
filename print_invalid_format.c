/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_format.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 20:03:40 by katakada          #+#    #+#             */
/*   Updated: 2024/10/16 18:23:49 by katakada         ###   ########.fr       */
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

int	print_invalid_char_start_case(const char **format, int fd)
{
	int	count;

	count = 0;
	if (ISLINUX == 1)
	{
		(*format)--;
		while (**format != '\0')
		{
			if (ft_putchar_fd(**format, fd) < 0)
				return (-1);
			count++;
			(*format)++;
			if (**format != '%')
				break ;
		}
		(*format)--;
		return (count);
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
