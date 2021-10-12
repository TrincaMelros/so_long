/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:47:33 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/12 13:52:42 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_height(char *filename)
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

int	get_map_length(char *filename)
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

void	map_parser(char *filename, char ***map)
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

void	free_map(char ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		i++;
	}
	free(*map);
}
