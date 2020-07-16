/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 14:15:35 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/24 17:51:13 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != '\0')
		{
			i++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	return (i);
}

static char		*ft_strdup_a(char *s1, char c)
{
	char	*s;

	s = s1;
	while (*s1 != '\0' && *s1 != c)
		s1++;
	*s1 = '\0';
	return (ft_strdup(s));
}

static char		**ft_free_all(char **mas, int j, char *s1)
{
	free(&mas[j]);
	while (j)
	{
		j--;
		free(&mas[j]);
	}
	free(*mas);
	free(s1);
	return (NULL);
}

static char		**ft_strspl(char const *s, char c)
{
	char	**mas;
	char	*s1;
	size_t	i;
	size_t	j;

	s1 = ft_strdup((char*)s);
	j = 0;
	i = ft_count(s, c);
	mas = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	if (mas)
		while (j < i && *s1 != '\0')
		{
			while (*s1 == c && *s1 != '\0')
				s1++;
			if (*s1 != '\0')
			{
				mas[j] = ft_strdup_a(s1, c);
				if (mas[j] == 0)
					return (ft_free_all(mas, j, s1));
				s1 += ft_strlen(mas[j]) + 1;
			}
			j++;
		}
	mas[j] = NULL;
	return (mas);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**mas;
	char	*s1;

	if (!s)
		return (NULL);
	s1 = ft_strdup((char*)s);
	if (!s1)
		return (NULL);
	mas = ft_strspl(s1, c);
	free(s1);
	return (mas);
}
