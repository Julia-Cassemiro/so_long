/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 10:25:06 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/25 10:25:06 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				count;
	unsigned char		*dest2;
	const unsigned char	*src2;
	unsigned char		*ret;

	count = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (count < n)
	{
		dest2[count] = src2[count];
		if (src2[count] == (unsigned char)c)
		{
			ret = dest2 + count + 1;
			return (ret);
		}
		count++;
	}
	return (NULL);
}
