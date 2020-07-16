/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 15:04:48 by ivalenti          #+#    #+#             */
/*   Updated: 2020/02/22 21:33:58 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt_ceil(int n, int start, int end)
{
	int mid;
	int res;

	if (n == 0 || n == 1)
		return (n);
	else
	{
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (mid * mid == n)
				return (mid);
			if (mid * mid < n)
			{
				start = mid + 1;
				res = mid;
			}
			else
				end = mid - 1;
		}
		return (res + 1);
	}
}

int		fd_valid(int fd, t_figure **fig, int n, char *name)
{
	char	s[2];

	if (read(fd, s, 1) == 0)
		return (1);
	close(fd);
	fd = open(name, O_RDONLY);
	if (math_check(fd, s, n) == 1)
		return (1);
	close(fd);
	n = 64;
	fd = open(name, O_RDONLY);
	return (ft_read(fd, fig, n) == 0 || *fig == NULL);
}

void	fillit_algorithm(int size, t_figure *fig)
{
	t_mrow		*matr;
	int			sqrt;

	sqrt = ft_sqrt_ceil(size, 1, size);
	matr = form_matr(fig, sqrt);
	while (!printsol(matr, sqrt))
	{
		sqrt++;
		matr = form_matr(fig, sqrt);
	}
}

int		main(int argc, char **argv)
{
	t_figure	*fig;
	int			fd;

	fig = NULL;
	if (argc != 2)
		ft_putstr("usage: ./fillit source_file\n");
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0 || fd_valid(fd, &fig, 0, argv[1]) || ft_count_fig(fig) > 26)
		{
			close(fd);
			ft_exit();
		}
		else
		{
			close(fd);
			fillit_algorithm(ft_count_fig(fig) * 4, fig);
		}
	}
	return (0);
}
