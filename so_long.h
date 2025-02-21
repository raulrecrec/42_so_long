/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rexposit <rexposit@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:42:24 by rexposit          #+#    #+#             */
/*   Updated: 2025/02/21 22:48:54 by rexposit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include "42_get_next_line/get_next_line.h"
# include "42_ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <string.h>
# include "42_Libft/libft.h"

# define TILE_SIZE 64
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

# define KEY_W XK_w
# define KEY_A XK_a
# define KEY_S XK_s
# define KEY_D XK_d
# define KEY_ESC XK_Escape

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	void	*wall;
	void	*floor;
	void	*player;
	void	*collectible;
	void	*exit;
	int		player_x;
	int		player_y;
}	t_game;

void	load_map(t_game *game, char *filename);
void	render_map(t_game *game, int x, int y);
void	load_textures(t_game *game);
void	validate_map(t_game *game);
void	free_resources(t_game *game);
void	clean_exit(t_game *game);
void	process_map_line(t_game *game, char *line, int y);
void	validate_map_elements(t_game *game, int p_cnt, int e_cnt, int c_cnt);
void	check_collectible_and_border(t_game *game, int x, int y, int *c_cnt);
void	handle_movement(int key, int *new_x, int *new_y, t_game *game);
int		check_remaining_collectibles(t_game *game);
int		handle_interactions_and_move(t_game *game, int new_x,
			int new_y, int *moves);
int		handle_keypress(int key, t_game *game);

#endif