/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:15:09 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/15 14:20:57 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rotate_player(double player[3], double d)
{
	player[angle] += d;
	if (player[angle] >= 2 * M_PI)
		player[angle] -= 2 * M_PI;
	if (player[angle] < 0)
		player[angle] += 2 * M_PI;
	return (player[angle]);
}

int	look_left(t_game *game)
{
	return (rotate_player(game->player, ROTATE_SPEED));
}

int	look_right(t_game *game)
{
	return (rotate_player(game->player, (-1) * ROTATE_SPEED));
}
