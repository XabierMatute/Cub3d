/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:49 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/20 20:54:02 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int	refresh_frame(t_game *game)
{
	game->player[x] *= UNIT;
	game->player[y] *= UNIT;
	ft_lightning_gun(game->map, game->player[angle], game);
	game->player[x] /= UNIT;
	game->player[y] /= UNIT;
	putminimap(game, game->map, game->player);
	return (0);
}

int	key_hook(int k, t_game *game)
{
	if (k == LEFT_KEY)
		look_left(game);
	if (k == RIGHT_KEY)
		look_right(game);
	if (k == W_KEY || k == UP_KEY)
		move_forward(game);
	if (k == A_KEY)
		move_left(game);
	if (k == S_KEY || k == DOWN_KEY)
		move_back(game);
	if (k == D_KEY)
		move_right(game);
	if (k == ESC_KEY || k == Q_KEY)
		endgame(game);
	refresh_frame(game);
	return (0);
}

int	cubed(t_game	*game)
{
	refresh_frame(game);
	mlx_hook(game->window, 2, (1L << 1), key_hook, game);//hay que hacer tambien lo de la x? si
	mlx_loop(game->mlx);
	return (endgame(game));
}
