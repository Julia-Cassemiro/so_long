/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:16:00 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/19 16:16:00 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	count;

	if (dest == src)
	{
		return (dest);
	}
	count = 0;
	while (count < n)
	{
		*(unsigned char *)(dest + count) = *(unsigned char *)(src + count);
		count++;
	}
	return (dest);
}
