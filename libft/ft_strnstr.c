/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 23:39:02 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/27 23:39:02 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cont1;
	size_t	cont2;

	cont1 = 0;
	cont2 = 0;
	if (*little == '\0')
		return ((char *)big);
	while (cont1 < len && big[cont1])
	{
		while (big[cont1 + cont2] == little[cont2]
			&& cont1 + cont2 < len && little[cont2] != '\0')
			cont2++;
		if (little[cont2] == '\0')
			return ((char *)big + cont1);
		cont1++;
		cont2 = 0;
	}
	return (NULL);
}
