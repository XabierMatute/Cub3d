/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:12:30 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texture(t_img	*texture)
{
	if (!texture)
		return ;
	ft_free(texture->mlx_img);
	ft_free(texture->addr);
	ft_free(texture);
}

void	endgame_images(t_game *game)
{
	free_texture(game->no_texture);
	free_texture(game->ea_texture);
	free_texture(game->so_texture);
	free_texture(game->we_texture);
}
