/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/11 13:29:21 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_mapper(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.exit, j * 50, i * 50);
			j++;
		}
		i++;
	}

}

void	load_wall_floor(t_game *game, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.floor, j * 50, i * 50);
			else if (map[i][j] == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
						game->assets.wall, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	img_assign(t_game *game, int i, int j)
{
	int	width;
	int	height;

	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, j * 50, i * 50, "Tester");
	game->assets.floor_path = "./images/assets/floor.xpm";
	game->assets.floor = mlx_xpm_file_to_image(game->mlx.mlx, \
			game->assets.floor_path, &width, &height);
	game->assets.wall_path = "./images/assets/wall.xpm";
	game->assets.wall = mlx_xpm_file_to_image(game->mlx.mlx, \
			game->assets.wall_path, &width, &height);
	game->assets.exit_path = "./images/assets/exit.xpm";
	game->assets.exit = mlx_xpm_file_to_image(game->mlx.mlx, \
			game->assets.exit_path, &width, &height);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	**map;
	int		i;
	int		j;

	if (argc != 2)
		return (0);
	i = get_map_height(argv[1]);
	j = get_map_length(argv[1]);
	map = malloc(sizeof(char *) * i);
	map_parser(argv[1], &map);
	img_assign(&game, i, j);
	load_wall_floor(&game, map);
	load_mapper(&game, map);
	mlx_loop(game.mlx.mlx);
	free_map(&map);
}
