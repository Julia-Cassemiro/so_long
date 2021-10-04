/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:07:24 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/04 10:29:37 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = -1;
	if (!src)
	{
		dst[0] = 0;
		return (dst);
	}
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}
