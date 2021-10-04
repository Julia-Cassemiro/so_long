/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:48:02 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/03 23:03:27 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_free_map(t_map *map, int ret_code)
{
	int	i;

	if (map)
	{
		if (map->map)
		{
			i = -1;
			while (++i < map->rows)
				free(map->map[i]);
			free(map->map);
		}
		free(map);
	}
	return (ret_code);
}

int	ft_init_map(t_map *map, int rows)
{
	int	i;

	map->map = (char **)malloc(sizeof(map->map) * rows);
	if (!map->map)
		return (ERROR);
	i = -1;
	while (++i < rows)
		map->map[i] = NULL;
	map->rows = rows;
	map->cols = 0;
	return (0);
}

void	ft_add_line(t_map *map, char *line)
{
	int	i;

	i = -1;
	while (++i < map->rows)
	{
		if (!map->map[i])
		{
			map->map[i] = line;
			break ;
		}
	}
	if (map->cols == 0)
		map->cols = ft_strlen(line);
}

int	ft_create_map(int fd, t_map **map, int rows)
{
	int		ret;
	char	*line;

	*map = (t_map *)malloc(sizeof(**map));
	if (!(*map))
		return (ERROR);
	if (ft_init_map(*map, rows) == ERROR)
		return (ERROR);
	line = NULL;
	ret = get_next_line(fd, &line, 0);
	while (ret > 0)
	{
		ft_add_line(*map, line);
		line = NULL;
		ret = get_next_line(fd, &line, 0);
	}
	if (ret == ERROR)
		return (ft_free_map(*map, ERROR));
	else
		ft_add_line(*map, line);
	return (0);
}
