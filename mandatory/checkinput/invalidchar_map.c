/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalidchar_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:16:30 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/29 18:55:54 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_void(char c)
{
	return (c == '\n' || c == ' ' || c == '\0');
}

int	invalidchar(char c)
{
	if (c == '1')
		return (0);
	if (c == '0')
		return (0);
	if (is_void(c))
		return (0);
	if (is_player(c))
		return (0);
	return (1);
}

int	invalidchar_line(char *line)
{
	while (*line)
	{
		if (invalidchar(*line))
		{
			return(printf("caracter invalido: %c\n", *line));
		}
		line++;
	}
	return (0);
}

int	invalidchar_map(char **map)
{
	while (*map)
	{
		if (invalidchar_line(*map))
		{
			return(printf("\ten la linea: %s\n", *map));
		}
		map++;
	}
	return (0);
}