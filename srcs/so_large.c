/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/12 16:56:31 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	movement(t_game *game)
{

}

int	exit_game(t_game *game)
{
	free_map(&(game->map.matrix));
	exit (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit_game(game);
	printf("I like turtles!\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (0);
	game.map.height = get_map_height(argv[1]);
	game.map.length = get_map_length(argv[1]);
	game.map.matrix = malloc(sizeof(char *) * game.map.height);
	map_parser(argv[1], &(game.map.matrix));
	if (map_validation(game))
		return (1);
	map_loading(&game);
	mlx_hook(game.mlx.mlx_win, 17, (1L << 17), exit_game, &game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_loop(game.mlx.mlx);
}
