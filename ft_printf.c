/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:34 by katakada          #+#    #+#             */
/*   Updated: 2024/10/14 21:14:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_format_or_char(int fd, const char **format, t_flags *flags,
		va_list *args)
{
	int	count;

	count = 0;
	if (**format == '%')
	{
		if (*(*format + 1) == '\0')
			return (-2);
		count = print_format(format, flags, args, fd);
		if (count < 0)
			return (-1);
		return (count);
	}
	if (ft_putchar_fd(**format, fd) < 0)
		return (-1);
	return (1);
}

int	print_end_of_percent(const char **format, t_flags *flags, int fd, int count)
{
	if (flags->percent_print == 1)
		if (ft_putchar_fd(**format, fd) > 0)
			return (count + 1);
	errno = EINVAL;
	return (-1);
}

int	ft_vdprintf(int fd, const char *format, va_list *args)
{
	int		count;
	int		cnt_tmp;
	t_flags	flags;

	count = 0;
	ft_bzero(&flags, sizeof(flags));
	while (*format != '\0')
	{
		if (ISLINUX == 1 && *(format) == '%' && *(format + 1) == '\0')
			return (print_end_of_percent(&format, &flags, fd, count));
		ft_bzero(&flags, sizeof(flags));
		cnt_tmp = print_format_or_char(fd, &format, &flags, args);
		if (cnt_tmp == -2)
			break ;
		if (cnt_tmp == -1)
			return (-1);
		count += cnt_tmp;
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
