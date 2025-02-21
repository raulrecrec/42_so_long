/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:51:58 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/10 15:39:18 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	n_cpy;
	long long	divider;
	char		char_n;

	n_cpy = (long long) n;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n_cpy < 0)
	{
		write(fd, "-", 1);
		n_cpy = n_cpy * -1;
	}
	divider = 1;
	while ((n_cpy / divider) >= 10)
		divider = divider * 10;
	while (divider >= 1)
	{
		char_n = (n_cpy / divider) + '0';
		write(fd, &char_n, 1);
		n_cpy = n_cpy % divider;
		divider = divider / 10;
	}
}
