/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:21:59 by rexposit          #+#    #+#             */
/*   Updated: 2024/11/13 13:20:21 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line_and_update(char **fd_unread)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	if (!*fd_unread)
		return (NULL);
	newline_pos = ft_strchr(*fd_unread, '\n');
	if (newline_pos)
		line = ft_substr(*fd_unread, 0, newline_pos - *fd_unread + 1);
	else
		line = ft_substr(*fd_unread, 0, ft_strlen(*fd_unread));
	if (line && ft_strlen(line) < ft_strlen(*fd_unread))
	{
		temp = *fd_unread;
		*fd_unread = ft_substr(*fd_unread, ft_strlen(line),
				ft_strlen(*fd_unread) - ft_strlen(line));
		free(temp);
	}
	else
	{
		free(*fd_unread);
		*fd_unread = NULL;
	}
	return (line);
}

static char	*read_and_append(int fd, char *fd_unread, char *fd_read)
{
	ssize_t	byts_rd;
	char	*temp;

	byts_rd = read(fd, fd_read, BUFFER_SIZE);
	if (byts_rd < 0)
	{
		free(fd_read);
		free(fd_unread);
		return (NULL);
	}
	fd_read[byts_rd] = '\0';
	if (!fd_unread)
		fd_unread = ft_substr(fd_read, 0, ft_strlen(fd_read));
	else
	{
		temp = fd_unread;
		fd_unread = ft_strjoin(fd_unread, fd_read);
		free(temp);
	}
	return (fd_unread);
}

static char	*read_until_line(int fd, char *fd_unread, char *fd_read)
{
	while (1)
	{
		fd_unread = read_and_append(fd, fd_unread, fd_read);
		if (!fd_unread)
			return (NULL);
		if (fd_read[0] == '\0')
			break ;
		if (ft_strchr(fd_unread, '\n'))
			break ;
	}
	free(fd_read);
	return (fd_unread);
}

char	*get_next_line(int fd)
{
	static char	*fd_unread;
	char		*fd_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fd_read = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!fd_read)
		return (NULL);
	fd_unread = read_until_line(fd, fd_unread, fd_read);
	if (!fd_unread || fd_unread[0] == '\0')
	{
		free(fd_unread);
		fd_unread = NULL;
		return (NULL);
	}
	return (extract_line_and_update(&fd_unread));
}
