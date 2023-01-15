/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 21:38:08 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/15 14:17:22 by iecharak         ###   ########.fr       */
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

typedef struct data
{
	int		length;
	int		row;
	int		collectible;
	int		exit;
	int		player;
	int		reached_e;
	int		reached_c;
	int		borders;
	char	*map;
	char	**path;
	char	**str;
	void	*id;
	void	*w_id;
	void	*img;
	int		mov_cnt;
	int		clc_cnt;
}			t_d;

typedef struct position
{
	int		x;
	int		y;
}			t_p;

int			ft_printf(const char *s, ...);
int			ft_putchar_l(char c);
int			ft_putnbr_l(int n);
int			ft_putstr_l(char *s);
char		*get_next_line(int fd);
char		*ft_read_add_to_str(char *str, int fd);
char		*add_to_str(char *str, char *buffer, int readed);
char		*ft_str_to_line(char *str);
char		*ft_clean_str(char *str);
char		*ftg_strchr(const char *s, int c);
size_t		ftg_strlen(const char *s);
char		*ft_memcpy(char *dst, char *src, int index);
t_p			ft_get_position(char **path);
char		*ft_strcat(char *s1, char *s2, int i, int j);
int			ft_strchr(const char *str, char c);
int			ft_countchar(const char *str, char c);
char		**ft_split(char *s, char c);
int			count_word(char *s, int c);
char		*word_split(char *s, int start, int end);
char		**ft_free(char **s, int i);
char		**ft_spliter(char **tab, char *s, char c);
char		*get_next_line(int fd);
int			check_args(int ac, char *av);
int			ft_error(char *err, char **path);
void		ft_read_map(int fd, t_d *d);
int			ft_strlen(char *s);
void		game_init(t_d d);
void		ft_check_map(t_d *d);
void		ft_count_element(t_d *d);
int			ft_strchr(const char *str, char c);
int			ft_strrncmp(char *s, char *r, int n);
int			ft_countchar(const char *str, char c);
int			ft_exit(void);
int			deal_key(int key, t_d *elmnt);
void		ft_display(char **map, t_d *elmnt);
void		ft_display_item(char *path, int i, int j, t_d *elmnt);
int			ft_move_up(t_p p, t_d *m);
int			ft_move_right(t_p p, t_d *m);
int			ft_move_left(t_p p, t_d *m);
int			ft_move_down(t_p p, t_d *m);
void		player_up(t_p p, t_d *m);
void		player_right(t_p p, t_d *m);
void		player_left(t_p p, t_d *m);
void		player_down(t_p p, t_d *m);
void		ft_check_inv_char(t_d *d);
void		check_path(int x, int y, t_d *e, char **path);
void		check_borders(t_d *d);
void		check_length(t_d *d);
void		ft_init_t_d(t_d *d);

#endif