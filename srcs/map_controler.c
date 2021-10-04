/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_controler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 22:47:51 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/04 10:23:12 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_is_line_a_wall(char *line)
{
	int	i;

	i = -1;
	if (line)
	{
		while (line[++i])
		{
			if (line[i] != WALL)
				return (0);
		}
	}
	return (1);
}

int	ft_is_line_ok(char *line, size_t size, int *wall_chk)
{
	int	i;

	if (ft_strlen(line) != size)
		return (0);
	if (!wall_chk || *wall_chk)
	{
		if (wall_chk)
			*wall_chk = 0;
		if (!ft_is_line_a_wall(line))
			return (0);
		return (1);
	}
	i = -1;
	while (line[++i])
	{
		if (i == 0 && line[i] != WALL)
			return (0);
		if (ft_strchr_index(AUTHORIZED, line[i], 0) == ERROR)
			return (0);
	}
	if (i < 3)
		return (0);
	if (line[i - 1] != WALL)
		return (0);
	return (1);
}

int	ft_is_yet_char(const char *possibles, int c, int chk)
{
	int	sum;

	sum = 0;
	while (*possibles)
	{
		if (chk - c == *possibles || chk - c == sum)
			return (1);
		sum += (int)*possibles;
		++possibles;
	}
	if (chk - c == sum)
		return (1);
	return (0);
}

void	ft_mandatory_char_check(char *line, int *chk)
{
	if (ft_strchr(line, 'P') - line >= 0 && ft_is_yet_char("EC", 'P', *chk))
		*chk = -1;
	if (ft_strchr(line, 'E') - line >= 0 && !ft_is_yet_char("PC", 'E', *chk))
		*chk += 'E';
	if (ft_strchr(line, 'P') - line >= 0 && !ft_is_yet_char("EC", 'P', *chk))
		*chk += 'P';
	if (ft_strchr(line, 'C') - line >= 0 && !ft_is_yet_char("EP", 'C', *chk))
		*chk += 'C';
}

int	ft_map_controler(int fd, int *rows)
{
	int		ret;
	int		char_chk;
	int		wall_chk;
	size_t	len;
	char	*line;

	wall_chk = 1;
	char_chk = 0;
	ret = get_next_line(fd, &line, 0);
	if (ret != ERROR)
		len = ft_strlen(line);
	while (ret > 0)
	{
		++(*rows);
		if (!ft_is_line_ok(line, len, &wall_chk))
			return (ft_free_and_return(line, ERROR));
		ft_mandatory_char_check(line, &char_chk);
		free(line);
		line = NULL;
		ret = get_next_line(fd, &line, 0);
	}
	if (ret == -1 || char_chk != 216 || !ft_is_line_ok(line, len, NULL))
		return (ft_free_and_return(line, ERROR));
	free(line);
	return (0);
}
