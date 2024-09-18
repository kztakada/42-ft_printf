/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:07:36 by katakada          #+#    #+#             */
/*   Updated: 2024/09/18 21:17:23 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define NIL "(nil)"
#else
# define NIL "0x0"
#endif

int	ft_putnbr_base_p(unsigned long long n, char *base, int fd)
{
	int	count;
	int	cnt_tmp;

	if (n == 0)
	{
		count = ft_putstr_fd(NIL, fd);
		if (count < 0)
			return (-1);
		return (count);
	}
	count = 0;
	count += ft_putstr_fd("0x", fd);
	if (count < 0)
		return (-1);
	cnt_tmp = ft_putnbr_base(n, base, fd);
	if (cnt_tmp < 0)
		return (-1);
	count += cnt_tmp;
	return (count);
}
