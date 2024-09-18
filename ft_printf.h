/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:53 by katakada          #+#    #+#             */
/*   Updated: 2024/09/18 21:30:52 by katakada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# define DEC "0123456789"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

typedef struct s_flags
{
	int	is_minus;
	int	is_zero;
	int	is_sharp;
	int	is_space;
	int	is_plus;
	int	min_width;
	int	precision;
	int	charactors;
	int	sign;
	int	type;
}		t_flags;

int		ft_printf(const char *format, ...);
int		print_format(const char **format, t_flags *flags, va_list *args,
			int fd);

int		print_char(int c, t_flags *flags, int fd);
int		print_str(char *str, t_flags *flags, int fd);
int		print_int(int n, t_flags *flags, int fd);
int		print_loop(int loop_times, int fd, int c);

int		ft_putnbr_base(unsigned long n, char *base, int fd);
int		ft_putnbr_base_p(unsigned long long n, char *base, int fd);
int		ft_putnbr_unsigned(unsigned long n, int fd);

int		is_flag(int c);
int		is_width_digit(int c);
int		is_precision_dot(int c);
int		is_number_type(int c);
int		is_format_type(int c);

void	parse_flags(const char **format, t_flags *flags);
void	parse_width(const char **format, t_flags *flags, va_list *args);
void	parse_precision(const char **format, t_flags *flags, va_list *args);
void	parse_format(const char **format, t_flags *flags);

void	set_char_print_conf(t_flags *flags);
void	set_str_print_conf(t_flags *flags, char *str);
void	set_ptr_print_conf(t_flags *flags, unsigned long long output_ptr);
void	set_int_print_conf(t_flags *flags, long *output_nbr);

long	get_abs(long n);

#endif