/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:13:03 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/01 17:09:49 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10

# endif

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read_add_to_str(char *str, int fd);
char	*add_to_str(char *str, char *buffer, int readed);
char	*ft_str_to_line(char *str);
char	*ft_clean_str(char *str);
size_t	ftg_strlen(const char *s);
char	*ftg_strchr(const char *s, int c);
char	*ft_memcpy(char *dst, char *src, int index);
#endif