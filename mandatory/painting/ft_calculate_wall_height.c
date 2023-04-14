/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_wall_height.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 14:07:37 by jperez            #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

double	ft_calculate_wall_height(double ray_distance)
{
	double	output;

	#ifdef DEBUG
	printf("Ray_distance: %f\n", ray_distance);
	#endif

	output = (UNIT / ray_distance) * SCREEN_DISTANCE;
	if (output > WIN_HEIGHT)
		return (WIN_HEIGHT);
	return(output);
}
