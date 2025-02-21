/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:56:48 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/10 15:37:01 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*allocate_str_mem(long long num)
{
	size_t	i;

	i = 0;
	if (num < 0)
	{
		num = num * -1;
		i++;
	}
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (malloc((i + 1) * sizeof(char)));
}

char	*num_reverse(char *n_str, size_t len)
{
	size_t	start;
	size_t	end;
	char	aux;

	if (n_str[0] == '-')
		start = 1;
	else
		start = 0;
	end = len - 1;
	while (start < end)
	{
		aux = n_str[start];
		n_str[start] = n_str[end];
		n_str[end] = aux;
		start++;
		end--;
	}
	return (n_str);
}

char	*num_cpy(char *n_str, long long num, size_t i)
{
	while (num > 0)
	{
		n_str[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	n_str[i] = '\0';
	n_str = num_reverse(n_str, ft_strlen(n_str));
	return (n_str);
}

char	*ft_itoa(int n)
{
	size_t		i;
	char		*n_str;
	long long	num;

	num = (long long) n;
	if (n == 0)
		return (ft_strdup("0"));
	n_str = allocate_str_mem(num);
	if (n_str == NULL)
		return (NULL);
	i = 0;
	if (num < 0)
	{
		n_str[i] = '-';
		num = num * -1;
		i++;
	}
	n_str = num_cpy(n_str, num, i);
	return (n_str);
}
