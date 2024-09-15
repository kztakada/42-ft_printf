/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 00:17:11 by katakada          #+#    #+#             */
/*   Updated: 2024/09/16 00:17:22 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_loop(int loop_times, int fd, int c)
{
	int	count;

	count = 0;
	while (loop_times-- > 0)
	{
		if (ft_putchar_fd(c, fd) < 0)
			return (-1);
		count++;
	}
	return (count);
}
