/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:28:40 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/07 12:51:44 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				x;
	const unsigned char	*s1_cpy;
	const unsigned char	*s2_cpy;

	x = 0;
	s1_cpy = (const unsigned char *) s1;
	s2_cpy = (const unsigned char *) s2;
	if (n == 0)
		return (0);
	while (x < n && s1_cpy[x] == s2_cpy[x]
		&& s1_cpy[x] != '\0' && s2_cpy[x] != '\0')
		x++;
	if (x == n)
		return (0);
	return (s1_cpy[x] - s2_cpy[x]);
}
