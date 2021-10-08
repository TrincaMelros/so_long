/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:54:21 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/08 13:20:35 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

#define BUFFER_SIZE 1

		/*	Get Next line */
int		get_next_line(char **line, int fd);
void	*ft__calloc(size_t nmemb, size_t size);

		/* Map Parsing */
int		get_map_size(char *filename);
void	map_parser(char *filename, char ***map);
void	matrix_printer(char **matrix);
void	free_map(char ***map);

#endif
