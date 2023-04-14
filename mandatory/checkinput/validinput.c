/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:51:20 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	have_emptyline(char **map)
{
	while (*map)
	{
		if (**map == '\n')
			return (printf("❌Error: el mapa tiene al menos una linea vacia\n"));
		map++;
	}
	return (0);
}

int	validmap(char **map)
{
	if (have_emptyline(map))
		return (0);
	if (invalidchar_map(map))
		return (ft_free2((void **)map), map_invalidchar_error());
	if (players_map(map) != 1)
		return (players_error(players_map(map)), ft_free2((void **)map), 0);
	if (!closed_map(map))
		return (ft_free2((void **)map), map_close_error());
	ft_free2((void **)map);
	return (1);
}

int	validformat(char *path)
{
	if (!have_all_data(path))
		return (missingdata_error(path));
	if (!have_repeat_data(path))
		return (repeat_error(path));
	if (!valid_data(path))
		return (validdata_error(path));
	if (strange_id(path))
		return (strange_error(path));
	if (!validmap(get_raw_map(path)))
		return (map_error(path));
	return (1);
}

int	validinput(char *path)
{
	if (!validextension(path))
		return (extension_error(path, INPUT_EXTENSION));
	if (!readable(path))
		return (read_error(path));
	if (!validformat(path))
		return (format_error(path));
	return (1);
}
