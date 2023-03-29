/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:23:56 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/29 17:32:24 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	map_open(char *path)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	fd = open(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (valid_id(line))
			i++;
		else if (i == 6)
		{
			free(line);
			return (fd);
		}
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
	map[i] = ft_get_next_line(fd);
	close(fd);
	return (map);
}

// char	**get_map(char *path)
// {

// }