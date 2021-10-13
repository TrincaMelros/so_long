/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:24:05 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/13 14:22:51 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	refresh_square(t_game *game, int yy, int xx)
{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.floor, xx * 50, yy * 50);
}

static void	place_player(t_game *game, int yy, int xx, char move)
{
	refresh_square(game, yy, xx);
	if (move == 'W')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.player_back, xx * 50, yy * 50);
	if (move == 'S')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.player_front, xx * 50, yy * 50);
	if (move == 'A')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, \
				game->assets.player_left, xx * 50, yy * 50);
	if (move == 'S')
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
		place_player(game, game->player.y, game->player.x, move);
	return (i);
}

static void	movement(t_game *game, int new_y, int new_x, char move)
{
	if (is_movement_valid(game, new_y, new_x, move))
		return ;
	refresh_square(game, game->player.y, game->player.x);
	if (game->map.matrix[new_y][new_x] == '0')
		place_player(game, new_y, new_x, move);
	if (game->map.matrix[new_y][new_x] == 'C')
	{
		place_player(game, new_y, new_x, move);
		game->map.matrix[new_y][new_x] = '0';
		game->player.collectibles--;
	}
	if (game->map.matrix[new_y][new_x] == 'E')
		exit_game(game);
	game->player.y = new_y;
	game->player.x = new_x;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(game);
	if (keycode == 13)
		movement(game, game->player.y - 1, game->player.x, 'W');
	if (keycode == 1)
		movement(game, game->player.y + 1, game->player.x, 'S');
	if (keycode == 0)
		movement(game, game->player.y, game->player.x - 1, 'A');
	if (keycode == 2)
		movement(game, game->player.y, game->player.x + 1, 'D');
	printf("I like turtles!\n");
	return (0);
}
