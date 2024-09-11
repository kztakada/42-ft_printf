/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:34 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 19:06:34 by katakada         ###   ########.fr       */
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

int	ft_vdprintf(int fd, const char *restrict format, va_list *args)
{
	int		i;
	int		count;
	t_flags	flags;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			flags = ft_parse_format(format, &i);
			count += printer(fd, flags, args);
		}
		else
		{
			if (ft_putchar_fd(format[i], fd) < 0)
				return (-1);
			count++;
		}
		if (count < 0)
			return (-1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	if (!format)
		return (-1);
	count = 0;
	va_start(args, format);
	count = ft_vdprintf(STDOUT_FILENO, format, &args);
	va_end(args);
	return (count);
}

t_flags	ft_parse_format(const char *format, int *i)
{
	t_flags	flags;

	flags.zero = 0;
	flags.minus = 0;
	flags.width = 0;
	flags.precision = 0;
	flags.star = 0;
	flags.type = 0;
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0')
			flags.zero = 1;
		if (format[*i] == '-')
			flags.minus = 1;
		(*i)++;
	}
	if (format[*i] == '*')
	{
		flags.star = 1;
		(*i)++;
	}
	if (format[*i] >= '0' && format[*i] <= '9')
	{
		flags.width = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	if (format[*i] == '.')
	{
		(*i)++;
		flags.precision = ft_atoi(&format[*i]);
		while (format[*i] >= '0' && format[*i] <= '9')
			(*i)++;
	}
	if (format[*i])
		flags.type = format[*i];
	return (flags);
}
