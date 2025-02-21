# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 14:30:09 by rexposit          #+#    #+#              #
#    Updated: 2024/10/24 14:30:11 by rexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

RM		= rm -f

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

SRCS	=					\
		ft_printf.c 		\
		ft_format.c			\
		ft_numlen.c			\
		ft_putlnbr.c		\
		ft_putlstr.c		\
		ft_putlchar.c		\
		ft_putlnbr_base.c	\
		
OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean all fclean re