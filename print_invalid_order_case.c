/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_order_case.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:29:29 by katakada          #+#    #+#             */
/*   Updated: 2024/10/14 19:42:10 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_invalid_order_case(const char **format, int fd, t_flags *flags)

{
	int count;

	count = 0;
	flags->percent_print = 1;
	(*format)--;
	if (**format == '%')
	{
		if (ft_putchar_fd(**format, fd) < 0)
			return (-1);
		count++;
	}
	if (*(*format + 1) == '\0')
	{
		if (ft_putchar_fd(**format, fd) < 0)
			return (-1);
		count++;
	}
	return (count);
}
