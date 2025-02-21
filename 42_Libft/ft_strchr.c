/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:05:24 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/03 18:38:58 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	c_cpy;

	i = 0;
	c_cpy = (char) c;
	while (s[i] != '\0')
	{
		if (s[i] == c_cpy)
			return ((char *)&s[i]);
		i++;
	}
	if (c_cpy == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
