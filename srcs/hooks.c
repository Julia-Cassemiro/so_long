/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:47:31 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/03 23:03:33 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_handle_key(int key, void *param)
{
	if (key == K_QUIT)
		ft_free_mem(((t_param *)param)->map, (t_param *)param, \
			((t_param *)param)->mlx, 0);
	if (key == K_UP || key == K_DOWN || key == K_LEFT || key == K_RIGHT)
	{
		if (ft_mover(param, ft_getmove(key)) == 1)
			ft_free_mem(((t_param *)param)->map, (t_param *)param, \
				((t_param *)param)->mlx, 0);
	}
	return (0);
}

int	ft_handle_close(void *param)
{
	ft_free_mem(((t_param *)param)->map, (t_param *)param, \
		((t_param *)param)->mlx, 0);
	return (0);
}

int	ft_render_next_frame(void *param)
{
	mlx_put_image_to_window(((t_param *)param)->mlx, ((t_param *)param)->win, \
		((t_param *)param)->playground->img, 0, TOP_GAP);
	return (0);
}
