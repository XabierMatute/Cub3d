/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_wall_height.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:07:37 by jperez            #+#    #+#             */
/*   Updated: 2023/04/22 17:54:21 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_calculate_wall_height(double ray_distance)
{
	return ((UNIT / ray_distance) * (WIN_WIDTH / 2) / tan(FOV / 2));
}
