/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_ptr_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 20:07:23 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 20:09:08 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_blank_ptr(t_flags *flags, int fd)
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

int	print_flag_zero_ptr(t_flags *flags, int fd)
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

int	print_0x_ptr(unsigned long long ptr, int fd)
{
	int	count;

	count = 0;
	if (ptr || ISLINUX == 0)
	{
		count += ft_putstr_fd("0x", fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_prefix_ptr(unsigned long long ptr, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = print_blank_ptr(flags, fd);
	if (count < 0)
		return (-1);
	cnt_tmp = print_0x_ptr(ptr, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_flag_zero_ptr(flags, fd);
	if (count < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
