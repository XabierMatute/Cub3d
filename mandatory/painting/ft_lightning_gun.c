/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lightning_gun.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:47:24 by jperez            #+#    #+#             */
/*   Updated: 2023/04/22 17:55:35 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*ft_send_height_and_angle(double wall_height, double angle)
{
	double	*output;

	output = (double *)malloc(sizeof(double) * 2);
	if (!output)
		exit(-1);
	output[0] = wall_height;
	output[1] = angle;
	return (output);
}

void	ft_lightning_gun(char **map, double angle, t_game *game)
{
	int		ray_x;
	double	min_angle;
	double	max_angle;
	t_img	*img;

	(void)map;
	ft_calculate_viewport(angle, &min_angle, &max_angle);
	ray_x = 0;
	mlx_clear_window(game->mlx, game->window);
	img = ft_create_img(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	while (ray_x < WIN_WIDTH)
	{
		ft_paint_column(game, img, ray_x, max_angle);
		max_angle -= FOV / WIN_WIDTH;
		if (max_angle < 0)
			max_angle += 2 * M_PI;
		ray_x++;
	}
	mlx_put_image_to_window(game->mlx, game->window, img->mlx_img, 0, 0);
	free(img);
}
