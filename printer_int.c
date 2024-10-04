/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:21:01 by katakada          #+#    #+#             */
/*   Updated: 2024/10/04 17:32:16 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_sign(t_flags *flags, int fd)
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

int	print_left_shift_int(int fd, t_flags *flags)
{
	int	count;
	int	cnt_tmp;

	cnt_tmp = 0;
	cnt_tmp = print_sign(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count = cnt_tmp;
	if (flags->is_minus == 1)
	{
		cnt_tmp = print_zero_loop(flags->precision, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	if (flags->is_zero == 1)
	{
		if (flags->precision != -1)
			cnt_tmp = print_zero_loop(flags->min_width, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_right_shift_int(int fd, t_flags *flags)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = 0;
	if (flags->is_minus == 0)
	{
		if (flags->is_zero != 1)
		{
			cnt_tmp = print_space_loop(flags->min_width, fd);
			if (cnt_tmp < 0)
				return (-1);
			count += cnt_tmp;
			cnt_tmp = print_sign(flags, fd);
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

int	print_nbr(int fd, t_flags *flags, long output_nbr)
{
	int	count;
	int	cnt_tmp;

	cnt_tmp = 0;
	if (flags->charactors != 0)
		cnt_tmp = ft_putnbr_fd(output_nbr, fd);
	if (cnt_tmp < 0)
		return (-1);
	count = cnt_tmp;
	if (flags->is_minus == 1)
	{
		cnt_tmp = print_space_loop(flags->min_width, fd);
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_int(int n, t_flags *flags, int fd)
{
	int		count;
	int		cnt_tmp;
	long	output_nbr;

	count = 0;
	cnt_tmp = 0;
	output_nbr = (long)n;
	set_int_print_conf(flags, &output_nbr);
	if (flags->is_minus == 1 || flags->is_zero == 1)
		cnt_tmp = print_left_shift_int(fd, flags);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_right_shift_int(fd, flags);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_nbr(fd, flags, output_nbr);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
