/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strncmp.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/05/21 10:40:19 by jgomes-c		  #+#	#+#			 */
/*   Updated: 2021/05/21 10:40:19 by jgomes-c		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp (const char *str1, const char *str2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (count < n - 1 && str1[count] == str2[count] && str1[count])
		count++;
	return ((unsigned char)str1[count] - (unsigned char)str2[count]);
}
