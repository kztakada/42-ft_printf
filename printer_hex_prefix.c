/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_hex_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:32:57 by katakada          #+#    #+#             */
/*   Updated: 2024/10/04 19:51:39 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_flag_minus(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	if (flags->is_minus == 1 && flags->is_sharp == 1)
	{
		cnt_tmp = ft_putstr_fd("0x", fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	if (flags->is_minus == 1)
	{
		cnt_tmp = print_zero_loop(flags->precision, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_flag_zero(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	if (flags->is_zero == 1 && flags->is_sharp == 1)
	{
		cnt_tmp = ft_putstr_fd("0x", fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	if (flags->is_zero == 1 && flags->precision != -1)
	{
		cnt_tmp = print_zero_loop(flags->min_width, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_flag_precision(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	if (flags->is_zero != 1 && flags->is_minus == 0)
	{
		cnt_tmp = print_space_loop(flags->min_width, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
		if (flags->is_sharp == 1)
		{
			cnt_tmp = ft_putstr_fd("0x", fd);
			if (cnt_tmp < 0)
				return (-1);
			count += cnt_tmp;
		}
		cnt_tmp = print_zero_loop(flags->precision, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_prefix_hex(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = print_flag_minus(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_precision(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
