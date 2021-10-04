/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_memcmp.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/20 01:43:36 by jgomes-c		  #+#	#+#			 */
/*   Updated: 2021/05/20 01:43:36 by jgomes-c		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp (const void *str1, const void *str2, size_t n)
{
	size_t			count;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	count = 0;
	if (n == 0)
	{
		return (0);
	}
	while (count < n)
	{
		if (s1[count] != s2[count])
		{
			return ((unsigned char)s1[count] - (unsigned char)s2[count]);
		}
		count++;
	}
	return (0);
}
