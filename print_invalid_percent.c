/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_invalid_percent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:42:57 by katakada          #+#    #+#             */
/*   Updated: 2024/10/13 20:43:37 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_invalid_percent_case(const char **format, int fd)
{
	int	count;

	count = 0;
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
