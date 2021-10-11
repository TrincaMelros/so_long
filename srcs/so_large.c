/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/11 15:22:05 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_rectangular(char **map)
{
	int	z;
	int	f;
	int	j;

	j = ft_strlen(map[0]);
	z = 1;
	while (map[z])
	{
		f = 0;
		while (map[z][f] != '\0')
			f++;
		if (f != j)
			return (1);
		z++;
	}
	return (0);
}

int	is_valid(char **map)
{
	int	exit;
	int	collectible;
	int	starting_pos;
	int	i;
	int	j;

	exit = 0;
	collectible = 0;
	starting_pos = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'C')
				collectible++;
			if (map[i][j] == 'P')
				starting_pos++;
			j++;
		}
		i++;
	}
}

int	map_validation(char **map, int i, int j)
{
	int	f;

	f = 0;
	if (is_rectangular(map))
		f = 1;
	if (is_valid(map))
		f = 1;
	return (f);
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
	if (map_validation(map, i, j))
	{
		printf("MAP ERROR\n");
		return (1);
	}
	map_loading(&game, map, i, j);
	mlx_loop(game.mlx.mlx);
	free_map(&map);
}
