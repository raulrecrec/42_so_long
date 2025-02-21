/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 19:07:09 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/24 11:33:31 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(const char c, va_list value)
{
	int	print_chars;

	print_chars = 0;
	if (c == 'c')
		print_chars = ft_putlchar(va_arg(value, int));
	else if (c == 's')
		print_chars = ft_putlstr(va_arg(value, char *));
	else if (c == 'd' || c == 'i')
		print_chars = ft_putlnbr(va_arg(value, int));
	else if (c == 'x' || c == 'X')
		print_chars = ft_putlnbr_base_xup(c, va_arg(value, unsigned long long));
	else if (c == 'u')
		print_chars = ft_putlnbr_base_xup(c, va_arg(value, unsigned int));
	else if (c == '%')
		print_chars = ft_putlchar('%');
	else if (c == 'p')
		print_chars = ft_putlnbr_base_xup(c, va_arg(value, long long));
	return (print_chars);
}
