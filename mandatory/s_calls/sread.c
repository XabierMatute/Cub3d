/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sread.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:30:31 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/08 18:19:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

ssize_t	sread(int fd, void *buf, size_t b)
{
	ssize_t	i;

	i = read(fd, buf, b);
	if (i < 0)
	{
		perror("read: ");
		exit(i);
	}
	return (i);
}
