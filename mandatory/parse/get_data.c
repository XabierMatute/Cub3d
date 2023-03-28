/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 14:31:34 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 17:26:40 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static	char	*parse_raw_data(char *line, int	idlen)
{
	char	*data;

	data = ft_strdup(line + idlen);
	free(line);
	return (data);
}

char	*get_raw_data(char *path, char *id)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, id, ft_strlen(id)))
		{
			close(fd);
			return (parse_raw_data(line, ft_strlen(id)));
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (0);
}

static	char	*parse_data(char *line, int	idlen)
{
	char	*data;
	size_t	i;
	size_t	f;

	i = idlen;
	while (line[i] == ' ')
		i++;
	f = i;
	while (line[f] && line[f] != ' ' && line[f] != '\n')
		f++;
	data = ft_substr(line, i, f - i);
	free(line);
	return (data);
}

char	*get_data(char *path, char *id)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	line = ft_get_next_line(fd);
	while (line)
	{
		if (!ft_strncmp(line, id, ft_strlen(id)))
		{
			close(fd);
			return (parse_data(line, ft_strlen(id)));
		}
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	return (0);
}