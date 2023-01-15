/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:07:36 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/15 01:37:32 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up(t_p p, t_d *m)
{
	m->path[p.x][p.y] = '0';
	m->path[p.x - 1][p.y] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x - 1, p.y, m);
	ft_display_item("./textures/player.xpm", p.x - 1, p.y, m);
}

void	player_right(t_p p, t_d *m)
{
	m->path[p.x][p.y] = '0';
	m->path[p.x][p.y + 1] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x, p.y + 1, m);
	ft_display_item("./textures/player.xpm", p.x, p.y + 1, m);
}

void	player_left(t_p p, t_d *m)
{
	m->path[p.x][p.y] = '0';
	m->path[p.x][p.y - 1] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x, p.y - 1, m);
	ft_display_item("./textures/player.xpm", p.x, p.y - 1, m);
}

void	player_down(t_p p, t_d *m)
{
	m->path[p.x][p.y] = '0';
	m->path[p.x + 1][p.y] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x + 1, p.y, m);
	ft_display_item("./textures/player.xpm", p.x + 1, p.y, m);
}
