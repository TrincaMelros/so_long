/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:48:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/12 15:04:43 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangular(t_game game)
{
	int		i;
	int		j;

	i = ft_strlen(game.map.matrix[0]);
	j = 1;
	while (game.map.matrix[j] && j < game.map.height)
	{
		if (i != ft_strlen(game.map.matrix[j]))
		{
			return (1);
		}
		j++;
	}
	return (0);
}

static int	is_pos_valid(t_game game)
{
	int	starting_pos;
	int	i;
	int	j;

	starting_pos = 0;
	i = 0;
	while (game.map.matrix[i] && i < game.map.height)
	{
		j = 0;
		while (game.map.matrix[i][j])
		{
			if (game.map.matrix[i][j] == 'P')
				starting_pos++;
			j++;
		}
		i++;
	}
	if (starting_pos > 0)
		return (0);
	else
		return (1);
}

static int	is_valid(t_game game)
{
	int	exit;
	int	collectible;
	int	i;
	int	j;

	exit = 0;
	collectible = 0;
	i = 0;
	while (game.map.matrix[i] && i < game.map.height)
	{
		j = 0;
		while (game.map.matrix[i][j])
		{
			if (game.map.matrix[i][j] == 'E')
				exit++;
			if (game.map.matrix[i][j] == 'C')
				collectible++;
			j++;
		}
		i++;
	}
	if (collectible > 0 && exit > 0)
		return (0);
	else
		return (1);
}

static int	is_closed(t_game game)
{
	int	f;
	int	z;

	f = 0;
	while (game.map.matrix[0][f] && game.map.matrix[game.map.height - 1][f])
	{
		if (game.map.matrix[0][f] != '1' || \
				game.map.matrix[game.map.height - 1][f] != '1')
			return (1);
		f++;
	}
	f = 0;
	while (game.map.matrix[f] && f < game.map.height)
	{
		if (game.map.matrix[f][0] != '1' || \
				game.map.matrix[f][game.map.length - 1] != '1')
			return (1);
		f++;
	}
	return (0);
}

int	map_validation(t_game game)
{
	int	f;

	f = 0;
	if (is_rectangular(game))
	{
		f = 1;
		ft_putstr_fd("Error\nMap is not rectangular.\n", 1);
	}
	else if (is_valid(game))
	{
		f = 1;
		ft_putstr_fd("Error\nMap has no exit or collectibles.\n", 1);
	}
	else if (is_pos_valid(game))
	{
		f = 1;
		ft_putstr_fd("Error\nMap doesn't have player starting position.\n", 1);
	}
	else if (is_closed(game))
	{
		f = 1;
		ft_putstr_fd("Error\nMap is not enclosed by walls.\n", 1);
	}
	return (f);
}
