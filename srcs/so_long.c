/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:49:28 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/03 23:03:20 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	ft_is_map_valid(char *map_file, int *rows)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == ERROR)
		return (-1);
	if (ft_map_controler(fd, rows) == ERROR)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static int	ft_is_ber_file(char *map_file)
{
	int	dot_pos;

	dot_pos = ft_strchr_index(map_file, '.', -1);
	if (dot_pos == ERROR)
		return (0);
	else
	{	
		if ((ft_strncmp(map_file + dot_pos, ".ber", 5)) == 0 \
			&& (dot_pos != 0) \
			&& (*(map_file + dot_pos - 1) != '/'))
			return (1);
		else
			return (0);
	}
}

static int	ft_file_to_array(char *map_file, t_map **map, int rows)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == ERROR)
		return (0);
	if (ft_create_map(fd, map, rows) == ERROR)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

static int	ft_game_loop(t_map *map)
{
	void	*mlx;
	void	*win;
	t_param	*param;

	mlx = mlx_init();
	param = NULL;
	if (!mlx)
		return (ft_free_map(map, ERROR));
	win = mlx_new_window(mlx, map->cols * SSIZE, map->rows * SSIZE, "so long");
	if (!win)
		ft_free_mem(map, param, mlx, ERROR);
	if (ft_init_param(&param, mlx, win, map) == ERROR)
		ft_free_mem(map, param, mlx, ERROR);
	ft_draw_playground(map, param);
	mlx_do_key_autorepeaton(mlx);
	mlx_loop_hook(mlx, ft_render_next_frame, param);
	mlx_hook(win, 2, 1L << 0, ft_handle_key, param);
	mlx_hook(win, 17, 0L, ft_handle_close, param);
	mlx_loop(mlx);
	return (ft_free_mem(map, param, mlx, 0));
}

int	main(int ac, char **av)
{
	int		rows;
	int		map_check;
	t_map	*map;

	rows = 1;
	if (ac != 2)
		return (ft_exit_w_message("Error", NULL, 2, 1));
	if (!ft_is_ber_file(av[1]))
		return (ft_exit_w_message("Error", "File is not a BER file", 2, 1));
	map_check = ft_is_map_valid(av[1], &rows);
	if (map_check == ERROR)
		return (ft_exit_w_message("Error", NULL, 2, 1));
	else if (!map_check)
		return (ft_exit_w_message("Error", "MAP is not valid", 2, 1));
	map = NULL;
	if (ft_file_to_array(av[1], &map, rows) == ERROR)
		return (ft_exit_w_message("Error", NULL, 2, 1));
	if (ft_game_loop(map) == ERROR)
		return (ft_exit_w_message("Error", NULL, 2, 1));
	return (0);
}
