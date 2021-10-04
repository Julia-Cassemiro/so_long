/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:49:49 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/03 23:03:18 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_getmove(int key)
{
	int	i;
	int	res;
	int	kb[4];

	res = 0;
	kb[0] = K_UP;
	kb[1] = K_RIGHT;
	kb[2] = K_DOWN;
	kb[3] = K_LEFT;
	i = -1;
	while (++i < 4)
	{
		if (key == kb[i])
			res = i;
	}
	return (res);
}

int	ft_free_mem(t_map *map, t_param *param, void *mlx, int ret_code)
{
	if (map)
		ft_free_map(map, 0);
	if (param)
		ft_free_param(param, mlx, 0);
	else if (mlx)
	{
		if (DESTROYMLX)
			mlx_destroy_display(mlx);
		free(mlx);
	}
	if (ret_code == ERROR)
		exit(ft_exit_w_message("Error", NULL, 2, 1));
	exit(ret_code);
	return (ret_code);
}

int	ft_free_and_return(char *to_free, int to_return)
{
	if (to_free)
	{
		get_next_line(0, &to_free, 1);
		free(to_free);
	}
	to_free = NULL;
	if (to_return)
		return (to_return);
	return (-1);
}

int	ft_exit_w_message(char *message, char *message2, int fd, int code)
{
	ft_putstr_fd(message, fd);
	ft_putchar_fd('\n', fd);
	if (message2)
	{
		ft_putstr_fd(message2, fd);
		ft_putchar_fd('\n', fd);
	}
	return (code);
}
