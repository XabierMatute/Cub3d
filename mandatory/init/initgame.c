/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:51:26 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 19:12:16 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*initgame(char *path)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (printf("❗️Error de memoria parsear el input\n"), NULL);
	initgame_mlx(game);
	initgame_window(game);
	initgame_images(game, path);
	initgame_colors(game, path);
	initgame_player(game, path);
	initgame_map(game, path);
	return (game);
}
