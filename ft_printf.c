/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:34 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 20:10:07 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_vdprintf(int fd, const char *format, va_list *args)
{
	int		count;
	t_flags	flags;

	if (!format)
		return (-1);
	count = 0;
	while (*format != '\0')
	{
		ft_bzero(&flags, sizeof(flags));
		if (*format == '%')
			count += output_format(&format, &flags, args, fd);
		else
		{
			if (ft_putchar_fd(*format, fd) < 0)
				return (-1);
			count++;
		}
		if (count < 0)
			return (-1);
		format++;
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
