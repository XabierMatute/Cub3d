/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:33:39 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/05 18:33:54 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	move(char **map, double	player[3], double angle)
{
	double	new_x;
	double	new_y;

	new_x = player[x] + cos(angle) * MOVE_SPEED;
	new_y = player[y] - sin(angle) * MOVE_SPEED;
	// printf("x:%f -> %f\n", player[x], new_x);
	// printf("y:%f -> %f\n", player[y], new_y);
	if (map[(int)floor((new_x + BASEBOARD))][(int)floor(player[y])] == '0')
		player[x] = new_x;
	if (map[(int)floor(player[x])][(int)floor((new_y + BASEBOARD))] == '0')
		player[y] = new_y;
	return (0);
}

int	move_forward(t_game *game)
{
	return (move(game->map, game->player, game->player[angle]));
}

int	move_left(t_game *game)
{
	return (move(game->map, game->player, game->player[angle] + M_PI / 2));
}
int	move_back(t_game *game)
{
	return (move(game->map, game->player, game->player[angle]  + M_PI));
}

int	move_right(t_game *game)
{
	return (move(game->map, game->player, game->player[angle] - M_PI / 2));
}
