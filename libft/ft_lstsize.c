/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 17:44:21 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/04 10:31:05 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_lstsize(t_list *lst)
{
	size_t		i;
	t_list		*list;

	list = lst;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
