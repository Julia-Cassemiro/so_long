/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 23:10:08 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/03 23:10:21 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_items(t_map *map, char item)
{
	int	row;
	int	col;
	int	res;

	res = 0;
	row = -1;
	while (++row < map->rows)
	{
		col = -1;
		while (++col < map->cols)
		{
			if (map->map[row][col] == item)
				++res;
		}
	}
	return (res);
}

int	ft_free_param(t_param *param, void *mlx, int ret_code)
{
	int	i;

	if (param->img)
	{
		i = -1;
		while (++i < NBSPRITES)
			mlx_destroy_image(mlx, param->img[i]);
	}
	free(param->img);
	mlx_destroy_image(mlx, param->playground->img);
	free(param->playground);
	mlx_destroy_window(param->mlx, param->win);
	if (DESTROYMLX)
		mlx_destroy_display(mlx);
	free(mlx);
	free(param);
	return (ret_code);
}

char	*ft_get_path(int i)
{
	char	path[50];

	path[0] = '\0';
	ft_strlcat(path, "theme/", 50);
	ft_strlcat(path, THEME, 50);
	ft_strlcat(path, "/", 50);
	ft_strlcat(path, &SPRITES[i * 2], ft_strlen(path) + 3);
	ft_strlcat(path, ".xpm", 50);
	return (ft_strdup(path));
}

int	ft_init_imgs(t_param *param, void *mlx)
{
	int		i;
	int		w;
	int		h;
	char	*path;

	param->img = (void **)malloc(sizeof(void *) * NBSPRITES);
	if (!param->img)
		return (ERROR);
	i = -1;
	while (++i < NBSPRITES)
	{
		path = NULL;
		path = ft_get_path(i);
		if (!path)
			return (ERROR);
		param->img[i] = mlx_xpm_file_to_image(mlx, path, &w, &h);
		free(path);
		if (!param->img[i])
			return (ERROR);
	}
	return (0);
}

int	ft_init_param(t_param **param, void *mlx, void *win, t_map *map)
{
	*param = (t_param *)malloc(sizeof(**param));
	if (!param)
		return (ERROR);
	(*param)->mlx = mlx;
	(*param)->win = win;
	(*param)->map = map;
	(*param)->img = NULL;
	(*param)->curr_items = 0;
	(*param)->curr_moves = 0;
	(*param)->total_items = ft_count_items(map, 'C');
	(*param)->is_on_exit = 0;
	(*param)->playground = ft_init_frame(*param);
	if (!(*param)->playground)
		return (ERROR);
	if (ft_init_imgs(*param, mlx) == ERROR)
		return (ERROR);
	return (0);
}
