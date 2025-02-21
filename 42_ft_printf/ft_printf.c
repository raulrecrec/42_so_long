/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:59:25 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/21 18:37:30 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	aargs;
	int		printed_chars;
	size_t	i;

	va_start(aargs, format);
	i = 0;
	printed_chars = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			printed_chars += ft_format(format[++i], aargs);
		else
			printed_chars += ft_putlchar(format[i]);
		i++;
	}
	va_end(aargs);
	return (printed_chars);
}
