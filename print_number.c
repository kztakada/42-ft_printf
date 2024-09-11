/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:04:58 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 17:45:36 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base, int fd)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += ft_putnbr_base(n / 16, base, fd);
		count += ft_putchar_fd(base[n % 16], fd);
	}
	else
		count += ft_putchar_fd(base[n], fd);
	return (count);
}

int	ft_putnbr_unsigned(unsigned long n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
	{
		count += ft_putnbr_fd((n / 10), fd);
		count += ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
		count += ft_putchar_fd((n + '0'), fd);
	return (count);
}
