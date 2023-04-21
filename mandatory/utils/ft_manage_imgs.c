/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:41:56 by jperez            #+#    #+#             */
/*   Updated: 2023/04/21 18:08:55 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

# define WIDTH 2

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= WIN_WIDTH)
		x = WIN_WIDTH - 1;
	else if (x < 0)
		x = 0;
	if (y >= WIN_HEIGHT)
		y = WIN_HEIGHT - 1;
	else if (y < 0)
		y = 0;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

int ft_get_texture_pixel(t_img *img, int x, int y)
{
	char	*dst;

	if (x >= img->width)
		x = img->width - 1;
	else if (x < 0)
		x = 0;
	if (y >= img->height)
		y = img->height - 1;
	else if (y < 0)
		y = 0;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int*)dst);
}

t_img	*ft_create_img(void *mlx, int width, int height)
{
	t_img *img;

	img = (t_img *)malloc(sizeof(t_img));
	img->mlx_img = mlx_new_image(mlx, width, height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	return (img);
}

t_img	*ft_save_xpm(t_game *game, char *path)
{
	t_img	*img;


	img = (t_img *)malloc(sizeof(t_img));
	img->mlx_img = mlx_xpm_file_to_image(game->mlx, path, &img->width, &img->height);
	img->addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
	return(img);
}

