/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:51:47 by rexposit          #+#    #+#             */
/*   Updated: 2024/09/30 21:07:09 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_cpy;
	unsigned char	c_cpy;
	size_t			i;

	i = 0;
	c_cpy = (unsigned char) c;
	s_cpy = (unsigned char *) s;
	while (i < n)
	{
		if (s_cpy[i] == c_cpy)
			return ((void *)&s_cpy[i]);
		i++;
	}
	return ((void *) 0);
}
