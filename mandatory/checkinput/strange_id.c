/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strange_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:41:04 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 18:50:18 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	strange_id(char	*path)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	fd = open(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (valid_id(line))
			i++;
		else if (*line && *line != '\n' && i < 6)
		{
			printf("linea extraña:\n%s\n", line);
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (0);
}
