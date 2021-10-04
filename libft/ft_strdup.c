/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 16:35:36 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/26 16:35:36 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*str;
	size_t	count;

	count = 0;
	str = (char *)malloc(sizeof(char) * ft_strlen(string) + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	while (string[count])
	{
		str[count] = string[count];
		count++;
	}
	str[count] = '\0';
	return (str);
}
