/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame_mlx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:35:49 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 19:13:34 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*initgame_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!(game->mlx))
	{
		printf("❗️Error al iniciar la mlx\n");
		endgame(game);
	}
	return (game);
}
