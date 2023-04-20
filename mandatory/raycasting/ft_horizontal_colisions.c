/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horizontal_colisions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 17:06:04 by jperez            #+#    #+#             */
/*   Updated: 2023/04/20 19:20:09 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double	ft_get_ray_y(double player_y, double angle)
{
	if (ft_angle_in_range(0, M_PI, angle))
		return (floor(player_y / UNIT) * UNIT);
	else
		return (floor(player_y / UNIT) * UNIT + UNIT);
}

static double	ft_get_ray_x(double player_x, double player_y, double ray_y, \
	double angle)
{
	if (ft_angle_in_range(M_PI_2, M_PI_3_2, angle))
		return (\
		player_x - fabs(player_y - ray_y) / tan(ft_normalize_angle(angle)));
	else
		return (\
		player_x + fabs(player_y - ray_y) / tan(ft_normalize_angle(angle)));
}

static void	ft_find_gap(double *ray_gap_x, double *ray_gap_y, double angle)
{
	if (ft_angle_in_range(0, M_PI, angle))
		*ray_gap_y = 0 - UNIT;
	else
		*ray_gap_y = UNIT;
	if (ft_angle_in_range(M_PI_2, M_PI_3_2, angle))
		*ray_gap_x = 0 - fabs(*ray_gap_y) / tan(ft_normalize_angle(angle));
	else
		*ray_gap_x = fabs(*ray_gap_y) / tan(ft_normalize_angle(angle));
}

double	ft_horizontal_colisions(double player_x, double player_y, \
	double angle, char **map)
{
	double	ray_x;
	double	ray_y;
	double	ray_gap_x;
	double	ray_gap_y;

	#ifdef DEBUG
	printf("--->Player_x: %f\n", player_x);
	printf("--->Player_y: %f\n", player_y);
	printf("--->Angle: %f\n", angle * 180 / M_PI);
	printf("\n");
	#endif
	ray_y = ft_get_ray_y(player_y, angle);
	ray_x = ft_get_ray_x(player_x, player_y, ray_y, angle);

	ft_find_gap(&ray_gap_x, &ray_gap_y, angle);

	#ifdef DEBUG
	printf("ray_x: %f\t(x: %d)\n", ray_x, (int)floor(ray_x / UNIT));
	printf("ray_y: %f\t(y: %d)\n", ray_y, (int)floor(ray_y / UNIT));
	printf("ray_gap_x: %f\n", ray_gap_x);
	printf("ray_gap_y: %f\n", ray_gap_y);
	printf("\n");
	#endif

	while (!ft_check_horizontal_walls(map, ray_x, ray_y, angle))
	{
		#ifdef DEBUG
		printf("ray_x: %f\n", ray_x);
		printf("ray_y: %f\n", ray_y);
		#endif

		ray_x += ray_gap_x;
		ray_y += ray_gap_y;
		
		#ifdef DEBUG
		printf(".-------------------------\n\n");
		#endif
	}
		#ifdef DEBUG
		printf("COISION_ray_x: %f\n", ray_x);
		printf("COLISION_ray_y: %f\n", ray_y);
		#endif
	return (ft_get_distance(player_x, player_y, ray_x, ray_y));
}
