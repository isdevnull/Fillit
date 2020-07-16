/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:01:17 by ivalenti          #+#    #+#             */
/*   Updated: 2020/02/12 14:01:22 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_compare(t_point *delta, const int x, const int y)
{
	if (delta->x > x)
		delta->x = x;
	if (delta->y > y)
		delta->y = y;
}

t_point		*ft_delta(const char **content)
{
	t_point	*delta;
	int		x;
	int		y;

	delta = (t_point*)malloc(sizeof(t_point));
	if (!delta)
		return (NULL);
	delta->x = 5;
	delta->y = 5;
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (content[y][x] == '#')
				ft_compare(delta, x, y);
			x++;
		}
		y++;
	}
	return (delta);
}

t_point		ft_onepoint(t_point *delta, const int x, const int y)
{
	t_point	n;

	n.x = x - delta->x;
	n.y = y - delta->y;
	return (n);
}

void		ft_setpoint(t_figure *new, const char **content)
{
	t_point	*delta;
	int		x;
	int		y;
	int		i;

	i = 0;
	delta = ft_delta(content);
	y = 0;
	while (y < 5)
	{
		x = 0;
		while (x < 5)
		{
			if (content[y][x] == '#')
			{
				new->p[i++] = ft_onepoint(delta, x, y);
			}
			x++;
		}
		y++;
	}
	free(delta);
}

t_figure	*ft_fignew(const char **content, char id)
{
	t_figure *new;

	new = (t_figure*)malloc(sizeof(t_figure));
	if (!new)
		return (NULL);
	new->id = id + 1;
	ft_setpoint(new, content);
	new->next = NULL;
	return (new);
}
