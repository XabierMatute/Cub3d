/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_wall_height.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:07:37 by jperez            #+#    #+#             */
/*   Updated: 2023/04/21 18:25:27 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_calculate_wall_height(double ray_distance)
{
	return ((UNIT / ray_distance) * SCREEN_DISTANCE);
}
