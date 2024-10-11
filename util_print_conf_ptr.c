/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_ptr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:52:38 by katakada          #+#    #+#             */
/*   Updated: 2024/10/11 16:34:09 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_ptr_digits(t_flags *flags, unsigned long long output_ptr,
		char *base)
{
	unsigned long long	ptr_of_base;

	ptr_of_base = ft_strlen(base);
	if (output_ptr >= ptr_of_base)
	{
		set_ptr_digits(flags, output_ptr / ptr_of_base, base);
		set_ptr_digits(flags, output_ptr % ptr_of_base, base);
	}
	else
		flags->charactors++;
}

void	set_blank_size_ptr(t_flags *flags, unsigned long long output_ptr)
{
	int	precision;
	int	sign_0x;

	sign_0x = 2;
	if (flags->precision == -3 && !output_ptr)
	{
		flags->blank_size = flags->blank_size - sign_0x;
		return ;
	}
	if (flags->precision > 0)
		precision = flags->precision;
	else
		precision = 0;
	if (precision <= flags->charactors)
		flags->blank_size = flags->blank_size - flags->charactors - sign_0x;
	else
		flags->blank_size = flags->blank_size - precision - sign_0x;
	if (flags->blank_size <= 0)
		flags->blank_size = 0;
}

void	set_ptr_print_conf(t_flags *flags, unsigned long long output_ptr)
{
	int	is_not_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2
			|| flags->precision == -3);
	set_print_conf_counted_digits(flags, output_ptr, HEX_LOWER);
	set_blank_size_ptr(flags, output_ptr);
	if (!(is_not_precision))
		set_print_conf_precision(flags);
}
