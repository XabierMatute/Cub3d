/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:49 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/05 18:23:00 by xmatute-         ###   ########.fr       */
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
	printf("k:%i x:%f y:%f angle:%f\n",k , game->player[x], game->player[y], game->player[angle]);
	return (0);
}

int	cubed(t_game	*game)
{
	put_floor(game->mlx, game->window, game->f_color);
	put_ceiling(game->mlx, game->window, game->c_color);
	mlx_hook(game->window, 2, (1L << 1), key_hook, game);//hay que hacer tambien lo de la x? si
	mlx_put_image_to_window(game->mlx, game->window, game->ea_texture->image, 0, 0);
	mlx_loop(game->mlx);
	return (endgame(game));
}