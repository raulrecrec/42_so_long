/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 12:34:25 by rexposit          #+#    #+#             */
/*   Updated: 2024/09/30 21:08:06 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	x;
	size_t	y;

	x = 0;
	if (little[0] == '\0')
		return ((char *) big);
	while (x < len && big[x] != '\0')
	{
		y = 0;
		while (x + y < len && big[x + y] == little[y] && little[y] != '\0')
			y++;
		if (little[y] == '\0')
			return ((char *) big + x);
		x++;
	}
	return ((char *) 0);
}
