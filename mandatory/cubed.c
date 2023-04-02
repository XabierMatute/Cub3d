/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:49 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 18:17:07 by xmatute-         ###   ########.fr       */
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

int	cubed(t_game	*game)
{
	put_floor(game->mlx, game->window, game->f_color);
	put_ceiling(game->mlx, game->window, game->c_color);
	mlx_put_image_to_window(game->mlx, game->window, game->ea_texture->image, 0, 0);
	mlx_loop(game->mlx);
	return (endgame(game));
}