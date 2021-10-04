/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 00:21:23 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/21 00:21:23 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	count;
	int	i;

	c = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	count = 0;
	while (count < i)
	{
		if (str[count] == c)
		{
			return ((void *)(str + count));
		}
		count++;
	}
	if (str[count] == c)
	{
		return ((void *)(str + count));
	}
	return (NULL);
}
