# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:55:18 by katakada          #+#    #+#              #
#    Updated: 2024/09/11 23:47:31 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c print_number.c print_pointer.c output_format.c validator.c
LIBFT = ./libft/libft.a
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C ./libft
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

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

.PHONY: all clean fclean re