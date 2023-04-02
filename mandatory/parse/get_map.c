/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:23:56 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/31 12:35:31 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

size_t	map_height(int fd)
{
	size_t	height;
	char	*line;

	height = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (height);
}

size_t	map_width(int fd)
{
	size_t	width;
	char	*line;

	width = 0;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > width)
			width = ft_strlen(line);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (width);
}

char	parsed_char(char c)
{
	if (is_void(c))
		return ('1');
	if (is_player(c))
		return ('0');
	return (c);
}

char	*parse_line(char *raw_line, size_t	width)
{
	char	*parsed_line;
	size_t	i;

	i = 0;
	parsed_line = smalloc((width + 1) * sizeof(char));
	while (raw_line[i])
	{
		parsed_line[i] = parsed_char(raw_line[i]);
		i++;
	}
	while (i < width)
	{
		parsed_line[i] = '1';
		i++;
	}
	parsed_line[i] = '\0';
	free(raw_line);
	return (parsed_line);
}

char	**get_map(char *path)
{
	int		fd;
	size_t	height;
	size_t	width;
	size_t	i;
	char	**map;

	height = map_height(map_open(path));
	width = map_width(map_open(path));
	fd = map_open(path);
	i = 0;
	map = smalloc((height + 1) * sizeof(char *));
	while (i < height)
	{
		map[i] = parse_line(ft_get_next_line(fd), width);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}
