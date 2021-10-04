/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:17:35 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/04 10:33:56 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_index(const char *s, int c, int offset)
{
	int	i;

	if (offset == -1)
	{
		i = ft_strlen(s);
		while (--i >= 0)
			if (s[i] == (char)c)
				return (i);
	}
	else
	{
		i = -1;
		while (s[++i + offset])
		{
			if (s[i + offset] == (char)c)
				return (i + offset);
		}
		if (c == 0 && s)
			return (i + offset);
	}
	return (-1);
}
