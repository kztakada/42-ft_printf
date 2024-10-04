/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:37:06 by katakada          #+#    #+#             */
/*   Updated: 2024/10/04 23:52:48 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_blank_space_int(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = 0;
	if (flags->is_minus == 0 && flags->is_zero != 1)
	{
		cnt_tmp = print_space_loop(flags->min_width, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_sign_int(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->sign == -1)
		count += ft_putchar_fd('-', fd);
	else if (flags->is_plus == 1)
		count += ft_putchar_fd('+', fd);
	else if (flags->is_space == 1)
		count += ft_putchar_fd(' ', fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	print_flag_zero_int(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = 0;
	if (flags->is_zero == 1)
	{
		if (flags->precision != -1)
			cnt_tmp = print_zero_loop(flags->min_width, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	if ((flags->is_zero != 1 && flags->is_minus == 0) || flags->is_minus == 1)
	{
		cnt_tmp = print_zero_loop(flags->precision, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_prefix_int(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = print_blank_space_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_sign_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
