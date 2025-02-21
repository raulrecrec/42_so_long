/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:43:00 by rexposit          #+#    #+#             */
/*   Updated: 2024/10/14 15:00:54 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**allocate_array_memory(char const *s, char c, char **str_split)
{
	size_t	i;
	size_t	str_num;

	str_num = 0;
	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			str_num++;
		i++;
	}
	str_split = malloc((str_num + 1) * sizeof(char *));
	if (str_split == NULL)
		return (NULL);
	str_split[str_num] = NULL;
	return (str_split);
}

char	*allocate_str_memory(size_t str_start, size_t str_end)
{
	size_t	str_len;
	char	*sub_str;

	str_len = str_end - str_start + 1;
	sub_str = malloc((str_len + 1) * sizeof(char));
	if (sub_str == NULL)
		return (NULL);
	return (sub_str);
}

char	**str_split_allocate(char const *s, char c, char **str_split, size_t i)
{
	size_t	j;
	size_t	str_start;

	while (s[i] != '\0' && s[i] == c)
		i++;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			str_start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			str_split[j] = allocate_str_memory(str_start, i);
			if (str_split[j] == NULL)
			{
				while (j-- > 0)
					free(str_split[j]);
				free(str_split);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (str_split);
}

char	**str_cpy(char const *s, char c, char **str_split)
{
	size_t	i;
	size_t	j;
	size_t	str_start;
	size_t	str_len;

	i = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			str_start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			str_len = i - str_start + 1;
			ft_strlcpy(str_split[j], &s[str_start], str_len + 1);
			j++;
		}
		i++;
	}
	return (str_split);
}

char	**ft_split(char const *s, char c)
{
	char	**str_split;

	str_split = allocate_array_memory(s, c, 0);
	if (str_split == NULL)
		return (NULL);
	str_split = str_split_allocate(s, c, str_split, 0);
	if (str_split == NULL)
		return (NULL);
	str_split = str_cpy(s, c, str_split);
	if (str_split == NULL)
		return (NULL);
	return (str_split);
}
