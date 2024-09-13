/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_setter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:20:28 by katakada          #+#    #+#             */
/*   Updated: 2024/09/13 23:20:59 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_char_space_conf(t_flags *flags)
{
	if (flags->min_width <= flags->charactors && flags->precision != -1)
	{
		flags->min_width = 0;
		return ;
	}
}

void	set_str_space_conf(t_flags *flags)
{
	if (flags->min_width <= flags->charactors && flags->precision != -1)
	{
		flags->min_width = 0;
		return ;
	}
	if (flags->precision != -1)
		flags->min_width = flags->min_width - flags->charactors;
}