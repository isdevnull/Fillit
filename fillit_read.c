/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 15:14:06 by ivalenti          #+#    #+#             */
/*   Updated: 2020/02/16 17:24:57 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			char_check(char *s)
{
	if (ft_strlen(s) == 2 && *s == '\n')
		return (2);
	if ((ft_strlen(s) == 4 || ft_strlen(s) == 0) && *s != '\0')
	{
		while (*s != '\0')
		{
			if (!(*s == '.' || *s == '#' || *s == '\n'))
				return (0);
			if (*s == '\n' && ft_strlen(s) != 1)
				return (0);
			s++;
		}
		return (1);
	}
	return (0);
}

int			count_adjacent(const char **content, int y, int x)
{
	int cnt;

	cnt = 0;
	if (y > 0 && content[y - 1][x] == '#')
		cnt++;
	if (x > 0 && content[y][x - 1] == '#')
		cnt++;
	if (y < 3 && content[y + 1][x] == '#')
		cnt++;
	if (x < 3 && content[y][x + 1] == '#')
		cnt++;
	return (cnt);
}

int			is_figure_valid(const char **content, int adj_cnt)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (content[y][x] == '#')
			{
				adj_cnt += count_adjacent(content, y, x);
				i++;
			}
			x++;
		}
		y++;
	}
	if (i != 4 || !(adj_cnt == 6 || adj_cnt == 8))
		return (0);
	return (1);
}

void		ft_figadd(t_figure **head, t_figure *new)
{
	t_figure	*tmp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int			ft_read(int fd, t_figure **fig, char id)
{
	char		*s;
	char		*matr[4];
	int			i;

	i = 0;
	s = NULL;
	while ((get_next_line(fd, &s) > 0 && char_check(s) > 0) || i == 4)
	{
		if (*s == '\0')
			free(s);
		if (i == 4)
		{
			i = 0;
			if (is_figure_valid((const char **)matr, 0))
			{
				ft_figadd(fig, ft_fignew((const char **)matr, id++));
				ffree(matr);
			}
			else
				ft_exit();
		}
		else
			matr[i++] = s;
	}
	return (check_last(s, i));
}
