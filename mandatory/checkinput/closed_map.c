/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:16:30 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/31 10:51:06 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	closed(char **map, size_t i, size_t j)
{
	if (i == 0 || j == 0)
		return (0);
	if (!map[i + 1])
		return (0);
	if (!map[i][j + 1])
		return (0);
	if (j > ft_strlen(map[i + 1]) || j > ft_strlen(map[i - 1]))
		return (0);
	if (is_void(map[i + 1][j]))
		return (0);
	if (is_void(map[i - 1][j]))
		return (0);
	if (is_void(map[i][j + 1]))
		return (0);
	if (is_void(map[i][j - 1]))
		return (0);
	return (1);
}

int	closed_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((map[i][j] == '0' || is_player(map[i][j]))
				&& !closed(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
