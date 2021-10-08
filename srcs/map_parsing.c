/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:47:33 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/08 13:23:54 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_size(char *filename)
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

void	matrix_printer(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			printf("%c", matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
