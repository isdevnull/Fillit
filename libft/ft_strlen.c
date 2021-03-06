/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivalenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:00:40 by ivalenti          #+#    #+#             */
/*   Updated: 2019/09/15 21:13:47 by ivalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*s1;

	i = 0;
	s1 = (char*)s;
	while (*s1 != '\0')
	{
		s1++;
		i++;
	}
	return (i);
}
