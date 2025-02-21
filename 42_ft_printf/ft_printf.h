/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:08:58 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/23 14:20:37 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_format(const char c, va_list value);
int		ft_numlen(int c);
int		ft_putlnbr(int n);
int		ft_putlstr(char *s);
int		ft_putlchar(char c);
int		ft_putlnbr_base_xup(const char c, long long nbr);

#endif