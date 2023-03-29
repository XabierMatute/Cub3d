/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:16:30 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/29 18:20:14 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	closed(char c)
{
	if ((&c)[1] == '0' || (&c)[-1] == '0')
		return (0);
	return (1);
}

int	closed_line(char *line)
{
	if (*line == '0')
		return(0);
	while (line[1])
	{
		if (*line == '0' && !closed(*line))
		{
			return(0);
		}
		line++;
	}
	if (*line == '0')
		return(0);
	return (0);
}

int	closed_map(char **map)
{
	if (ft_strchr(*map, '0'))
		return(0);
	while (map[1])
	{
		if (closed_line(*map))
		{
			return(0);
		}
		map++;
	}
	if (ft_strchr(*map, '0'))
		return(0);
	return (1);
}