/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:37:48 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/18 09:37:48 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset (void *str, int c, size_t n)
{
	size_t			count;
	unsigned char	*dest;

	dest = (unsigned char *)str;
	count = 0;
	while (n-- > 0)
	{
		dest[count] = (unsigned char)c;
		count++;
	}
	return (dest);
}
