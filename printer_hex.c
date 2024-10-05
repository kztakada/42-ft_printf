/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 18:56:41 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 19:09:25 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_suffix_hex(t_flags *flags, int fd)
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

int	print_core_hex(unsigned int output_hex, t_flags *flags, char *base, int fd)
{
	int	count;

	count = 0;
	if (!((flags->precision == -2 && output_hex == 0) || (flags->precision == -1
				&& output_hex == 0)))
	{
		count = ft_putnbr_hex_base(output_hex, base, fd);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	print_hex_base(unsigned int output_hex, t_flags *flags, char *base, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	set_hex_print_conf(flags, output_hex, base);
	cnt_tmp = print_prefix_hex(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_core_hex(output_hex, flags, base, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_hex(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
