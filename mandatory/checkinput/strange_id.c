/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strange_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:41:04 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 18:44:48 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	valid_id(char	*line)
{
	if (!ft_strncmp(line, "NO", ft_strlen("NO")))
		return (1);
	if (!ft_strncmp(line, "SO", ft_strlen("SO")))
		return (1);
	if (!ft_strncmp(line, "EA", ft_strlen("EA")))
		return (1);
	if (!ft_strncmp(line, "WE", ft_strlen("WE")))
		return (1);
	if (!ft_strncmp(line, "F", ft_strlen("F")))
		return (1);
	if (!ft_strncmp(line, "C", ft_strlen("C")))
		return (1);
	return (0);
}

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
		else if (*line && *line != '\n')
			if (i < 6)
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