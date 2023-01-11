/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 23:07:36 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/11 23:09:05 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_up(position p, map_elmnt *m)
{
	m->map[p.x][p.y] = '0';
	m->map[p.x - 1][p.y] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x - 1, p.y, m);
	ft_display_item("./textures/player.xpm", p.x - 1, p.y, m);
}

void	player_right(position p, map_elmnt *m)
{
	m->map[p.x][p.y] = '0';
	m->map[p.x][p.y + 1] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x, p.y + 1, m);
	ft_display_item("./textures/player.xpm", p.x, p.y + 1, m);
}

void	player_left(position p, map_elmnt *m)
{
	m->map[p.x][p.y] = '0';
	m->map[p.x][p.y - 1] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x, p.y - 1, m);
	ft_display_item("./textures/player.xpm", p.x, p.y - 1, m);
}

void	player_down(position p, map_elmnt *m)
{
	m->map[p.x][p.y] = '0';
	m->map[p.x + 1][p.y] = 'P';
	ft_display_item("./textures/background.xpm", p.x, p.y, m);
	ft_display_item("./textures/background.xpm", p.x + 1, p.y, m);
	ft_display_item("./textures/player.xpm", p.x + 1, p.y, m);
}
