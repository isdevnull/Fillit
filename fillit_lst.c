/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:03:11 by ivalenti          #+#    #+#             */
/*   Updated: 2020/02/16 17:22:57 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill(int *str, t_figure *f, t_point p, int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		str[i] = ft_index(f->p[i], p, n);
		i++;
	}
}

void	add_row(t_mrow **row, t_figure *f, int n, t_point p)
{
	if (*row == NULL)
	{
		if (!(*row = (t_mrow *)malloc(sizeof(t_mrow))))
		{
			return ;
		}
		else
		{
			(*row)->id = f->id;
			(*row)->next = NULL;
			fill((*row)->index, f, p, n);
		}
	}
	else
		add_row(&(*row)->next, f, n, p);
}

int		valvar(t_point p, t_figure *f, int n)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (p.x + f->p[i].x < n)
		{
			if (p.y + f->p[i].y < n)
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

void	increase(t_point *p, int n)
{
	if (p->x + 1 < n)
		p->x++;
	else
	{
		p->y++;
		p->x = 0;
	}
}

t_mrow	*form_matr(t_figure *fig, int n)
{
	t_mrow		*matr;
	t_figure	*f;
	t_point		p;
	t_figure	delim;

	delim.id = '0';
	f = fig;
	matr = NULL;
	while (f != NULL)
	{
		p.x = 0;
		p.y = 0;
		while (p.x * n + p.y < n * n)
		{
			if (valvar(p, f, n))
				add_row(&matr, f, n, p);
			increase(&p, n);
		}
		f = f->next;
		add_row(&matr, &delim, n, p);
	}
	return (matr);
}
