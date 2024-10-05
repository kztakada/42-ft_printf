/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 00:33:23 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 13:35:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_prefix_ptr(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_minus == 0)
		count = print_space_loop(flags->blank_size, fd);
	if (count < 0)
		return (-1);
	return (count);
}

int	print_suffix_ptr(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_minus == 1)
	{
		count = print_space_loop(flags->blank_size, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_ptr(unsigned long long ptr, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	set_ptr_print_conf(flags, (unsigned long long)ptr);
	count = print_prefix_ptr(flags, fd);
	if (count < 0)
		return (-1);
	cnt_tmp = ft_putnbr_base_p((unsigned long long)ptr, HEX_LOWER, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_ptr(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
