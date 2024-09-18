/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_setters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:57:36 by katakada          #+#    #+#             */
/*   Updated: 2024/09/18 19:57:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
