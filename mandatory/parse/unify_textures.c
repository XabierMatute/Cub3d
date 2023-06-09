/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unify_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:18:53 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/20 19:28:56 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_img	*unify(void *mlx, t_img *t)
{
	t_img	*img;
	int		i;
	int		j;

	img = ft_calloc(sizeof(t_img), 1);
	img->mlx_img = mlx_new_image(mlx, UNIT, UNIT);
	img->width = UNIT;
	img->height = UNIT;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	i = 0;
	while (i < UNIT)
	{
		j = 0;
		while (j < UNIT)
		{
			my_mlx_pixel_put(img, i, j,
				ft_get_texture_pixel(t, i * t->width / UNIT,
					j * t->height / UNIT));
			j++;
		}
		i++;
	}
	free_texture(t);
	return (img);
}

t_img	*mirror_unify(void *mlx, t_img *t)
{
	t_img	*img;
	int		i;
	int		j;

	img = ft_calloc(sizeof(t_img), 1);
	img->mlx_img = mlx_new_image(mlx, UNIT, UNIT);
	img->width = UNIT;
	img->height = UNIT;
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	i = 0;
	while (i < UNIT)
	{
		j = 0;
		while (j < UNIT)
		{
			my_mlx_pixel_put(img, i, j,
				ft_get_texture_pixel(t, (UNIT - i - 1) * t->width / UNIT,
					j * t->height / UNIT));
			j++;
		}
		i++;
	}
	free_texture(t);
	return (img);
}
