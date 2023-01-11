/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:59:51 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/11 23:10:32 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_up(position p, map_elmnt *m)
{
	if (m->map[p.x - 1][p.y] == 'E' && m->clc_cnt == m->collct)
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		ft_printf("CONGRATULATIONS, You won !!");
		free(m->map);
		exit(0);
		return (0);
	}
	else if (m->map[p.x - 1][p.y] == 'C')
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_up(p, m);
		m->mov_cnt++;
		m->clc_cnt++;
		return (1);
	}
	else if (m->map[p.x - 1][p.y] == '0')
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_up(p, m);
		m->mov_cnt++;
		return (1);
	}
	return (0);
}

int	ft_move_right(position p, map_elmnt *m)
{
	if (m->map[p.x][p.y + 1] == 'E' && m->clc_cnt == m->collct)
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		ft_printf("CONGRATULATIONS, You won !!");
		free(m->map);
		exit(0);
		return (0);
	}
	if (m->map[p.x][p.y + 1] == 'C')
	{
		m->clc_cnt++;
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_right(p, m);
		m->mov_cnt++;
		return (1);
	}
	if (m->map[p.x][p.y + 1] == '0')
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_right(p, m);
		m->mov_cnt++;
		return (1);
	}
	return (0);
}

int	ft_move_left(position p, map_elmnt *m)
{
	if (m->map[p.x][p.y - 1] == 'E' && m->clc_cnt == m->collct)
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		ft_printf("CONGRATULATIONS, You won !!");
		free(m->map);
		exit(0);
		return (0);
	}
	if (m->map[p.x][p.y - 1] == 'C')
	{
		m->clc_cnt++;
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_left(p, m);
		m->mov_cnt++;
		return (1);
	}
	if (m->map[p.x][p.y - 1] == '0')
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_left(p, m);
		m->mov_cnt++;
		return (1);
	}
	return (0);
}

int	ft_move_down(position p, map_elmnt *m)
{
	if (m->map[p.x + 1][p.y] == 'E' && m->clc_cnt == m->collct)
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		ft_printf("CONGRATULATIONS, You won !!");
		free(m->map);
		exit(0);
		return (0);
	}
	if (m->map[p.x + 1][p.y] == 'C')
	{
		m->clc_cnt++;
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_down(p, m);
		m->mov_cnt++;
		return (1);
	}
	if (m->map[p.x + 1][p.y] == '0')
	{
		ft_printf("Move nomber : %d\n", m->mov_cnt + 1);
		player_down(p, m);
		m->mov_cnt++;
		return (1);
	}
	return (0);
}
