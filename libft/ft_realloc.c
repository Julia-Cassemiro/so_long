/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 10:04:55 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/04 10:29:25 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*new;

	if (!ptr)
	{
		new = (char *)malloc(sizeof(*new) * size);
		if (!new)
			return (ptr);
		return (new);
	}
	if (size == 0 && ptr)
	{
		new = (char *)malloc(sizeof(*new));
		if (!new)
			return (ptr);
		new[0] = 0;
		return (new);
	}
	new = (char *)malloc(sizeof(*new) * size);
	if (!new)
		return (ptr);
	new = ft_strcpy(new, ptr);
	free(ptr);
	return (new);
}
