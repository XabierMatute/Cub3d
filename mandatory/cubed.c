/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:49 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/05 19:06:00 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_ceiling(void *mlx, void *window, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = 0;
		while (j < WIN_HEIGHT / 2)
		{
			mlx_pixel_put(mlx, window, i, j, color);

			j++;
		}
		i++;
	}
}

void	put_floor(void *mlx, void *window, int color)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIN_WIDTH)
	{
		j = WIN_HEIGHT / 2;
		while (j < WIN_HEIGHT)
		{
			mlx_pixel_put(mlx, window, i, j, color);

			j++;
		}
		i++;
	}
}

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
			if(map[i][j] == '0')
				ft_fat_pixel(game, j * MM_TILE_SIZE, i * MM_TILE_SIZE, 0);
			j++;
		}
		i++;
	}
	return (0);
}

int	putplayer(t_game *game, double player[3])
{
	ft_fat_pixel(game, (int)(MM_TILE_SIZE * player[y]), (int)(MM_TILE_SIZE * player[x]), 16711680);
	// mlx_pixel_put(game->mlx, game->window, (int)floor(player[y]), (int)floor(player[x]), 16711680);
	return (0);
}

int	putminimap(t_game *game, char **map, double player[3])
{
	putfloor(game, map);
	putplayer(game, player);
	return(1);
}

int	key_hook(int k, t_game *game)
{
	// if (k == LEFT_KEY)
	// 	look_left(game);
	// if (k == RIGHT_KEY)
	// 	look_right(game);
	if (k == W_KEY)
		move_forward(game);
	if (k == A_KEY)
		move_left(game);
	if (k == S_KEY)
		move_back(game);
	if (k == D_KEY)
		move_right(game);
	if (k == ESC_KEY)
		endgame(game);
	putminimap(game, game->map, game->player);
	printf("k:%i x:%f y:%f angle:%f\n",k , game->player[x], game->player[y], game->player[angle]);
	return (0);
}

int	cubed(t_game	*game)
{
	put_floor(game->mlx, game->window, game->f_color);
	put_ceiling(game->mlx, game->window, game->c_color);
	mlx_hook(game->window, 2, (1L << 1), key_hook, game);//hay que hacer tambien lo de la x? si
	// mlx_put_image_to_window(game->mlx, game->window, game->ea_texture->image, 0, 0);
	mlx_loop(game->mlx);
	return (endgame(game));
}