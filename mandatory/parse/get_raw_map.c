/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:07:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**get_raw_map(char *path)
{
	int		fd;
	size_t	height;
	size_t	i;
	char	**map;

	height = map_height(map_open(path));
	fd = map_open(path);
	i = 0;
	map = smalloc((height + 1) * sizeof(char *));
	while (i < height)
	{
		map[i] = ft_get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	sclose(fd);
	return (map);
}
