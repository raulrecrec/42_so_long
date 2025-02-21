/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:24:23 by rexposit          #+#    #+#             */
/*   Updated: 2024/09/30 21:07:50 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	x;
	size_t	leng_dest;
	size_t	leng_src;

	x = 0;
	leng_dest = 0;
	leng_src = 0;
	while (dst[leng_dest] != '\0' && leng_dest < size)
		leng_dest++;
	while (src[leng_src] != '\0')
		leng_src++;
	if (size <= leng_dest)
		return (size + leng_src);
	while (src[x] != '\0' && leng_dest + x < size - 1)
	{
		dst[leng_dest + x] = src[x];
		x++;
	}
	if ((leng_dest + x) < size)
		dst[leng_dest + x] = '\0';
	return (leng_dest + leng_src);
}
