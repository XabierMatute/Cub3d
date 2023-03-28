/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:51:20 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 17:40:53 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int	validmap(char **map)
// {
// 	if (invalidchar(map))
// 		return (map_invalidchar_error(map));
// 	if (!singleplayer(map))
// 		return (map_multiplayer_error(map));
// 	if (!closed(map))
// 		return (map_close_error(map));
// 	// if (have_emptyline(map))
// 	// 	return (map_emptyline_error(map));
// 	// if (have_space(map))
// 	// 	return (map_space_error(map));
// 	return (1);
// }

int	validformat(char *path)
{
	if (!have_all_data(path))
		return (missingdata_error(path));
	if (!have_repeat_data(path))
		return (repeat_error(path));
	if (!valid_data(path))//Colores R,G,B en rango [0,255]: 0, 255, 255
		return (validdata_error(path));
	if (strange_id(path))
		return (strange_error(path));
	// if (!validmap(get_map(path)))
	// 	return (map_error(path));
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
