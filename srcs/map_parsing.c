/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:47:33 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/13 13:12:07 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	get_map_height(char *filename)
{
	int		fd;
	int		size;
	char	*str;

	fd = open(filename, O_RDONLY);
	size = 0;
	while (get_next_line(&str, fd))
		size++;
	close(fd);
	return (size);
}

static int	get_map_length(char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*str;

	fd = open(filename, O_RDONLY);
	j = 0;
	while (get_next_line(&str, fd))
	{
		i = 0;
		while (str[i])
			i++;
		if (i > j)
			j = i;
	}
	close(fd);
	return (j);
}

static void	map_parser(char *filename, char ***map)
{
	int		fd;
	int		j;
	char	*line;

	fd = open(filename, O_RDONLY);
	j = 0;
	while (get_next_line(&line, fd))
	{
		(*map)[j] = ft_strdup(line);
		j++;
	}
	close(fd);
}

static void	fix_multiple_player(t_game *game)
{
	int	i;
	int	j;
	int	playa;

	playa = 0;
	i = 0;
	while (game->map.matrix[i] && i < game->map.height)
	{
		j = 0;
		while (game->map.matrix[i][j])
		{
			if (game->map.matrix[i][j] == 'P')
			{
				if (playa == 0)
					playa = 1;
				else if (playa == 1)
					game->map.matrix[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void	map_parsing(t_game *game, char *filename)
{
	game->map.height = get_map_height(filename);
	game->map.length = get_map_length(filename);
	game->map.matrix = malloc(sizeof(char *) * game->map.height);
	map_parser(filename, &(game->map.matrix));
	fix_multiple_player(game);
}
