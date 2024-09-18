/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:07:50 by katakada          #+#    #+#             */
/*   Updated: 2024/09/19 00:17:53 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define ISLINUX 1
#else
# define ISLINUX 0
#endif

int	print_char(int c, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = 0;
	flags->charactors = 1;
	set_char_print_conf(flags);
	if (flags->is_minus == 0)
	{
		if (ISLINUX == 1)
			count = print_loop(flags->min_width - 1, fd, ' ');
		if (ISLINUX == 0)
			count = print_loop(flags->min_width - 1, fd, '0');
	}
	if (count < 0)
		return (-1);
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	count++;
	if (flags->is_minus == 1)
		cnt_tmp = print_loop(flags->min_width - 1, fd, ' ');
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}

int	print_left_shift_str(t_flags *flags, int fd)
{
	int	count;

	count = 0;
	if (flags->is_zero == 1)
		count = print_loop(flags->min_width, fd, '0');
	else if (flags->is_minus == 0)
		count = print_loop(flags->min_width, fd, ' ');
	if (count < 0)
		return (-1);
	return (count);
}

int	print_str(char *str, t_flags *flags, int fd)
{
	int		count;
	int		cnt_tmp;
	char	*output_str;

	if (!str)
		str = "(null)";
	set_str_print_conf(flags, str);
	count = print_left_shift_str(flags, fd);
	if (count < 0)
		return (-1);
	output_str = ft_substr(str, 0, flags->charactors);
	if (!output_str)
		return (-1);
	cnt_tmp = ft_putstr_fd(output_str, fd);
	free(output_str);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = 0;
	if (flags->is_minus == 1)
		cnt_tmp = print_loop(flags->min_width, fd, ' ');
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}

int	print_ptr(unsigned long long ptr, t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = 0;
	set_ptr_print_conf(flags, (unsigned long long)ptr);
	if (flags->is_minus == 0)
		cnt_tmp = print_loop(flags->min_width, fd, ' ');
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	cnt_tmp = ft_putnbr_base_p((unsigned long long)ptr, HEX_LOWER, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	if (flags->is_minus == 1)
	{
		cnt_tmp = print_loop(flags->min_width, fd, ' ');
		if (cnt_tmp < 0)
			return (-1);
		count += cnt_tmp;
	}
	return (count);
}

int	print_percent(t_flags *flags, int fd)
{
	int	count;
	int	cnt_tmp;

	count = 0;
	cnt_tmp = 0;
	flags->charactors = 1;
	set_char_print_conf(flags);
	if (flags->is_zero == 1)
		count = print_loop(flags->min_width - 1, fd, '0');
	else if (flags->is_minus == 0)
		count = print_loop(flags->min_width - 1, fd, ' ');
	if (count < 0)
		return (-1);
	if (ft_putchar_fd('%', fd) < 0)
		return (-1);
	count++;
	if (flags->is_minus == 1)
		cnt_tmp = print_loop(flags->min_width - 1, fd, ' ');
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
