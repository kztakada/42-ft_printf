/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:31:45 by katakada          #+#    #+#             */
/*   Updated: 2024/09/12 00:23:29 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(int c)
{
	return (c == '0' || c == '-' || c == '#' || c == ' ' || c == '+');
}

int	is_width_digit(int c)
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
