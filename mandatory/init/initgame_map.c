/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:32:51 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 13:34:02 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*initgame_map(t_game *game, char *path)
{
	game->map = get_map(path);
	if (!(game->map))
	{
		printf("❗️Error leer el mapa\n");
		endgame(game);
	}
	return (game);
}