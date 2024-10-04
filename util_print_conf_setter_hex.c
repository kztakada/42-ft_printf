/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_setter_hex.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:02:14 by katakada          #+#    #+#             */
/*   Updated: 2024/10/04 20:28:28 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_hexlen_base(unsigned int output_hex, char *base, t_flags *flags)
{
	unsigned int	nbr_of_base;

	nbr_of_base = ft_strlen(base);
	if (output_hex >= nbr_of_base)
	{
		set_hexlen_base(output_hex / nbr_of_base, base, flags);
		set_hexlen_base(output_hex % nbr_of_base, base, flags);
	}
	else
		flags->charactors++;
}

void	set_min_width(t_flags *flags)
{
	int	precision;

	if (flags->precision > 0)
		precision = flags->precision;
	else
		precision = 0;
	if (precision <= flags->charactors)
		flags->min_width = flags->min_width - flags->charactors
			- flags->is_sharp;
	else
		flags->min_width = flags->min_width - precision - flags->is_sharp;
	if (flags->min_width <= 0)
		flags->min_width = 0;
}

void	set_precision(t_flags *flags)
{
	if (flags->precision > flags->charactors)
		flags->precision = flags->precision - flags->charactors;
	else
		flags->precision = 0;
}

void	set_hex_print_conf(t_flags *flags, unsigned int *output_hex, char *base)
{
	int	is_not_precision;
	int	is_zero_precision;

	is_not_precision = (flags->precision == -1 || flags->precision == -2);
	is_zero_precision = flags->precision == -2;
	if (*output_hex == 0 && is_not_precision)
		flags->is_zero = 0;
	set_hexlen_base(*output_hex, base, flags);
	if (!(output_hex == 0 && is_zero_precision))
		set_min_width(flags);
	if (!(is_not_precision))
		set_precision(flags);
	if (*output_hex == 0)
		flags->is_sharp = 0;
}
