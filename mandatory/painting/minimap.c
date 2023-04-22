/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 17:19:41 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/22 17:22:14 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_fat_pixel(t_game *game, int x, int y, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i <= MM_TILE_SIZE)
	{
		j = 0;
		while (j <= MM_TILE_SIZE)
		{
			if (x + i < WIN_WIDTH && y + j < WIN_HEIGHT)
				mlx_pixel_put(game->mlx, game->window, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

int	putfloor(t_game *game, char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
				ft_fat_pixel(game, j * MM_TILE_SIZE,
					i * MM_TILE_SIZE, 0);
			j++;
		}
		i++;
	}
	return (0);
}

int	putplayer(t_game *game, double player[3])
{
	ft_fat_pixel(game, (int)(MM_TILE_SIZE * (player[x] - 0.5)),
		(int)(MM_TILE_SIZE * (player[y] - 0.5)), 16711680);
	return (0);
}

int	putminimap(t_game *game, char **map, double player[3])
{
	putfloor(game, map);
	putplayer(game, player);
	return (1);
}
