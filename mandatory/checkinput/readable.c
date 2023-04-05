/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:26:16 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/05 14:59:17 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	readable(char *path)
{
	int		fd;
	char	s[42];
	int		r;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (0);
	}
	r = read(fd, s, 42);
	sclose(fd);
	if (r < 0)
	{
		perror("read");
		return (0);
	}
	return (1);
}
