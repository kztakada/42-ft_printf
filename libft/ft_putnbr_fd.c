/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:51:50 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 17:39:51 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	long	number;
	int		count;

	number = (long)n;
	count = 0;
	if (number < 0)
	{
		count += ft_putchar_fd('-', fd);
		number *= -1;
	}
	if (number >= 10)
		count += ft_putnbr_fd((number / 10), fd);
	count += ft_putchar_fd((number % 10 + '0'), fd);
	return (count);
}
