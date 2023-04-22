/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:49 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/22 17:42:18 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
