/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:53 by katakada          #+#    #+#             */
/*   Updated: 2024/09/11 20:09:24 by katakada         ###   ########.fr       */
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
int		output_format(const char **format, t_flags *flags, va_list *args,
			int fd);
t_flags	ft_parse_format(const char **format);
int		ft_putnbr_base(unsigned long n, char *base, int fd);
int		ft_putnbr_base_p(uintptr_t n, char *base, int fd);
int		ft_putnbr_unsigned(unsigned long n, int fd);

#endif