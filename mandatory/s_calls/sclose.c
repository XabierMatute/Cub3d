/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sclose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:30:31 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	sclose(int fd)
{
	int	i;

	i = close(fd);
	if (i < 0)
	{
		perror("close: ");
		exit(i);
	}
	return (i);
}
