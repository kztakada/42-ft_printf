# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: katakada <katakada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/31 15:55:18 by katakada          #+#    #+#              #
#    Updated: 2024/10/17 17:44:57 by katakada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(wildcard *.c)
SRCS := $(filter-out main.c, $(SRCS))
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