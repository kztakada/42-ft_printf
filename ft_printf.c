/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:34 by katakada          #+#    #+#             */
/*   Updated: 2024/09/10 19:37:06 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printer(t_flags flags, va_list ap)
{
	if (flags.type == 'c')
		return (ft_putchar(va_arg(ap, int)));
	if (flags.type == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (flags.type == 'd' || flags.type == 'i')
		return (ft_putnbr((long)va_arg(ap, int)));
	if (flags.type == 'x')
		return (ft_putnbr_base((unsigned long)va_arg(ap, unsigned int),
				HEX_LOWER));
	if (flags.type == 'X')
		return (ft_putnbr_base((unsigned long)va_arg(ap, unsigned int),
				HEX_UPPER));
	if (flags.type == 'p')
		return (ft_putnbr_base_p((unsigned long long)va_arg(ap, void *),
				HEX_LOWER));
	if (flags.type == 'u')
		return ((unsigned long)ft_putnbr_unsigned(va_arg(ap, unsigned int)));
	if (flags.type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	t_flags	flags;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			flags = ft_parse_format(format, &i);
			count += printer(flags, ap);
		}
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
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
