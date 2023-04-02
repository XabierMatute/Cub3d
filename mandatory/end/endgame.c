/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:57:24 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 18:47:05 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	endgame(t_game	*game)
{
	ft_free(game->map);
	endgame_images(game);
	ft_free(game->window);
	ft_free(game->mlx);
	ft_free(game);
	exit(0);
}
