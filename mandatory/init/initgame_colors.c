/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:30:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 17:41:32 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_game	*initgame_colors(t_game *game, char *path)
{
	game->ceiling_color = get_color(path, "C");
	game->floor_color = get_color(path, "F");
	return (game);
}
