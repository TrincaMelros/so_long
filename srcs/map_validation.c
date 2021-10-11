/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 16:48:55 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/11 17:09:42 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_rectangular(char **map)
{
	size_t	i;
	int		j;

	i = ft_strlen(map[0]);
	j = 1;
	while (map[j])
	{
		if (i != ft_strlen(map[j]))
		{
			return (1);
		}
		j++;
	}
	return (0);
}

static int	is_pos_valid(char **map)
{
	int	starting_pos;
	int	i;
	int	j;

	starting_pos = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
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

static int	is_valid(char **map)
{
	int	exit;
	int	collectible;
	int	i;
	int	j;

	exit = 0;
	collectible = 0;
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
			j++;
		}
		i++;
	}
	if (collectible > 0 && exit > 0)
		return (0);
	else
		return (1);
}

static int	is_closed(char **map, int i, int j)
{
	int	f;
	int	z;

	f = 0;
	while (map[0][f] && map[i - 1][f])
	{
		if (map[0][f] != '1' || map[i - 1][f] != '1')
			return (1);
		f++;
	}
	f = 0;
	while(map[f])
	{
		if (map[f][0] != '1' || map[f][j - 1] != '1')
			return (1);
		f++;
	}
	return (0);
}

int	map_validation(char **map, int i, int j)
{
	int	f;

	f = 0;
	if (is_rectangular(map))
	{
		f = 1;
		ft_putstr_fd("Error\nMap is not rectangular.\n", 1);
	}
	else if (is_valid(map))
	{
		f = 1;
		ft_putstr_fd("Error\nMap has no exit or collectibles.\n", 1);
	}
	else if (is_pos_valid(map))
	{
		f = 1;
		ft_putstr_fd("Error\nMap doesn't have player starting position.\n", 1);
	}
	else if (is_closed(map, i, j))
	{
		f = 1;
		ft_putstr_fd("Error\nMap is not enclosed by walls.\n", 1);
	}
	return (f);
}
