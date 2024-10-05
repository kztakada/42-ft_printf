/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: katakada <katakada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:11:53 by katakada          #+#    #+#             */
/*   Updated: 2024/10/05 16:39:22 by katakada         ###   ########.fr       */
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
	int	blank_size;
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
int		print_prefix_int(t_flags *flags, int fd);
int		print_hex_base(unsigned int hex, t_flags *flags, char *base, int fd);
int		print_prefix_hex(t_flags *flags, int fd);
int		print_ptr(unsigned long long ptr, t_flags *flags, int fd);
int		print_percent(t_flags *flags, int fd);
int		print_zero_loop(int loop_times, int fd);
int		print_space_loop(int loop_times, int fd);

int		ft_putnbr_base(unsigned long n, char *base, int fd);
int		ft_putnbr_base_p(unsigned long long n, char *base, int fd);
int		ft_putnbr_unsigned(unsigned long n, int fd);

int		is_flag(int c);
int		is_field_digit(int c);
int		is_precision_dot(int c);
int		is_number_type(int c);
int		is_format_type(int c);

void	parse_flags(const char **format, t_flags *flags);
void	set_field_size(const char **format, t_flags *flags, va_list *args);
void	parse_precision(const char **format, t_flags *flags, va_list *args);
void	parse_format(const char **format, t_flags *flags);

void	set_char_print_conf(t_flags *flags);
void	set_str_print_conf(t_flags *flags, char *str);
void	set_ptr_print_conf(t_flags *flags, unsigned long long output_ptr);
void	set_int_print_conf(t_flags *flags, long *output_nbr);
void	set_hex_print_conf(t_flags *flags, unsigned int *output_hex,
			char *base);

long	get_abs(long n);

#endif