/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:04:15 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/11 19:48:16 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

path_err	ft_init_path_errs(void)
{
	path_err	errs;

	errs.x = 0;
	errs.y = 0;
	errs.ex = 0;
	errs.clctbls = 0;
	errs.c_er = 0;
	return (errs);
}

map_err	ft_init_errs(void)
{
	map_err	errs;

	errs.inv_rowlen = 0;
	errs.inv_char = 0;
	errs.inv_n_ply = 0;
	errs.inv_n_collct = 0;
	errs.inv_n_exits = 0;
	errs.inv_borders = 0;
	return (errs);
}

char	*ft_strcat(char *s1, char *s2, int i, int j)
{
	char	*s;

	s = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (NULL);
	while (s1 && s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (s);
}
