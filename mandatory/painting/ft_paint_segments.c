/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_segments.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez <jperez@student.42urduliz.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:49:48 by jperez            #+#    #+#             */
/*   Updated: 2023/04/20 19:25:27 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_paint_ceiling(t_img *img, int img_x, double wall_height, int sky_color)
{
	int	img_y;
	int	end;

	end	= (WIN_HEIGHT - wall_height) / 2;
	img_y = -1;
	while (++img_y < end)
		my_mlx_pixel_put(img, img_x, img_y, sky_color);
}

void	ft_paint_floor(t_img *img, int img_x, double wall_height, int floor_color)
{
	int	img_y;

	img_y = (WIN_HEIGHT - wall_height) / 2 + wall_height;
	while (img_y < WIN_HEIGHT)
		my_mlx_pixel_put(img, img_x, img_y++, floor_color);
}

int	ft_get_wall_start(int wall_height, int *start_gap)
{
	if (wall_height > WIN_HEIGHT)
	{
		*start_gap = (int)floor((wall_height - WIN_HEIGHT) / 2);
		return (0);
	}
	else
	{
		*start_gap = 0;
		return ((WIN_HEIGHT - wall_height) / 2);
	}
}

# define IMG		0
# define TEXTURE	1
void	ft_paint_wall(t_img *img, t_img *texture, int indexes[], double wall_height)
{
	int		img_y;
	int		start;
	int		start_gap;
	float	scale;

	scale = texture->height / wall_height;
	start = ft_get_wall_start(wall_height, &start_gap) - 1;
	img_y = start;
	while (img_y < start + wall_height && img_y < WIN_HEIGHT)
	{
		my_mlx_pixel_put(img, indexes[IMG], img_y, ft_get_texture_pixel(texture, indexes[TEXTURE], (img_y - start + start_gap) * scale));
		img_y++;
	}
}
