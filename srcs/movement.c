/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:24:05 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/20 11:06:46 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	place_player(t_game *game, int yy, int xx, char move)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.floor, xx * 50, yy * 50);
	if (move == 'W')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.player_back, xx * 50, yy * 50);
	if (move == 'S')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.player_front, xx * 50, yy * 50);
	if (move == 'A')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.player_left, xx * 50, yy * 50);
	if (move == 'D')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.player_right, xx * 50, yy * 50);
}

static int	is_movement_valid(t_game *game, int new_y, int new_x, char move)
{
	int	i;

	i = 0;
	if (game->map.matrix[new_y][new_x] == '1')
		i = 1;
	if (game->map.matrix[new_y][new_x] == 'E' && game->player.collectibles > 0)
		i = 1;
	if (i == 1)
	{
		place_player(game, game->player.y, game->player.x, move);
		game->player.moves++;
		printf("[\e[0;32mMOVES\e[0m] : %d\n", game->player.moves);
	}
	return (i);
}

static void	end_game(t_game *game, int yy, int xx)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
			game->assets.floor, xx * 50, yy * 50);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
			game->assets.exit, xx * 50, yy * 50);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
			game->assets.player_front, xx * 50, yy * 50);
	game->player.allow_movement = 0;
	mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, \
			((game->map.length * 50) / 2) - 100, ((game->map.height * 50) / 2) \
			, 0x00FF0000, "!!YOU WIN BOSS!! (PRESS ESC TO EXIT)");
}

static void	movement(t_game *game, int new_y, int new_x, char move)
{
	if (is_movement_valid(game, new_y, new_x, move))
		return ;
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.floor, game->player.x * 50, game->player.y * 50);
	if (game->map.matrix[new_y][new_x] == '0' || \
			game->map.matrix[new_y][new_x] == 'P')
		place_player(game, new_y, new_x, move);
	if (game->map.matrix[new_y][new_x] == 'C')
	{
		place_player(game, new_y, new_x, move);
		game->map.matrix[new_y][new_x] = '0';
		game->player.collectibles--;
	}
	if (game->map.matrix[new_y][new_x] == 'E')
		end_game(game, new_y, new_x);
	game->player.y = new_y;
	game->player.x = new_x;
	game->player.moves++;
	printf("[\e[0;32mMOVES\e[0m] : %d\n", game->player.moves);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game(game, 1);
	if (game->player.allow_movement == 0)
		return (0);
	if (keycode == MOVE_UP)
		movement(game, game->player.y - 1, game->player.x, 'W');
	if (keycode == MOVE_DOWN)
		movement(game, game->player.y + 1, game->player.x, 'S');
	if (keycode == MOVE_LEFT)
		movement(game, game->player.y, game->player.x - 1, 'A');
	if (keycode == MOVE_RIGHT)
		movement(game, game->player.y, game->player.x + 1, 'D');
	return (0);
}
