/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:04:14 by jperez            #+#    #+#             */
/*   Updated: 2023/04/20 20:13:00 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

double	ft_get_distance(double player_x, double player_y, double ray_x, double ray_y)
{
	return (sqrt(pow(ray_x - player_x, 2) + pow(ray_y - player_y, 2)));
}

//El error esta en que el map lo has puesto en las funciones como int
int	ft_check_wall(char **map, double ray_x, double ray_y)
{
	int	x;
	int	y;
	
	x = (int)floor(ray_x / UNIT);
	y = (int)floor(ray_y / UNIT);

	#ifdef DEBUG
	printf("Check_wall\n");
	printf("X: %d\n", x);
	printf("Y: %d\n", y);
	#endif

	if (!((0 <= x && x < (int)ft_strlen(map[0])) && (0 <= y && y < ft_args_len(map))))
		return (1);
	if ('0' < map[y][x] && map[y][x] <= '9')
		return (1);
	return (0);
}

int	ft_check_vertical_walls(char **map, double ray_x, double ray_y, double angle)
{
	int	x;
	int	y;
	
	x = (int)floor(ray_x / UNIT);
	y = (int)floor(ray_y / UNIT);

	#ifdef DEBUG
	printf("Check_wall\n");
	printf("X: %d\n", x);
	printf("Y: %d\n", y);
	#endif


	if (!ft_angle_in_range(M_PI_2, M_PI_3_2, angle))
	{
		if (!((0 <= x && x < (int)ft_strlen(map[0])) && (0 <= y && y < ft_args_len(map))))
			return (1);
		if ('0' < map[y][x] && map[y][x] <= '9')
			return (1);
	}
	else
	{
		x--;
		if (!((0 <= x && x < (int)ft_strlen(map[0])) && (0 <= y && y < ft_args_len(map))))
			return (1);
		if ('0' < map[y][x] && map[y][x] <= '9')
			return (1);
	}
	return (0);
}

int	ft_check_horizontal_walls(char **map, double ray_x, double ray_y, double angle)
{
	int	x;
	int	y;
	
	x = (int)floor(ray_x / UNIT);
	y = (int)floor(ray_y / UNIT);

	#ifdef DEBUG
	printf("Check_wall\n");
	printf("X: %d\n", x);
	printf("Y: %d\n", y);
	#endif


	if (!ft_angle_in_range(0, M_PI, angle))
	{
		if (!((0 <= x && x < (int)ft_strlen(map[0])) && (0 <= y && y < ft_args_len(map))))
			return (1);
		if ('0' < map[y][x] && map[y][x] <= '9')
			return (1);
	}
	else
	{
		y--;
		if (!((0 <= x && x < (int)ft_strlen(map[0])) && (0 <= y && y < ft_args_len(map))))
			return (1);
		if ('0' < map[y][x] && map[y][x] <= '9')
			return (1);
	}
	return (0);
}
