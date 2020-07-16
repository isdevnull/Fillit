/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 17:27:54 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/16 17:42:19 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_index(t_point p1, t_point p2, int n)
{
	return ((p1.x + p2.x) + (p1.y + p2.y) * n);
}

t_mrow	*skip(t_mrow *f)
{
	while ((f->next != NULL) && (f->id != '0'))
		f = f->next;
	return (f->next);
}

int		fig_is_valid(char *solution, t_mrow *figures)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (solution[figures->index[i]] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		ft_count_fig(t_figure *lst)
{
	t_figure	*tmp;
	int			cnt;

	tmp = lst;
	cnt = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		cnt++;
	}
	return (cnt);
}

void	free_matr(t_mrow *matr)
{
	t_mrow	*tmp;

	while (matr != NULL)
	{
		tmp = matr;
		matr = matr->next;
		free(tmp);
	}
}
