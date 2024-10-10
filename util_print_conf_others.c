/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_conf_others.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 17:53:52 by katakada          #+#    #+#             */
/*   Updated: 2024/10/10 18:48:47 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_char_print_conf(t_flags *flags)
{
	if (flags->blank_size <= flags->charactors && flags->precision != -1)
	{
		flags->blank_size = 0;
		return ;
	}
}

void	set_str_print_conf(t_flags *flags, char *str)
{
	flags->charactors = ft_strlen(str);
	if (flags->precision == -2 || flags->precision == -3)
		flags->charactors = 0;
	if (flags->charactors > flags->precision && flags->precision > 0)
		flags->charactors = flags->precision;
	if (flags->blank_size <= flags->charactors && flags->precision != -1)
	{
		flags->blank_size = 0;
		if (flags->precision == -1)
			flags->charactors = 0;
		return ;
	}
	if (flags->precision != -1)
		flags->blank_size = flags->blank_size - flags->charactors;
	if (flags->precision == -1)
		flags->charactors = 0;
}
