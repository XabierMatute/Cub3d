/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initgame_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:16:23 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 18:24:59 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_texture	*get_texture(void *mlx, char *path, char *id)
{
	t_texture	*texture;
	int			*w;
	int			*h;

	texture = ft_calloc(sizeof(t_texture), 1);
	w = &((texture->dimention)[x]);
	h = &(texture->dimention[y]);
	texture->image = mlx_xpm_file_to_image(mlx, get_data(path, id), w, h);
	if (!texture->image)
	{
		printf("💀Error con la textura \"%s\"\n", id);
		perror("");
		free(texture);
		texture = NULL;
	}
	return (texture);
}

t_game	*initgame_images(t_game *game, char *path)//pro
{
	game->no_texture = get_texture(game->mlx, path, "NO");	
	game->ea_texture = get_texture(game->mlx, path, "EA");
	game->so_texture = get_texture(game->mlx, path, "SO");
	game->we_texture = get_texture(game->mlx, path, "WE");
	return (game);
}