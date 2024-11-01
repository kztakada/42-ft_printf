# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:55:18 by katakada          #+#    #+#              #
#    Updated: 2024/11/01 17:35:33 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			print_format.c \
			print_format_funcs.c \
			print_format_setters.c \
			print_format_validator.c \
			print_format_validator_order.c \
			print_invalid_format.c \
			print_invalid_order_case.c \
			print_invalid_order_case_setters.c \
			print_invalid_order_case_printers.c \
			printer_char.c \
			printer_hex.c \
			printer_hex_prefix.c \
			printer_int.c \
			printer_percent.c \
			printer_ptr.c \
			printer_str.c \
			printer_u_int.c \
			printer_util_loop_print.c \
			printer_util_nbr_and_str_print.c \
			printer_util_number_print.c \
			util_func_putnbr.c \
			util_print_conf_func.c \
			util_print_conf_hex.c \
			util_print_conf_int.c \
			util_print_conf_int_func.c \
			util_print_conf_others.c \
			util_print_conf_ptr.c \
			util_print_conf_u_int.c \
			util_validator_flag.c \
			util_validator_format.c
			  
LIBFT	= ./libft/libft.a
OBJS	= $(SRCS:.c=.o)
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ./libft
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

bonus: all

clean:
	make fclean -C ./libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

norm :
	norminette -R CheckForbiddenSourceHeader $(SRCS)
	norminette -R CheckDefine *.h

.PHONY: all bonus clean fclean re norm