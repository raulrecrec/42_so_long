/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:27:41 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/07 15:42:50 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;
	size_t			i;

	if (dest == NULL && src == NULL)
		return (NULL);
	src_cpy = (unsigned char *) src;
	dest_cpy = (unsigned char *) dest;
	i = 0;
	if (dest_cpy < src_cpy)
	{
		while (i < n)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			dest_cpy[n] = src_cpy[n];
	}
	return (dest);
}
