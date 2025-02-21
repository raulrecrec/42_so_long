# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 13:52:09 by rexposit          #+#    #+#              #
#    Updated: 2025/02/21 22:29:36 by rexposit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del ejecutable
NAME 	= so_long

# Compilador y flags
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -I./minilibx-linux -I./42_ft_printf -I./42_get_next_line -I./42_libft

# Librerías necesarias para MiniLibX en Linux
MLX 	= -L./minilibx-linux -lmlx -lXext -lX11

# Archivos fuente de so_long
SRCS 	= so_long.c \
		  map.c \
		  render_and_clean.c \

# Archivos fuente de get_next_line
GNL_SRCS = 42_get_next_line/get_next_line.c \
		   42_get_next_line/get_next_line_utils.c

# Archivos fuente de ft_printf
PRINTF_SRCS = 42_ft_printf/ft_printf.c \
			  42_ft_printf/ft_putlchar.c \
			  42_ft_printf/ft_putlstr.c \
			  42_ft_printf/ft_putlnbr.c \
			  42_ft_printf/ft_putlnbr_base.c \
			  42_ft_printf/ft_numlen.c \
			  42_ft_printf/ft_format.c

# Archivos fuente de libft
LIBFT_DIR = 42_Libft
LIBFT = $(LIBFT_DIR)/libft.a

# Convertimos los archivos .c en .o
OBJS	= $(SRCS:.c=.o)
GNL_OBJS = $(GNL_SRCS:.c=.o)
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

# Regla principal (compila el ejecutable)
all: $(LIBFT) $(NAME)

# Compilar la libft
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Compilar so_long
$(NAME): $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS) $(MLX) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "✅ Compilación completada: $(NAME)"

# Regla para compilar archivos de ft_printf
42_ft_printf/%.o: 42_ft_printf/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔹 Compilado: $<"

# Regla para compilar archivos de get_next_line
42_get_next_line/%.o: 42_get_next_line/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔹 Compilado: $<"

# Regla para compilar archivos .c en .o de so_long
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "🔹 Compilado: $<"

# Eliminar archivos .o
clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS) $(GNL_OBJS) $(PRINTF_OBJS)
	@echo "🗑 Archivos objeto eliminados."

# Eliminar el ejecutable y los archivos objeto
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "🗑 Ejecutable eliminado."

# Recompilar desde cero
re: fclean all