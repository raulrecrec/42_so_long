/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 13:39:25 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/08 13:52:53 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strcmp_forward(char const *s1, char const *set)
{
	size_t			i;
	size_t			j;
	size_t			x;
	unsigned int	found;

	i = 0;
	x = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		found = 0;
		while (set[j] != '\0' && found == 0)
		{
			if (s1[i] == set[j])
			{
				x++;
				found = 1;
			}
			j++;
		}
		if (found != 1)
			break ;
		i++;
	}
	return (x);
}

int	strcmp_reverse(char const *s1, char const *set)
{
	size_t			i;
	size_t			j;
	size_t			x;
	unsigned int	found;

	i = ft_strlen(s1) - 1;
	x = 0;
	while (i > 0)
	{
		j = 0;
		found = 0;
		while (set[j] != '\0' && found == 0)
		{
			if (s1[i] == set[j])
			{
				x++;
				found = 1;
			}
			j++;
		}
		if (found != 1)
			break ;
		i--;
	}
	return (x);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_left;
	size_t	str_right;
	size_t	i;
	size_t	len_s1_trim;
	char	*s1_trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	str_left = strcmp_forward(s1, set);
	str_right = strcmp_reverse(s1, set);
	if (str_left >= (size_t) ft_strlen(s1))
		return (ft_strdup(""));
	len_s1_trim = ft_strlen(s1) - str_left - str_right;
	s1_trim = malloc(len_s1_trim + 1);
	if (s1_trim == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1_trim)
	{
		s1_trim[i] = s1[str_left];
		i++;
		str_left++;
	}
	s1_trim[i] = '\0';
	return (s1_trim);
}
