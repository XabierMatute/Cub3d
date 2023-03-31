/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:07:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/31 12:07:47 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

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
