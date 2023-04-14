/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strange_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:41:04 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	strange_id(char	*path)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	fd = sopen(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (valid_id(line))
			i++;
		else if (*line && *line != '\n' && i < 6)
		{
			printf("linea extraña:\n%s\n", line);
			free(line);
			sclose(fd);
			return (1);
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	sclose(fd);
	return (0);
}
