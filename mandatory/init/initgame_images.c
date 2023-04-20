/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:16:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/20 19:14:09 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	char	*data;
	int		*w;
	int		*h;

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
	if (id[0] == 'W' || id[0] == 'S')
		return (mirror_unify(mlx, texture));
	return (unify(mlx, texture));
}

t_game	*initgame_images(t_game *game, char *path)
{
	game->no_texture = get_img(game->mlx, path, "NO");
	game->ea_texture = get_img(game->mlx, path, "EA");
	game->so_texture = get_img(game->mlx, path, "SO");
	game->we_texture = get_img(game->mlx, path, "WE");
	if (!game->no_texture || !game->ea_texture
		|| !game->so_texture || !game->we_texture)
		endgame(game);
	return (game);
}
