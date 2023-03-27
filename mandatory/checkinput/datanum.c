/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datanum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:47:36 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/25 20:17:41 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	datanum(char *path, char *id)
{
	int		fd;
	char	*line;
	int		n;

	n = 0;
	fd = open(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, id, ft_strlen(id)))
			n++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (n);
}
