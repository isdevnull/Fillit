/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbespin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:00:55 by hbespin           #+#    #+#             */
/*   Updated: 2020/02/23 00:17:57 by hbespin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ffree(char *matr[4])
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (matr[i] != NULL)
			free(matr[i]);
		i++;
	}
}

int		check_last(char *s, int i)
{
	if (char_check(s) == 0 || i != 0)
		ft_exit();
	if (*s == '\0')
		free(s);
	return (1);
}

void	ft_exit(void)
{
	ft_putstr("error\n");
	exit(-1);
}

int		math_check(int fd, char *s, int n)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (read(fd, s, 1))
	{
		if (*s == '.')
			i++;
		else if (*s == '#')
			k++;
		else if (*s == '\n')
			n++;
		if ((i + k + n) % 21 == 0 && *s != '\n')
			return (1);
	}
	if (3 * k != i || (k + k / 4 - 1) != n)
		return (1);
	return (0);
}
