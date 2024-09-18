/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:07:50 by katakada          #+#    #+#             */
/*   Updated: 2024/09/18 20:08:46 by katakada         ###   ########.fr       */
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
	int	space_count;

	count = 0;
	space_count = 0;
	flags->charactors = 1;
	set_char_print_conf(flags);
	if (flags->is_minus == 0)
	{
		if (ISLINUX == 1)
			space_count = print_loop(flags->min_width - 1, fd, ' ');
		if (ISLINUX == 0)
			space_count = print_loop(flags->min_width - 1, fd, '0');
	}
	if (space_count < 0)
		return (-1);
	if (ft_putchar_fd(c, fd) < 0)
		return (-1);
	count++;
	if (flags->is_minus == 1)
		space_count = print_loop(flags->min_width - 1, fd, ' ');
	if (space_count < 0)
		return (-1);
	return (count + space_count);
}

int	print_str(char *str, t_flags *flags, int fd)
{
	int		count;
	int		space_count;
	char	*output_str;

	space_count = 0;
	if (!str)
		str = "(null)";
	set_str_print_conf(flags, str);
	if (flags->is_minus == 0)
		space_count = print_loop(flags->min_width, fd, ' ');
	if (space_count < 0)
		return (-1);
	output_str = ft_substr(str, 0, flags->charactors);
	if (!output_str)
		return (-1);
	count = ft_putstr_fd(output_str, fd);
	free(output_str);
	if (count < 0)
		return (-1);
	if (flags->is_minus == 1)
		space_count = print_loop(flags->min_width, fd, ' ');
	if (space_count < 0)
		return (-1);
	return (count + space_count);
}
