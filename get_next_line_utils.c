/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:12:36 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/01 17:12:27 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ftg_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] != '\0')
		len++;
	return (len);
}

char	*ftg_strchr(const char *s, int c)
{
	while (s && *s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_memcpy(char *dst, char *src, int index)
{
	int	i;

	i = 0;
	while (src[index])
	{
		dst[i] = src[index];
		i++;
		index++;
	}
	dst[i] = '\0';
	return (dst);
}