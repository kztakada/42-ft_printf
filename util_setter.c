/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:20:28 by katakada          #+#    #+#             */
/*   Updated: 2024/09/15 23:28:12 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	set_char_print_conf(t_flags *flags)
{
	if (flags->min_width <= flags->charactors && flags->precision != -1)
	{
		flags->min_width = 0;
		return ;
	}
}

void	set_str_print_conf(t_flags *flags, char *str)
{
	flags->charactors = ft_strlen(str);
	if (flags->precision == -2)
		flags->charactors = 0;
	if (flags->charactors > flags->precision && flags->precision > 0)
		flags->charactors = flags->precision;
	if (flags->min_width <= flags->charactors && flags->precision != -1)
	{
		flags->min_width = 0;
		if (flags->precision == -1)
			flags->charactors = 0;
		return ;
	}
	if (flags->precision != -1)
		flags->min_width = flags->min_width - flags->charactors;
	if (flags->precision == -1)
		flags->charactors = 0;
}

long	get_abs(long n)
{
	if (n < 0)
		return ((n * -1));
	return (n);
}

void	resolve_sign(t_flags *flags, long *output_nbr)
{
	flags->sign = 0;
	if (*output_nbr < 0)
		flags->sign = -1;
	if (flags->sign == 1 || flags->is_plus == 1)
		flags->sign = 1;
	if (*output_nbr < 0)
		*output_nbr = get_abs(*output_nbr);
}

void	set_nbr_digits(t_flags *flags, long output_nbr, char *base)
{
	int	nbr_of_base;

	nbr_of_base = ft_strlen(base);
	if (output_nbr >= nbr_of_base)
	{
		set_nbr_digits(flags, output_nbr / nbr_of_base, base);
		set_nbr_digits(flags, output_nbr % nbr_of_base, base);
	}
	else
		flags->charactors++;
}

void	resolve_min_width(t_flags *flags, long output_nbr)
{
	int	precision;
	int	is_not_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2);
	if (output_nbr == 0 && is_not_precision)
		return ;
	if (flags->precision > 0)
		precision = flags->precision;
	else
		precision = 0;
	if (precision <= flags->charactors)
		flags->min_width = flags->min_width - flags->charactors
			- get_abs(flags->sign) - flags->is_sharp;
	else
		flags->min_width = flags->min_width - precision - get_abs(flags->sign)
			- flags->is_sharp;
	if (flags->min_width <= 0)
		flags->min_width = 0;
}

void	resolve_precision(t_flags *flags)
{
	int	is_not_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2);
	if (is_not_precision)
		return ;
	if (flags->precision > flags->charactors)
		flags->precision = flags->precision - flags->charactors;
	else
		flags->precision = 0;
}

void	set_nbr_print_conf(t_flags *flags, long *output_nbr)
{
	int	is_not_precision;
	int	is_zero_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2);
	is_zero_precision = flags->precision == -2;
	if (*output_nbr == 0 && is_not_precision)
		flags->is_zero = 0;
	resolve_sign(flags, output_nbr);
	if (!(*output_nbr == 0 && is_not_precision))
		set_nbr_digits(flags, *output_nbr, DEC);
	if (*output_nbr == 0 && is_zero_precision)
		flags->charactors = 0;
	resolve_min_width(flags, *output_nbr);
	resolve_precision(flags);
}
