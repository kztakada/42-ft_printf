/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_validators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:31:45 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 18:06:24 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_format_flag(int c)
{
	return (c == '0' || c == '-' || c == '#' || c == ' ' || c == '+');
}

int	is_field_digit(int c)
{
	return (ft_isdigit(c) || c == '*');
}

int	is_precision_dot(int c)
{
	return (c == '.');
}

int	is_number_type(int c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X');
}

int	is_format_type(int c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == '%' || is_number_type(c));
}
