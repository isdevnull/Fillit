/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 18:34:03 by ivalenti          #+#    #+#             */
/*   Updated: 2020/02/12 14:05:17 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <fcntl.h>

typedef struct s_point	t_point;
typedef struct s_figure	t_figure;
typedef struct s_mrow	t_mrow;

struct		s_mrow
{
	int				index[4];
	char			id;
	struct s_mrow	*next;
};

struct		s_point
{
	int	x;
	int	y;
};

struct		s_figure
{
	char			id;
	struct s_point	p[4];
	struct s_figure *next;
};

int			char_check(char *s);
void		ft_compare(t_point	*delta, const int x, const int y);
t_point		*ft_delta(const char **content);
t_point		ft_onepoint(t_point *delta, const int x, const int y);
void		ft_setpoint(t_figure *new, const char **content);
t_figure	*ft_fignew(const char **content, char id);
int			is_figure_valid(const char **content, int adj_cnt);
void		ft_figadd(t_figure **head, t_figure *new);
int			ft_read(int fd, t_figure **fig, char id);
int			count_adjacent(const char **content, int y, int x);
t_mrow		*form_matr(t_figure *fig, int n);
void		increase(t_point *p, int n);
int			valvar(t_point p, t_figure *f, int n);
void		add_row(t_mrow **row, t_figure *f, int n, t_point p);
void		fill(int *str, t_figure *f, t_point p, int n);
int			ft_index(t_point p1, t_point p2, int n);
int			ft_sqrt_ceil(int n, int start, int end);
t_mrow		*skip(t_mrow *f);
int			fig_is_valid(char *solution, t_mrow *figures);
void		fill_sol(char *solution, t_mrow *figures);
void		ft_putstr3(char *s, int n);
int			printsol(t_mrow *figures, int n);
char		*ft_lastsol(char *solution, t_mrow *figures, int n);
char		*ft_solution(char *solution, t_mrow *figures, int n);
int			fd_valid(int fd, t_figure **fig, int n, char *name);
int			ft_count_fig(t_figure *lst);
void		fillit_algorithm(int size, t_figure *fig);
void		free_matr(t_mrow *matr);
void		ffree(char *matr[4]);
int			check_last(char *s, int i);
void		ft_exit();
int			math_check(int fd, char *s, int n);
#endif
