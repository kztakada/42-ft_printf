/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_setter_int.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:52:00 by katakada          #+#    #+#             */
/*   Updated: 2024/09/18 19:54:45 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	set_int_print_conf(t_flags *flags, long *output_nbr)
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
