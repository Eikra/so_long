/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:59:50 by iecharak          #+#    #+#             */
/*   Updated: 2023/01/04 00:36:39 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <mlx.h>
# include <stdarg.h>
//ARA3ISC

# define ESC 53
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

/* Struct to store and handle layout properties */
typedef struct gamme_elmnt
{
	int		row;
	int		col;
	int		ply;
	int		exit;
	int		collct;
	char    **map;
	void	*id;
	void	*w_id;
	void	*img;
	int mov_cnt;
	int clc_cnt;
}			map_elmnt;

/* Struct to handle all possible layout errors */
typedef struct elmnt_err
{
	int		inv_rowlen;
	int		inv_char;
	int		inv_n_ply;
	// int		inv_n_ghosts;
	int		inv_n_collct;
	int		inv_n_exits;
	int		inv_borders;
}			map_err;
typedef struct path
{
	int	x;
	int	y;
	int	ex;
	int	clctbls;
	int c_er;
}path_err;
typedef struct player
{
	int	x;
	int	y;
}		position;


int			check(int ac, char *av);
int			ft_error(char *err, char **map);
int			ft_strrncmp(char *s, char *r, int n);
int			ft_strlen(char *s);
char		**check_map(int fd, map_elmnt *elmnt);
map_err		ft_init_errs(void);
map_elmnt	ft_init_elmnt(void);
path_err	ft_init_path_errs(void);
char		*ft_read_map(int fd, map_err *errs, map_elmnt *elmnt);
void		ft_check_elmnt(char *line, map_err *errs, map_elmnt *elmnt,
				int last_r);
void	check_path(int x,int y, path_err *e, char **path);
void	print_path_errs(map_elmnt *m, path_err e, char **path);
position	ft_get_position(char **path);
char		*ft_strcat(char *s1, char *s2);
//get_next_line
//ft_substr
int			ft_strchr(const char *str, char c);
int			ft_countchar(const char *str, char c);
char		*ft_strenlarge(char *s1, char *s2);
char		*ft_substr(char *s, int start, int len);
char		**ft_split(char *s, char c);
int			count_word(char *s, int c);
char		*word_split(char *s, int start, int end);
char		**ft_free(char **s, int i);
char		**ft_spliter(char **tab, char *s, char c);
char		*get_next_line(int fd);
void	ft_print_errs(map_err errs);
int	deal_key(int key, map_elmnt *elmnt);
void game_init(map_elmnt elmnt);
void    ft_display(char **map,map_elmnt *elmnt);
void	ft_display_item(char *path,int i,int j,map_elmnt *elmnt);
int ft_move_up(position p, map_elmnt *m);
int ft_move_right(position p, map_elmnt *m);
int ft_move_left(position p, map_elmnt *m);
int ft_move_down(position p, map_elmnt *m);


int	ft_printf(const char *s, ...);
int	ft_putchar_l(char c);
int	ft_putnbr_l(int n);
int	ft_putstr_l(char *s);
int	ft_put_unbr_l(unsigned int n);
int	ft_hd_d_l(unsigned int n, char c);
int	ft_hdp_d_l(unsigned long n);

// size_t	ft_strlen(const char *s);
// char	*add_to_str(char *str, char *buffer, int readed);
// char	*ft_read_add_to_str(int fd);
// char	**ft_split(char const *s, char c);
// char	**ft_spliter(char **tab, char const *s, char c);
// char	**ft_free(char **s, int i);
// char	*word_split(char const *s, int start, int end);
// size_t	count_word(char const *s, int c);