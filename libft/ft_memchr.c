/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 00:01:59 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/20 00:01:59 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			count;
	unsigned char	*str1;

	c = (unsigned char)c;
	str1 = (unsigned char *) str;
	count = 0;
	while (count < n)
	{
		if (str1[count] == c)
			return ((void *)(str + count));
		count++;
	}
	return (NULL);
}
