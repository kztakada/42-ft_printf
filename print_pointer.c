/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:07:36 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 17:49:50 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#ifdef __linux__
# define NIL "(nil)"
#else
# define NIL "0x0"
#endif

int	ft_putnbr_base_p(uintptr_t n, char *base, int fd)
{
	int	count;

	if (n == 0)
		return (ft_putstr_fd(NIL, fd));
	count = 0;
	count += ft_putstr_fd("0x", fd);
	count += ft_putnbr_base(n, base, fd);
	return (count);
}
