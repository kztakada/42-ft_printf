/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_hex_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:32:57 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 19:40:46 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_blank_hex(t_flags *flags, int fd)
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

int	print_sharp_hex(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_sharp)
	{
		count = ft_putstr_fd("0x", fd);
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

int	print_prefix_hex(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = print_blank_hex(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_sharp_hex(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero_hex(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
