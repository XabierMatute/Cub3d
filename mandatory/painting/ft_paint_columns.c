/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_columns.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:20:55 by jperez            #+#    #+#             */
/*   Updated: 2023/04/21 19:52:08 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_texture_index(t_game *game, double max_angle, int orientation)
{
	if (orientation == HORIZONTAL)
		return (ft_get_texture_x(game->player[x], game->player[y], max_angle, \
			game->map));
	else
		return (ft_get_texture_y(game->player[x], game->player[y], max_angle, \
			game->map));
}

t_img	*ft_choose_texture(t_game *game, int orientation, double max_angle)
{
	if (ft_angle_in_range(0, M_PI, max_angle) && orientation == HORIZONTAL)
		return (game->no_texture);
	else if (ft_angle_in_range(M_PI, 2 * M_PI, max_angle) && \
		orientation == HORIZONTAL)
		return (game->so_texture);
	else if (ft_angle_in_range(M_PI_2, M_PI_3_2, max_angle) && \
		orientation == VERTICAL)
		return (game->we_texture);
	else
		return (game->ea_texture);
}

void	ft_paint_column(t_game *game, t_img *img, int img_x, double max_angle)
{
	t_colision	*colision;
	double		wall_height;
	int			indexes[2];

	colision = ft_raycasting(game->player[x], game->player[y], max_angle, \
		game->map);
	wall_height = ft_calculate_wall_height(colision->distance);
	indexes[1] = ft_get_texture_index(game, max_angle, colision->orientation);
	indexes[0] = img_x;
	ft_paint_ceiling(img, img_x, wall_height, game->ceiling_color);
	ft_paint_wall(img, \
		ft_choose_texture(game, colision->orientation, max_angle), indexes, \
		wall_height);
	ft_paint_floor(img, img_x, wall_height, game->floor_color);
	free(colision);
}
