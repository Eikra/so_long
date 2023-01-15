/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:35:16 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/15 14:38:55 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_countchar(const char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str && str[j])
	{
		if (str[j] == c)
			i++;
		j++;
	}
	return (i);
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strrncmp(char *s, char *r, int n)
{
	int	i;
	int	j;

	i = ft_strlen(s) - 1;
	j = ft_strlen(r) - 1;
	while (n)
	{
		if (s[i] != r[j])
			return (1);
		n--;
		i--;
		j--;
	}
	return (0);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

t_p	ft_get_position(char **path)
{
	t_p	p;

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
