/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:37:30 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/11 20:56:21 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_elmnt(char *line, map_err *errs, map_elmnt *elmnt, int last_r)
{
	if (!elmnt->col && line)
		elmnt->col = ft_strlen(line) - 1;
	if (line && elmnt->col && ((ft_strchr(line, '\n')
				&& elmnt->col != ft_strlen(line) - 1) || (!ft_strchr(line, '\n')
				&& elmnt->col != ft_strlen(line))))
		errs->inv_rowlen = 1;
	if (line && (line[0] != '1' || line[elmnt->col - 1] != '1' || (last_r
				&& ft_countchar(line, '1') != elmnt->col)))
		errs->inv_borders = 1;
	elmnt->collct += ft_countchar(line, 'C');
	elmnt->exit += ft_countchar(line, 'E');
	elmnt->ply += ft_countchar(line, 'P');
	errs->inv_n_collct = elmnt->collct < 1;
	errs->inv_n_exits = elmnt->exit;
	errs->inv_n_ply = elmnt->ply;
	while (line && *line)
	{
		if (!ft_strchr("01CEP\n", *line))
			errs->inv_char = 1;
		line++;
	}
}

char	*ft_read_map(int fd, map_err *errs, map_elmnt *elmnt)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!elmnt->col)
				ft_error("Map is empty!", elmnt->map);
			else
				ft_check_elmnt(line, errs, elmnt, 1);
			free(last_line);
			break ;
		}
		ft_check_elmnt(line, errs, elmnt, !elmnt->row);
		last_line = ft_strcat(last_line, line, 0, 0);
		elmnt->row++;
	}
	return (last_line);
}

map_elmnt	ft_init_elmnt(void)
{
	map_elmnt	elmnt;

	elmnt.row = 0;
	elmnt.col = 0;
	elmnt.ply = 0;
	elmnt.exit = 0;
	elmnt.collct = 0;
	elmnt.mov_cnt = 0;
	elmnt.clc_cnt = 0;
	return (elmnt);
}

void	print_path_errs(map_elmnt *m, path_err e)
{
	if (m->collct != e.clctbls)
		ft_error("Invalid path to collectible !!", m->map);
	if (!e.ex)
		ft_error("Invalid path to the door !!", m->map);
}

void	check_path(int x, int y, path_err *e, char **path)
{
	if (path[x][y] && path[x][y] == 'C')
	{
		path[x][y] = 'K';
		e->clctbls++;
	}
	if (path[x][y] && (path[x][y] == '0' || path[x][y] == 'P'))
		path[x][y] = 'K';
	if (path[x + 1][y] == 'E' || path[x][y + 1] == 'E' || path[x - 1][y] == 'E'
		|| path[x][y - 1] == 'E')
		e->ex = 1;
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
