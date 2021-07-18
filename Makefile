# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdude <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 11:41:14 by mdude             #+#    #+#              #
#    Updated: 2020/12/09 14:33:23 by mdude            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERS = libft.h

SRC = format_c.c \
	  format_di.c \
	  format_p.c \
	  format_prec.c \
	  format_s.c \
	  format_u.c \
	  format_x.c \
	  format_xx.c \
	  ft_atoi.c \
	  ft_dot.c \
	  ft_isdigit.c \
	  ft_itoa.c \
	  ft_itoa_base.c \
	  ft_itoa_uns.c \
	  ft_minus.c \
	  ft_printf.c \
	  ft_putchar.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_strlen.c \
	  ft_toupper.c \
	  ft_zero.c \
	  init_sflags.c \
	  init_string.c \
	  intlen.c \
	  is_flag.c \
	  is_percent.c \
	  is_specify.c \
	  ft_zero_int.c \
	  ft_dot_int.c \
	  flags_null.c \
	  check_spec.c

OSRC = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@

$(NAME): $(OSRC) $(HEADERS)
	ar rcs $(NAME) $(OSRC)

all: $(NAME)

clean:
	rm -f $(OSRC)

fclean: clean
	rm -f $(NAME)

re: fclean all
