/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_util_number_print.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:32:16 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 20:52:34 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_blank_space_nbr(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_minus == 0 && flags->is_zero == 0)
	{
		count = print_space_loop(flags->blank_size, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_flag_zero_hex(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_zero == 1 && flags->precision != -1)
	{
		count = print_zero_loop(flags->blank_size, fd);
		if (count < 0)
			return (-1);
		return (count);
	}
	if ((flags->is_zero == 0 && flags->is_minus == 0) || flags->is_minus == 1)
	{
		count = print_zero_loop(flags->precision, fd);
		if (count < 0)
			return (-1);
		return (count);
	}
	return (count);
}
