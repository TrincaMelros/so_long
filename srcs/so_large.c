/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/09 18:06:22 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	load_map(t_mlx *mlx, char **map)
{
	int	i;
	int	j;

	matrix_printer(map);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
					mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->floor, j * 50, i * 50);
			else if (map[i][j] == '1')
					mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->wall, j * 50, i * 50);
			j++;
		}
		i++;
	}
}

void	img_assign(t_mlx *mlx, int i, int j)
{
	int	width;
	int	height;

	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, j * 50, i * 50, "Tester");
	mlx->floor_path = "./images/floor.xpm";
	mlx->floor = mlx_xpm_file_to_image(mlx->mlx, mlx->floor_path, &width, &height);
	mlx->wall_path = "./images/wall.xpm";
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, mlx->wall_path, &width, &height);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	char	**map;
	int		i;
	int		j;

	if (argc != 2)
		return (0);
	i = get_map_height(argv[1]);
	j = get_map_length(argv[1]);
	map = malloc(sizeof(char *) * i);
	map_parser(argv[1], &map);
	img_assign(&mlx, i, j);
	load_map(&mlx, map);
	mlx_loop(mlx.mlx);
	free_map(&map);
}
