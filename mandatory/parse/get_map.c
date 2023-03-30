/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:23:56 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 20:25:41 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	map_start(char *path)
{
	int		fd;
	char	*line;
	size_t	i;
	size_t	s;

	s = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (valid_id(line))
			i++;
		else if (i == 6)
			if (*line != '\n')
			{
				free(line);
				return (close(fd), s - 1);
			}
		free(line);
		line = ft_get_next_line(fd);
		s++;
	}
	return (close(fd), s);
}

int	map_open(char *path)
{
	int		fd;
	char	*line;
	size_t	s;

	s = map_start(path);
	fd = open(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (s--)
	{
		free(line);
		line = ft_get_next_line(fd);
	}
	return (fd);
}

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

char	**get_raw_map(char *path)
{
	int		fd;
	size_t	height;
	size_t	i;
	char	**map;

	height = map_height(map_open(path));
	fd = map_open(path);
	i = 0;
	map = malloc((height + 1) * sizeof(char *));
	while (i < height)
	{
		map[i] = ft_get_next_line(fd);		
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
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
	parsed_line = malloc((width + 1) * sizeof(char));
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
	map = malloc((height + 1) * sizeof(char *));
	while (i < height)
	{
		map[i] = parse_line(ft_get_next_line(fd), width);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}

// char	**get_map(char *path)
// {

// }