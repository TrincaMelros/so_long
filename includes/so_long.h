/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 13:54:21 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/12 16:56:34 by malmeida         ###   ########.fr       */
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

typedef	struct	s_assets {
	void		*floor;
	void		*wall;
	void		*exit;
	void		*collectible;
	void		*player_front;
	void		*player_back;
	void		*player_left;
	void		*player_right;
}				t_assets;

typedef	struct	s_mlx {
	void		*mlx;
	void		*mlx_win;
}				t_mlx;

typedef	struct	s_map {
	char		**matrix;
	int			height;
	int			length;
}				t_map;

typedef struct	s_player {
	int			x;
	int			y;
	int			moves;
}				t_player;

typedef	struct	s_game {
	t_mlx		mlx;
	t_assets	assets;
	t_map		map;
	t_player	player;
}				t_game;

void	map_printer(char **map);

		/*	Get Next line */
int		get_next_line(char **line, int fd);

		/* Map Parsing */
int		get_map_height(char *filename);
int		get_map_length(char *filename);
void	map_parser(char *filename, char ***map);
void	free_map(char ***map);

		/* Map and Image Loading */
void	map_loading(t_game *game);

		/* Map Validation */
int		map_validation(t_game game);

#endif
