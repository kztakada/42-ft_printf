/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:21:01 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 20:53:00 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_core_int(int fd, t_flags *flags, long output_nbr)
{
	int	count;

	count = 0;
	if (flags->charactors != 0)
		count = ft_putnbr_fd(output_nbr, fd);
	if (count < 0)
		return (-1);
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
	cnt_tmp = print_suffix_nbr_str(flags, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
