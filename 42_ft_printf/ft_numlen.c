/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 18:12:15 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/21 18:37:11 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlen(int c)
{
	size_t	num_len;

	num_len = 0;
	if (c <= 0)
		num_len++;
	while (c != 0)
	{
		c = c / 10;
		num_len++;
	}
	return (num_len);
}
