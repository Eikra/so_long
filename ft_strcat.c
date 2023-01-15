/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 22:14:54 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/15 14:39:10 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
