/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:21:01 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 13:35:49 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_core_int(int fd, t_flags *flags, long output_nbr)
{
	int	count;
	int	cnt_tmp;

	cnt_tmp = 0;
	if (flags->charactors != 0)
		cnt_tmp = ft_putnbr_fd(output_nbr, fd);
	if (cnt_tmp < 0)
		return (-1);
	count = cnt_tmp;
	return (count);
}

int	print_suffix_int(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	if (flags->is_minus == 1)
	{
		cnt_tmp = print_space_loop(flags->blank_size, fd);
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
	output_nbr = (long)n;
	set_int_print_conf(flags, &output_nbr);
	cnt_tmp = print_prefix_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_core_int(fd, flags, output_nbr);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = print_suffix_int(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
