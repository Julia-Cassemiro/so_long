/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 20:16:41 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/05/27 20:34:55 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	count;
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (str == 0)
		return (NULL);
	count = 0;
	i = 0;
	while (s1[i] != '\0')
		str[count++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[count++] = s2[i++];
	str[count] = '\0';
	return (str);
}
