/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:15:16 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/15 14:37:06 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_inv_char(t_d *d)
{
	int	i;

	i = 0;
	while (d->map[i])
	{
		if (!ft_strchr("01CEP\n", d->map[i]))
			ft_error("Invalid character !!", NULL);
		i++;
	}
}

void	ft_check_map(t_d *d)
{
	t_p	p;

	d->path = ft_split(d->map, '\n');
	d->str = ft_split(d->map, '\n');
	ft_check_inv_char(d);
	ft_count_element(d);
	check_length(d);
	check_borders(d);
	p = ft_get_position(d->path);
	check_path(p.x, p.y, d, d->str);
	if (!d->reached_e)
		ft_error("Invalid path to the door !!", d->path);
	if (d->reached_c != d->collectible)
		ft_error("Invalid path to collectible !!", d->path);
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

void	ft_read_map(int fd, t_d *d)
{
	char	*line;

	line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!d->row)
				ft_error("Map is empty!", NULL);
			break ;
		}
		d->map = ft_strcat(d->map, line, 0, 0);
		d->row++;
	}
}

int	main(int ac, char **av)
{
	int	fd;
	t_d	d;

	fd = check_args(ac, av[1]);
	ft_init_t_d(&d);
	ft_read_map(fd, &d);
	ft_check_map(&d);
	game_init(d);
	return (0);
}
