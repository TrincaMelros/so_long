/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 14:34:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/13 21:22:39 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_assets(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i] && i < game->map.height)
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.exit, j * 50, i * 50);
			if (game->map.matrix[i][j] == 'C')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.collectible, j * 50, i * 50);
			if (game->map.matrix[i][j] == 'P')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.player_front, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

static void	load_wall_floor(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.matrix[i] && i < game->map.height)
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == '0' || game->map.matrix[i][j] == 'E' \
					|| game->map.matrix[i][j] == 'C' \
					|| game->map.matrix[i][j] == 'P')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.floor, j * 50, i * 50);
			if (game->map.matrix[i][j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.wall, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

static void	player_assignment(t_game *game)
{
	int		width;
	int		height;
	char	*path;

	path = "./images/assets/player_front.xpm";
	game->assets.player_front = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
	path = "./images/assets/player_back.xpm";
	game->assets.player_back = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
	path = "./images/assets/player_left.xpm";
	game->assets.player_left = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
	path = "./images/assets/player_right.xpm";
	game->assets.player_right = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
}

static void	img_assignment(t_game *game)
{
	int		width;
	int		height;
	char	*path;

	path = "./images/assets/floor.xpm";
	game->assets.floor = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
	path = "./images/assets/wall.xpm";
	game->assets.wall = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
	path = "./images/assets/exit.xpm";
	game->assets.exit = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
	path = "./images/assets/collectible.xpm";
	game->assets.collectible = mlx_xpm_file_to_image(game->mlx.mlx, \
			path, &width, &height);
}

void	map_loading(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, game->map.length * 50, \
			game->map.height * 50, "42 Gameroni");
	img_assignment(game);
	player_assignment(game);
	load_wall_floor(game);
	load_assets(game);
}
