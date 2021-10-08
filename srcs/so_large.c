/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_large.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:15:45 by malmeida          #+#    #+#             */
/*   Updated: 2021/10/08 13:24:38 by malmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		i;

	if (argc != 2)
		return (0);
	i = get_map_size(argv[1]);
	map = malloc(sizeof(char) * i);
	map_parser(argv[1], &map);
	matrix_printer(map);
	free_map(&map);
/*	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*alex_img;
	char	*path = "./images/floor";
	char 	*alex_path = "./images/alex.XPM";
	int		width;
	int		height;
	int		i;
	int		j;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 800, "Floor Bs");
	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	alex_img = mlx_xpm_file_to_image(mlx, alex_path, &width, &height);
	j = 0;
	while (j < 8)
	{
		i = 0;
		while (i < 8)
		{
			mlx_put_image_to_window(mlx, mlx_win, img, i * 100, j * 100);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, alex_img, 200, 200);
	mlx_loop(mlx);
*/
}
