/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_open.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:52:10 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/05 14:58:50 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	map_start(char *path)
{
	int		fd;
	char	*line;
	size_t	i;
	size_t	s;

	s = 0;
	i = 0;
	fd = sopen(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (valid_id(line))
			i++;
		else if (i == 6 && *line != '\n')
		{
			free(line);
			return (sclose(fd), s - 1);
		}
		free(line);
		line = ft_get_next_line(fd);
		s++;
	}
	return (sclose(fd), s);
}

int	map_open(char *path)
{
	int		fd;
	char	*line;
	size_t	s;

	s = map_start(path);
	fd = sopen(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (s--)
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	return (fd);
}
