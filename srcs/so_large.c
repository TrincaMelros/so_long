/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/11 17:09:44 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	map_printer(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
	map_printer(map);
	if (map_validation(map, i, j))
		return (1);
	map_loading(&game, map, i, j);
	mlx_loop(game.mlx.mlx);
	free_map(&map);
}
