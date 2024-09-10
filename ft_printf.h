/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:53 by katakada          #+#    #+#             */
/*   Updated: 2024/09/10 19:18:03 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

typedef struct s_flags
{
	int	zero;
	int	minus;
	int	width;
	int	precision;
	int	star;
	int	type;
}		t_flags;

int		ft_printf(const char *format, ...);
t_flags	ft_parse_format(const char *format, int *i);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long n);
int		ft_putnbr_base(unsigned long n, char *base);
int		ft_putnbr_base_p(uintptr_t n, char *base);
int		ft_putnbr_unsigned(unsigned long n);

#endif