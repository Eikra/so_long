/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 20:14:25 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/11 23:05:06 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10
# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

typedef struct gamme_elmnt
{
	int		row;
	int		col;
	int		ply;
	int		exit;
	int		collct;
	char	**map;
	char	**path;
	void	*id;
	void	*w_id;
	void	*img;
	int		mov_cnt;
	int		clc_cnt;
}				map_elmnt;

typedef struct elmnt_err
{
	int		inv_rowlen;
	int		inv_char;
	int		inv_n_ply;
	int		inv_n_collct;
	int		inv_n_exits;
	int		inv_borders;
}				map_err;

typedef struct path
{
	int		x;
	int		y;
	int		ex;
	int		clctbls;
	int		c_er;
}				path_err;

typedef struct player
{
	int		x;
	int		y;
}				position;

int			check_args(int ac, char *av);
int			ft_error(char *err, char **path);
int			ft_strrncmp(char *s, char *r, int n);
int			ft_strlen(char *s);
void		check_map(int fd, map_elmnt *elmnt);
map_err		ft_init_errs(void);
map_elmnt	ft_init_elmnt(void);
path_err	ft_init_path_errs(void);
char		*ft_read_map(int fd, map_err *errs, map_elmnt *elmnt);
void		ft_check_elmnt(char *line, map_err *errs, map_elmnt *elmnt,
				int last_r);
void		check_path(int x, int y, path_err *e, char **path);
void		print_path_errs(map_elmnt *m, path_err e);
position	ft_get_position(char **path);
char		*ft_strcat(char *s1, char *s2, int i, int j);
int			ft_strchr(const char *str, char c);
int			ft_countchar(const char *str, char c);
char		**ft_split(char *s, char c);
int			count_word(char *s, int c);
char		*word_split(char *s, int start, int end);
char		**ft_free(char **s, int i);
char		**ft_spliter(char **tab, char *s, char c);
char		*get_next_line(int fd);
void		ft_print_errs(map_err errs, map_elmnt *m);
int			deal_key(int key, map_elmnt *elmnt);
void		game_init(map_elmnt elmnt);
void		ft_display(char **map, map_elmnt *elmnt);
void		ft_display_item(char *path, int i, int j, map_elmnt *elmnt);
int			ft_move_up(position p, map_elmnt *m);
int			ft_move_right(position p, map_elmnt *m);
int			ft_move_left(position p, map_elmnt *m);
int			ft_move_down(position p, map_elmnt *m);
int			ft_printf(const char *s, ...);
int			ft_putchar_l(char c);
int			ft_putnbr_l(int n);
int			ft_putstr_l(char *s);
char		*get_next_line(int fd);
char		*ft_read_add_to_str(char *str, int fd);
char		*add_to_str(char *str, char *buffer, int readed);
char		*ft_str_to_line(char *str);
char		*ft_clean_str(char *str);
size_t		ftg_strlen(const char *s);
char		*ftg_strchr(const char *s, int c);
char		*ft_memcpy(char *dst, char *src, int index);
void		player_down(position p, map_elmnt *m);
void		player_left(position p, map_elmnt *m);
void		player_right(position p, map_elmnt *m);
void		player_up(position p, map_elmnt *m);

#endif
