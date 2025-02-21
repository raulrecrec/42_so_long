/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:42:14 by rexposit          #+#    #+#             */
/*   Updated: 2024/09/30 21:06:59 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_size;
	void	*ptr;

	if (nmemb != 0 && size > __SIZE_MAX__ / nmemb)
		return (NULL);
	mem_size = nmemb * size;
	ptr = malloc(mem_size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, mem_size);
	return (ptr);
}
