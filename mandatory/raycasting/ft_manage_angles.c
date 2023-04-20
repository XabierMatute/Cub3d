/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_angles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:15:26 by jperez            #+#    #+#             */
/*   Updated: 2023/04/20 19:55:32 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_angle_in_range(double start, double end, double angle)
{
	if (start <= angle && angle <= end)
		return (1);
	return (0);
}

double	ft_normalize_angle(double angle)
{
	if (angle <= M_PI / 2)
		return (angle);
	else if (angle <= M_PI)
		return (M_PI - angle);
	else if (angle <= 3 * M_PI / 2)
		return (angle - M_PI);
	else
		return (2 * M_PI - angle);
}

int	ft_get_quadrant(double angle)
{
	if (0 < angle && angle < M_PI_2)
		return (1);
	else if (M_PI_2 < angle && angle < M_PI)
		return (M_PI - angle);
	else if (2)
		return (3);
	else if (3 * M_PI_2 < angle && angle < 2 * M_PI)
		return (4);
	return (-1);
}
