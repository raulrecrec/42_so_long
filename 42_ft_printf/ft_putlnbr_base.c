/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:36:50 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/24 13:56:05 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putlnbr_base_xxu(unsigned int nbr, char *base, int print_crs)
{
	int			leng_base;
	long long	nbr_cpy;
	char		aux;

	nbr_cpy = (long long) nbr;
	leng_base = 0;
	while (base[leng_base] != '\0')
		leng_base++;
	if (nbr_cpy >= leng_base)
		print_crs = ft_putlnbr_base_xxu(nbr_cpy / leng_base, base, print_crs);
	aux = base[nbr_cpy % leng_base];
	print_crs++;
	write(1, &aux, 1);
	return (print_crs);
}

int	ft_putlnbr_base_p(unsigned long long nbr, char *base, int print_crs)
{
	int		leng_base;
	char	aux;

	leng_base = 0;
	while (base[leng_base] != '\0')
		leng_base++;
	if (nbr >= (unsigned long long) leng_base)
		print_crs = ft_putlnbr_base_p(nbr / leng_base, base, print_crs);
	aux = base[nbr % leng_base];
	print_crs++;
	write(1, &aux, 1);
	return (print_crs);
}

int	ft_putlnbr_base_xup(const char c, long long nbr)
{
	int	print_crs;

	print_crs = 0;
	if (c == 'x')
		print_crs = ft_putlnbr_base_xxu(nbr, "0123456789abcdef", print_crs);
	else if (c == 'X')
		print_crs = ft_putlnbr_base_xxu(nbr, "0123456789ABCDEF", print_crs);
	else if (c == 'u')
		print_crs = ft_putlnbr_base_xxu(nbr, "0123456789", print_crs);
	else if (c == 'p')
	{
		if (nbr == 0)
			print_crs = write(1, "(nil)", 5);
		else
		{
			print_crs = write(1, "0x", 2);
			print_crs = ft_putlnbr_base_p(nbr, "0123456789abcdef", print_crs);
		}
	}
	return (print_crs);
}
