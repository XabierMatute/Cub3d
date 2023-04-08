/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:31:44 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/08 18:18:13 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	initplayer(double player[3], char c, double i, double j)
{
	player[x] = i + 0.5;
	player[y] = j + 0.5;
	if (c == 'N')
		player[angle] = NORTH;
	if (c == 'E')
		player[angle] = NORTH - M_PI / 2;
	if (c == 'W')
		player[angle] = NORTH + M_PI / 2;
	if (c == 'S')
		player[angle] = NORTH + M_PI;
}

t_game	*initgame_player(t_game *game, char *path)
{
	char	**map;
	size_t	i;
	size_t	j;

	map = get_raw_map(path);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]))
			{
				initplayer(game->player, map[i][j], i, j);
				break ;
			}
			j++;
		}
		i++;
	}
	return (game);
}
