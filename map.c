/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:52:25 by rexposit          #+#    #+#             */
/*   Updated: 2025/02/21 22:05:12 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_map_line(t_game *game, char *line, int y)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (y == 0)
		game->width = ft_strlen(line);
	game->map[y] = line;
	x = 0;
	while (x < game->width)
	{
		if (line[x] == 'P')
		{
			game->player_x = x;
			game->player_y = y;
		}
		x++;
	}
}

void	load_map(t_game *game, char *filename)
{
	int		fd;
	int		y;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: No se pudo abrir el archivo %s\n", filename);
		clean_exit(game);
	}
	game->map = malloc(100 * sizeof(char *));
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		process_map_line(game, line, y);
		line = get_next_line(fd);
		y++;
	}
	game->height = y;
	game->width = ft_strlen(game->map[0]);
	close(fd);
	validate_map(game);
}

void	validate_map_elements(t_game *game, int p_cnt, int e_cnt, int c_cnt)
{
	if (p_cnt != 1)
	{
		ft_printf("Error: El mapa debe tener exactamente 1 jugador ('P')\n");
		clean_exit(game);
	}
	if (e_cnt == 0)
	{
		ft_printf("Error: El mapa debe tener a menos una salida ('E')\n");
		clean_exit(game);
	}
	if (c_cnt == 0)
	{
		ft_printf("Error: El mapa debe tener al menos 1 coleccionable ('C')\n");
		clean_exit(game);
	}
}

void	check_collectible_and_border(t_game *game, int x, int y, int *c_cnt)
{
	if (game->map[y][x] == 'C')
		(*c_cnt)++;
	if ((y == 0 || y == game->height - 1 || x == 0
			|| x == game->width - 1) && game->map[y][x] != '1')
	{
		ft_printf("Error: El mapa debe estar cerrado con paredes\n");
		clean_exit(game);
	}
}

void	validate_map(t_game *game)
{
	int	p_cnt;
	int	e_cnt;
	int	c_cnt;
	int	y;
	int	x;

	p_cnt = 0;
	e_cnt = 0;
	c_cnt = 0;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
				p_cnt++;
			else if (game->map[y][x] == 'E')
				e_cnt++;
			check_collectible_and_border(game, x, y, &c_cnt);
			x++;
		}
		y++;
	}
	validate_map_elements(game, p_cnt, e_cnt, c_cnt);
}
