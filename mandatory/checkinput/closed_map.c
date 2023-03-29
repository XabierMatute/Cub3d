/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:16:30 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/29 18:57:48 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

// int	closed(char c)
// {
// 	char	
// 	return (c);
// }

// int	closed_line(char *line, char **map)
// {
// 	if (*line == '0')
// 		return(0);
// 	while (line[1])
// 	{
// 		if (*line == '0' && !closed(*line))
// 		{
// 			return(0);
// 		}
// 		line++;
// 	}
// 	if (*line == '0')
// 		return(0);
// 	return (1);
// }

// int	closed_map(char **map)
// {
// 	char	**aux;

// 	aux = map;
// 	if (ft_strchr(*map, '0'))
// 			return(0);
// 	while (map[1])
// 	{
// 		if (!closed_line(*map, aux))
// 		{
// 			return(0);
// 		}
// 		map++;
// 	}
// 	if (ft_strchr(*map, '0'))
// 		return(0);
// 	return (1);
// }

int	closed(char **map, size_t i, size_t j)
{
	if (i == 0 || j == 0)
		return (0);
	if (!map[i + 1])
		return (0);
	if (!map[i][j + 1])
		return (0);
	if (i > ft_strlen(map[i + 1]) || i > ft_strlen(map[i - 1]))
		return (0);
	if (is_void(map[i + 1][j]))
		return (0);
	if (is_void(map[i - 1][j]))
		return (0);	
	if (is_void(map[i][j + 1]))
		return (0);
	if (is_void(map[i][j - 1]))
		return (0);
	return (1);
}

int	closed_map(char **map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && !closed(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}