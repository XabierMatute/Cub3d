/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:36:58 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 20:19:18 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"


size_t	players_line(char *line)
{
	size_t	players;

	players = 0;
	while (*line && *line != '\n')
	{
		if (is_player(*line))
			players++;		
		line++;
	}
	return (players);
}

size_t	players_map(char **map)
{
	size_t	players;

	players = 0;
	while (*map)
	{
		players += players_line(*map);
		map++;
	}
	return (players);
}