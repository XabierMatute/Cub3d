/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:37:00 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 16:50:02 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	rgbtoint(int r, int g, int b)
{
	return(b + g * 256 + r * 256 * 256);
}

int	get_color(char *path, char *id)
{
	char	*data;
	char	**rgb;
	int		color;

	data = get_data(path, id);
	rgb = ft_split(data, ',');
	free(data);
	color = rgbtoint(ft_atoi(rgb[R]), ft_atoi(rgb[G]), ft_atoi(rgb[B]));
	ft_free2((void **)rgb);
	return(color);	
}