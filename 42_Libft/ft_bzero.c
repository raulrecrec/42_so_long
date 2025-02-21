/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:04:18 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/03 14:34:08 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*aux;
	size_t			len;

	aux = (unsigned char *) s;
	len = 0;
	while (len < n)
	{
		aux[len] = 0;
		len++;
	}
}
