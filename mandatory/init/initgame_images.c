/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:16:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/16 19:51:31 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_img	*unify(void *mlx, t_img *texture)
{
	t_img	*img;
	int			i;
	int			j;

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
		printf("i:%i\n", i);
		while (j < UNIT)
		{
			printf(" j:%i\n", j);
			// printf("color[%i][%i]:%i\n", i * texture->height / UNIT, j * texture->width / UNIT, ft_get_texture_pixel(texture, i * (texture->height / UNIT), j * (texture->height / UNIT)));
			// printf("color[%i * %i / %i = %i][%i * %i / %i = %i]:%i\n", i, texture->height, UNIT, (i * texture->height / UNIT), j, texture->height, UNIT, j * texture->height / UNIT, ft_get_texture_pixel(texture, i * (texture->width / UNIT), j * (texture->width / UNIT)));
			my_mlx_pixel_put(img, i, j, ft_get_texture_pixel(texture, i * texture->width / UNIT, j * texture->height / UNIT));
			j++;
		}
		i++;
	}
	free_texture(texture);
	return(img);
}


t_img	*texture_error(t_img *texture, char *id)
{
	printf("💀Error con la textura \"%s\"\n", id);
	perror("");
	free(texture);
	texture = NULL;
	return (texture);
}

t_img	*get_img(void *mlx, char *path, char *id)
{
	t_img	*texture;
	char		*data;
	int			*w;
	int			*h;

	texture = ft_calloc(sizeof(t_img), 1);
	w = &(texture->width);
	h = &(texture->height);
	data = get_data(path, id);
	texture->mlx_img = mlx_xpm_file_to_image(mlx, data, w, h);
	free(data);
	if (!texture->mlx_img)
		return (texture_error(texture, id));
	texture->addr = mlx_get_data_addr(texture->mlx_img, &texture->bpp,
										&texture->line_len, &texture->endian);
	if (!texture->addr)
		return (texture_error(texture, id));
	// return (texture);
	return (unify(mlx, texture));
}



t_game	*initgame_images(t_game *game, char *path)
{
	game->no_texture = get_img(game->mlx, path, "NO");
	game->ea_texture = get_img(game->mlx, path, "EA");
	game->so_texture = get_img(game->mlx, path, "SO");
	game->we_texture = get_img(game->mlx, path, "WE");
	if (!game->no_texture || !game->ea_texture
		|| !game->so_texture || !game->we_texture)//aqui no sales?
		endgame(game);
	return (game);
}
