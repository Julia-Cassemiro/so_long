/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:38:18 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/27 18:38:18 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t
	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	count;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dst);
	count = dest_len;
	i = 0;
	if (dest_len < size - 1 && size > 0)
	{
		while (src[i] && dest_len + i < size - 1)
		{
			dst[count] = src[i];
			count++;
			i++;
		}
		dst[count] = 0;
	}
	if (dest_len >= size)
		dest_len = size;
	return (dest_len + src_len);
}
