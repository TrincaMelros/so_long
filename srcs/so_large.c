/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/13 14:19:10 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	start_game(t_game *game)
{
	int	i;
	int	j;
	int	player;

	game->player.collectibles = 0;
	player = 0;
	i = 0;
	while (game->map.matrix[i] && i < game->map.height)
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'C')
				game->player.collectibles++;
			if (game->map.matrix[i][j] == 'P' && player == 0)
			{
				game->player.y = i;
				game->player.x = j;
				player++;
			}
			j++;
		}
		i++;
	}
}

int	exit_game(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.matrix[i] && i < game->map.height)
	{
		free(game->map.matrix[i]);
		i++;
	}
	free(game->map.matrix);
	mlx_destroy_image(game->mlx.mlx, game->assets.floor);
	mlx_destroy_image(game->mlx.mlx, game->assets.wall);
	mlx_destroy_image(game->mlx.mlx, game->assets.exit);
	mlx_destroy_image(game->mlx.mlx, game->assets.collectible);
	mlx_destroy_image(game->mlx.mlx, game->assets.player_front);
	mlx_destroy_image(game->mlx.mlx, game->assets.player_back);
	mlx_destroy_image(game->mlx.mlx, game->assets.player_left);
	mlx_destroy_image(game->mlx.mlx, game->assets.player_back);
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	map_parsing(&game, argv[1]);
	if (map_validation(game))
		exit_game(&game);
	start_game(&game);
	map_loading(&game);
	mlx_hook(game.mlx.mlx_win, 17, (1L << 17), exit_game, &game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_loop(game.mlx.mlx);
}
