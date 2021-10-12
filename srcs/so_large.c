/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/12 15:12:20 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	mlx_loop(game.mlx.mlx);
	free_map(&(game.map.matrix));
}
