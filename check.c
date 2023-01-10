/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:14:22 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/04 01:18:02 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check(int ac, char *av)
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

int	ft_error(char *err, char **map)
{
	int	i;

	i = 0;
	if (map)
		free(map);
	write(1, "\033[0;91mError\n", 16);
	write(1, "\033[0;39m", 9);
	while (err[i])
	{
		write(1, &err[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(0);
	return (0);
}





char	**check_map(int fd, map_elmnt *elmnt)
{
	char	*map;
	char	**path;
	map_err	errs;
	path_err	p_errs;
	position	p;
	//int i = 0;

	map = NULL;
	errs = ft_init_errs();
	*elmnt = ft_init_elmnt();
	p_errs=ft_init_path_errs();
	map = ft_read_map(fd, &errs, elmnt);
	ft_print_errs(errs);
	path = ft_split (map, '\n');
	p=ft_get_position(path);
	//printf("%d\n%d",p.x,p.y);
	check_path(p.x, p.y, &p_errs, path);
	print_path_errs(elmnt,p_errs, path);
	//printf("%d\n%d\n%d", p_errs.ex,p_errs.clctbls, elmnt->collct);
	// while (path[i])
	// {
	// 	printf("%s\n",path[i]);
	// 	i++;
	// }
	
	return(ft_split (map, '\n'));
}

position	ft_get_position(char **path)
{
	position	p;

	p.x=0;
	p.y=0;
	while (path[p.x])
	{
		p.y=0;
		while (path[p.x][p.y])
		{
			if(path[p.x][p.y]=='P')
				return(p);
			p.y++;
		}
		p.x++;
	}
	return(p);
}


void	check_path(int x,int y, path_err *e, char **path)
{
	//printf("%s\n%d\n",path[x],x);
	if(path[x][y] && path[x][y]== 'C')
	{
		path[x][y]= 'K';
		e->clctbls++;
	}
	//&& (path[x+1][y]== '0'||path[x][y+1]== '0' ||path[x-1][y]== '0'||path[x][y-1]== '0')
	if(path[x][y] && (path[x][y]== '0' || path[x][y]== 'P'))
		path[x][y]= 'K';
	if(path[x][y] && (path[x+1][y]== 'E'||path[x][y+1]== 'E' ||path[x-1][y]== 'E'||path[x][y-1]== 'E'))
	{
		e->ex=1;
		//path[x][y]= 'K';
	}
	if(path[x+1][y] && (path[x+1][y]== '0' ||path[x+1][y]== 'C'))
		check_path(x+1,y, e, path);
	if(path[x][y+1] && (path[x][y+1]== '0' ||path[x][y+1]== 'C'))
		check_path(x, y+1, e, path);
	if(x-1 > 0 && path[x-1][y] && (path[x-1][y]== '0' ||path[x-1][y]== 'C'))
		check_path(x-1, y, e, path);
	if(y-1 >0 && path[x][y-1] && (path[x][y-1]== '0' ||path[x][y-1]== 'C'))
		check_path(x,y-1, e, path);
	return;
}
void	print_path_errs(map_elmnt *m, path_err e, char **path)
{
	if(m->collct != e.clctbls)
		ft_error("Invalid path to collectible !!", path);
	if(!e.ex)
		ft_error("Invalid path to the door !!", path);
}


map_elmnt	ft_init_elmnt(void)
{
	map_elmnt	elmnt;

	elmnt.row = 0;
	elmnt.col = 0;
	elmnt.ply = 0;
	elmnt.exit = 0;
	elmnt.collct = 0;
	return (elmnt);
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
				ft_error("Map is empty!", NULL);
			else
				ft_check_elmnt(line, errs, elmnt, 1);
			free(last_line);
			break ;
		}
		//free(last_line);
		ft_check_elmnt(line, errs, elmnt, !elmnt->row);
		last_line = ft_strcat(last_line, line);
		//printf("%d\n", ft_strlen(line));
		//free(line);
		elmnt->row++;
	}
	return(last_line);
}
void	ft_check_elmnt(char *line, map_err *errs, map_elmnt *elmnt, int last_r)
{
	if (!elmnt->col && line)
		elmnt->col = ft_strlen(line) - 1;
	if (line && elmnt->col && ((ft_strchr(line,'\n') && elmnt->col != ft_strlen(line) - 1) || (!ft_strchr(line,'\n') && elmnt->col != ft_strlen(line))))
			errs->inv_rowlen = 1;
	if (line && (line[0] != '1' || line[elmnt->col - 1] != '1' || (last_r && ft_countchar(line, '1') != elmnt->col)))
		errs->inv_borders = 1;
	elmnt->collct += ft_countchar(line, 'C');
	elmnt->exit += ft_countchar(line, 'E');
	elmnt->ply += ft_countchar(line, 'P');
	errs->inv_n_collct = elmnt->collct < 1;
	errs->inv_n_exits = elmnt->exit;
	errs->inv_n_ply =  elmnt->ply;
	while (line && *line)
	{
		if (!ft_strchr("01CEP\n", *line))
			errs->inv_char = 1;
		line++;
	}
}


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
void	ft_print_errs(map_err errs)
{
	if(errs.inv_rowlen)
		ft_error("Invalid map to row length", NULL);
	if(errs.inv_char)
		ft_error("Invalid character !!", NULL);
	if(errs.inv_n_ply != 1)
		ft_error("Invalid map to player", NULL);
	// if(errs.inv_n_ghosts)
	// 	ft_error("Invalid map", NULL);
	if(errs.inv_n_collct)
		ft_error("Invalid path to collectible !!", NULL);
	if(errs.inv_n_exits != 1)
		ft_error("Invalid path to the door !!", NULL);
	if(errs.inv_borders)
		ft_error("Invalid map to borders", NULL);
}
char	*ft_strenlarge(char *s1, char *s2)
{
	int len_s1;
	int len_s2;
	char *s3;
	int i;

	if (s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[i] = s1[i];
		if (i < len_s2)
			s3[i + len_s1] = s2[i];
		i++;
	}
	s3[len_s1 + len_s2] = '\0';
	free(s1);
	free(s2);
	return (s3);
}

char	*ft_substr_ft(char *substr, char *s, int start,int sub_len)
{
	int	i;

	i = 0;
	while (i < sub_len && s[start + i])
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_substr(char *s,int start, int len)
{
	int	sub_len;
	char	*substr;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > (ft_strlen(s) - start))
		sub_len = ft_strlen(s) - start;
	if (len <= (ft_strlen(s) - start))
		sub_len = len;
	substr = (char *)malloc(sub_len + 1);
	if (!substr)
		return (NULL);
	return (ft_substr_ft(substr, s, start, sub_len));
}
//-----------
int	count_word(char *s, int c)
{
	int	i;
	int	count;
	int		done_null;

	count = 0;
	i = 0;
	done_null = 1;
	while (i < ft_strlen(s))
	{
		if (s[i] != c && s[i] && done_null > 0)
		{
			count++;
			done_null = -1;
		}
		if ((s[i] == c || !s[i]) && done_null < 0)
		{
			done_null = 1;
		}
		i++;
	}
	return (count);
}

char	*word_split(char *s, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 2));
	if (!word)
		return (NULL);
	while (start <= end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_free(char **s, int i)
{
	i--;
	while (s[i])
	{
		free(s[i]);
		i--;
	}
	free(s);
	return (NULL);
}

char	**ft_spliter(char **tab, char *s, char c)
{
	int	i;
	int	j;
	int	start;

	j = 0;
	i = -1;
	while (++i < ft_strlen(s))
	{
		start = i;
		while (s[i] != c && s[i])
		{
			if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			{
				tab[j] = word_split(s, start, i);
				if (tab[j] == NULL)
					return (ft_free(tab, j));
				j++;
			}
			i++;
		}
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char *s, char c)
{
	char	**tab;
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_spliter(tab, s, c);
	return (tab);
}