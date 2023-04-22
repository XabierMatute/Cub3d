/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_viewport.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:40:17 by jperez            #+#    #+#             */
/*   Updated: 2023/04/22 17:53:54 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double	ft_calculate_min_angle(double angle)
{
	if (angle == 0)
		return (2 * M_PI - FOV / 2);
	else if (angle + FOV / 2 > 2 * M_PI)
		return (angle - FOV / 2);
	else if (angle - FOV / 2 < 0)
		return (2 * M_PI + (angle - FOV / 2));
	else
		return (angle - FOV / 2);
}

static double	ft_calculate_max_angle(double angle)
{
	if (angle == 0)
		return (FOV / 2);
	else if (angle + FOV / 2 > 2 * M_PI)
		return (angle + FOV / 2 - 2 * M_PI);
	else if (angle - FOV / 2 < 0)
		return (angle + FOV / 2);
	else
		return (angle + FOV / 2);
}

void	ft_calculate_viewport(double angle, double *min_angle, \
	double *max_angle)
{
	*min_angle = ft_calculate_min_angle(angle);
	*max_angle = ft_calculate_max_angle(angle);
}
