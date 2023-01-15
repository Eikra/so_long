/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 00:48:13 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/15 14:36:15 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_t_d(t_d *d)
{
	d->length = 0;
	d->row = 0;
	d->collectible = 0;
	d->exit = 0;
	d->player = 0;
	d->reached_e = 0;
	d->reached_c = 0;
	d->borders = 0;
	d->mov_cnt = 0;
	d->clc_cnt = 0;
	d->map = NULL;
	d->path = NULL;
}

void	ft_count_element(t_d *d)
{
	d->collectible = ft_countchar(d->map, 'C');
	if (!d->collectible)
		ft_error("No collectible !!", NULL);
	d->exit = ft_countchar(d->map, 'E');
	if (d->exit != 1)
		ft_error("Invalid path to the door !!", NULL);
	d->player = ft_countchar(d->map, 'P');
	if (d->player != 1)
		ft_error("Invalid map to player !!", NULL);
}

void	check_path(int x, int y, t_d *e, char **path)
{
	if (path[x][y] && path[x][y] == 'C')
	{
		path[x][y] = 'K';
		e->reached_c++;
	}
	if (path[x][y] && (path[x][y] == '0' || path[x][y] == 'P'))
		path[x][y] = 'K';
	if (path[x + 1][y] == 'E' || path[x][y + 1] == 'E' || path[x - 1][y] == 'E'
		|| path[x][y - 1] == 'E')
		e->reached_e = 1;
	if (path[x + 1][y] && (path[x + 1][y] == '0' || path[x + 1][y] == 'C'))
		check_path(x + 1, y, e, path);
	if (path[x][y + 1] && (path[x][y + 1] == '0' || path[x][y + 1] == 'C'))
		check_path(x, y + 1, e, path);
	if (path[x - 1][y] && (path[x - 1][y] == '0' || path[x - 1][y] == 'C'))
		check_path(x - 1, y, e, path);
	if (path[x][y - 1] && (path[x][y - 1] == '0' || path[x][y - 1] == 'C'))
		check_path(x, y - 1, e, path);
	return ;
}

void	check_borders(t_d *d)
{
	int	i;

	i = 0;
	if (d->map[ft_strlen(d->map) - 1] != '1')
		ft_error("Invalid map to borders !!", d->path);
	if (ft_countchar(d->path[0], '1') != d->length
		|| ft_countchar(d->path[d->row - 1], '1') != d->length)
		ft_error("Invalid map to borders !!", d->path);
	while (d->path[i])
	{
		if (d->path[i][0] != '1' || d->path[i][d->length - 1] != '1')
			ft_error("Invalid map to borders !!", d->path);
		i++;
	}
}

void	check_length(t_d *d)
{
	int	i;

	d->length = ft_strlen(d->path[0]);
	i = 1;
	while (d->path[i])
	{
		if (d->length != ft_strlen(d->path[i]))
			ft_error("Invalid map to row length !!", d->path);
		i++;
	}
}
