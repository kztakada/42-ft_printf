/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_setter_int.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:52:00 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 13:39:03 by katakada         ###   ########.fr       */
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

void	set_blank_size(t_flags *flags, long output_nbr)
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
		flags->blank_size = flags->blank_size - flags->charactors
			- get_abs(flags->sign) - flags->is_sharp;
	else
		flags->blank_size = flags->blank_size - precision - get_abs(flags->sign)
			- flags->is_sharp;
	if (flags->blank_size <= 0)
		flags->blank_size = 0;
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
	set_blank_size(flags, *output_nbr);
	resolve_precision(flags);
}
