/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:25:46 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/15 14:36:36 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_item(char *path, int i, int j, t_d *elmnt)
{
	int	w;
	int	h;

	elmnt->img = mlx_xpm_file_to_image(elmnt->id, path, &w, &h);
	if (!elmnt->img)
		ft_error("Error : corrupted xpm", elmnt->path);
	mlx_put_image_to_window(elmnt->id, elmnt->w_id, elmnt->img, 60 * j, 60 * i);
}

void	ft_display(char **map, t_d*elmnt)
{
	int	i;
	int	j;

	i = 0;
	while ((map[i]))
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				ft_display_item("./textures/wall.xpm", i, j, elmnt);
			if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'P')
				ft_display_item("./textures/background.xpm", i, j, elmnt);
			if (map[i][j] == 'P')
				ft_display_item("./textures/player.xpm", i, j, elmnt);
			if (map[i][j] == 'C')
				ft_display_item("./textures/collectible.xpm", i, j, elmnt);
			if (map[i][j] == 'E')
				ft_display_item("./textures/door.xpm", i, j, elmnt);
			j++;
		}
		i++;
	}
}

int	deal_key(int key, t_d *elmnt)
{
	t_p	p;

	p = ft_get_position(elmnt->path);
	if (key == ESC)
	{
		ft_printf("You closed the game using ESC key !");
		mlx_destroy_window(elmnt->id, elmnt->w_id);
		exit(0);
	}
	if (key == UP || key == 13)
		ft_move_up(p, elmnt);
	if (key == RIGHT || key == 2)
		ft_move_right(p, elmnt);
	if (key == LEFT || key == 0)
		ft_move_left(p, elmnt);
	if (key == DOWN || key == 1)
		ft_move_down(p, elmnt);
	return (0);
}

int	ft_exit(void)
{
	ft_printf("Exit the program with the X !!");
	exit(0);
}

void	game_init(t_d d)
{
	d.id = mlx_init();
	d.w_id = mlx_new_window(d.id, 60 * d.length, 60 * d.row, "so_long");
	ft_display(d.path, &d);
	mlx_hook(d.w_id, 2, 0, deal_key, &d);
	mlx_hook(d.w_id, 17, 0, ft_exit, &d);
	mlx_loop(d.id);
}
