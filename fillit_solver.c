/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:02:18 by ivalenti          #+#    #+#             */
/*   Updated: 2020/02/22 22:02:06 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_sol(char *solution, t_mrow *figures)
{
	int i;

	i = 0;
	while (i < 4)
	{
		solution[figures->index[i]] = figures->id;
		i++;
	}
}

void	ft_putstr3(char *s, int n)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (i % n == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(s[i]);
		i++;
	}
}

int		printsol(t_mrow *figures, int n)
{
	char s[n * n + 1];

	ft_memset(s, '.', n * n);
	s[n * n] = '\0';
	if ((ft_solution(s, figures, n)) != NULL)
		ft_putstr3(s, n);
	else
	{
		free_matr(figures);
		return (0);
	}
	return (1);
}

char	*ft_lastsol(char *solution, t_mrow *figures, int n)
{
	char *c;

	while (figures != NULL && figures->id != '0')
	{
		c = ft_strdup(solution);
		if (fig_is_valid(solution, figures) == 1)
		{
			fill_sol(c, figures);
			ft_putstr3(c, n);
			ft_putchar('\n');
			free(c);
			free_matr(figures);
			exit(0);
		}
		free(c);
		figures = figures->next;
	}
	return (NULL);
}

char	*ft_solution(char *solution, t_mrow *figures, int n)
{
	char *c;

	if (skip(figures) == NULL)
		return (ft_lastsol(solution, figures, n));
	while (figures->id != '0')
	{
		c = ft_strdup(solution);
		if (fig_is_valid(solution, figures) == 1)
		{
			fill_sol(c, figures);
			if (skip(figures) != NULL)
				ft_solution(c, skip(figures), n);
		}
		free(c);
		figures = figures->next;
	}
	return (NULL);
}
