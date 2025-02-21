/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 17:49:59 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/21 18:38:08 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	long long	n_cpy;
	long long	divider;
	char		char_n;

	n_cpy = (long long) n;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n_cpy < 0)
	{
		write(1, "-", 1);
		n_cpy = n_cpy * -1;
	}
	divider = 1;
	while ((n_cpy / divider) >= 10)
		divider = divider * 10;
	while (divider >= 1)
	{
		char_n = (n_cpy / divider) + '0';
		write(1, &char_n, 1);
		n_cpy = n_cpy % divider;
		divider = divider / 10;
	}
}

int	ft_putlnbr(int n)
{
	ft_putnbr(n);
	return (ft_numlen(n));
}
