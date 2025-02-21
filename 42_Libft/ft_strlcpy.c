/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:51:53 by rexposit          #+#    #+#             */
/*   Updated: 2024/09/30 21:07:56 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (src[y] != '\0')
		y++;
	if (size > 0)
	{
		while (src[x] != '\0' && x < size - 1)
		{
			dst[x] = src[x];
			x++;
		}
		dst[x] = '\0';
	}
	return (y);
}
