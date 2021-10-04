/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomes-c <jgomes-c@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 09:43:17 by jgomes-c          #+#    #+#             */
/*   Updated: 2021/10/02 12:18:21 by jgomes-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_fill_buffer_until_n(char **bufline, int fd)
{
	char	*buf;
	int		linelen;
	int		ret;

	buf = (char *)malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ERROR);
	while (!ft_strchr(*bufline, '\n'))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == 0 || ret == -1)
		{
			free(buf);
			return (ret);
		}
		buf[ret] = '\0';
		linelen = (ft_strchr(*bufline, 0) - *bufline) + ret + 1;
		*bufline = ft_realloc(*bufline, linelen);
		ft_strlcat(*bufline, buf, linelen);
	}
	free(buf);
	return (STD_LINE);
}

static int	ft_update_bufline(char **bufline)
{
	char	*tofree;
	int		nl_index;

	tofree = *bufline;
	nl_index = ft_strchr(*bufline, '\n') - *bufline;
	*bufline = ft_substr(*bufline, nl_index + 1, \
		(ft_strchr(*bufline, 0) - *bufline) - (nl_index + 1));
	if (!*bufline)
	{
		*bufline = tofree;
		return (ERROR);
	}
	free(tofree);
	return (0);
}

static int	ft_return_line(char **line, char **bufline, int status)
{
	int		nl_index;

	if (status == ERROR)
		return (ERROR);
	if (status == LAST_LINE)
	{
		*line = ft_substr(*bufline, 0, ft_strchr(*bufline, 0) - *bufline);
		if (!*line)
			return (ERROR);
		return (LAST_LINE);
	}
	else
	{
		nl_index = ft_strchr(*bufline, '\n') - *bufline;
		*line = ft_substr(*bufline, 0, nl_index);
		if (!*line)
			return (ERROR);
		if (ft_update_bufline(bufline) == ERROR)
			return (ERROR);
		return (STD_LINE);
	}
}

static int	ft_init_bufline(char **bufline)
{
	if (!*bufline)
	{
		*bufline = (char *)malloc(sizeof(**bufline) * (BUFFER_SIZE + 1));
		if (!*bufline)
			return (ERROR);
		*bufline[0] = 0;
	}
	return (0);
}

int	get_next_line(int fd, char **line, int to_free)
{
	static char	*bufline = NULL;
	int			result;

	if (to_free)
	{
		free(bufline);
		return (0);
	}
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || ft_init_bufline(&bufline) == -1)
		return (ERROR);
	result = ft_fill_buffer_until_n(&bufline, fd);
	if (ft_return_line(line, &bufline, result) == ERROR)
	{
		free(bufline);
		bufline = NULL;
		return (ERROR);
	}
	if (result == LAST_LINE)
	{
		free(bufline);
		bufline = NULL;
	}
	return (result);
}
