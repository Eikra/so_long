/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:01:05 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/11 20:28:43 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

position	ft_get_position(char **path)
{
	position	p;

	p.x = 0;
	p.y = 0;
	while (path[p.x])
	{
		p.y = 0;
		while (path[p.x][p.y])
		{
			if (path[p.x][p.y] == 'P')
				return (p);
			p.y++;
		}
		p.x++;
	}
	return (p);
}

void	check_map(int fd, map_elmnt *elmnt)
{
	char		*map;
	map_err		errs;
	path_err	p_errs;
	position	p;

	map = NULL;
	errs = ft_init_errs();
	*elmnt = ft_init_elmnt();
	p_errs = ft_init_path_errs();
	map = ft_read_map(fd, &errs, elmnt);
	ft_print_errs(errs, elmnt);
	elmnt->map = ft_split(map, '\n');
	elmnt->path = ft_split(map, '\n');
	p = ft_get_position(elmnt->path);
	check_path(p.x, p.y, &p_errs, elmnt->path);
	ft_free(elmnt->path, elmnt->row);
	print_path_errs(elmnt, p_errs);
}

int	ft_error(char *err, char **path)
{
	int	i;

	i = 0;
	if (path)
		free(path);
	ft_printf("\033[0;91mError :\n\033[0;39m");
	ft_printf("    %s\n", err);
	exit(0);
	return (0);
}

int	check_args(int ac, char *av)
{
	int	fd;

	if (ac != 2)
		ft_error("Invalid number of arguments!", NULL);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		ft_error("File not found!", NULL);
	if (ft_strrncmp(av, ".ber", 4))
		ft_error("Invalid file type, use .ber!", NULL);
	return (fd);
}

int	main(int ac, char **av)
{
	int			fd;
	map_elmnt	elmnt;

	fd = check_args(ac, av[1]);
	check_map(fd, &elmnt);
	game_init(elmnt);
	return (0);
}
