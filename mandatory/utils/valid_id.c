/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_id.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:49:57 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
