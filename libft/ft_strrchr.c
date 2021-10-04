/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 00:45:04 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/21 00:45:04 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;
	int	i;

	c = (unsigned char)c;
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	count = i;
	while (count != 0)
	{
		if (str[count] == c)
		{
			return ((void *)(str + count));
		}
		count--;
	}
	if (str[count] == c)
	{
		return ((void *)(str + count));
	}
	return (NULL);
}
