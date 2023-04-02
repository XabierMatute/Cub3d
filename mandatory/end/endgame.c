/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:57:24 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/02 18:19:37 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	ft_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
}

int	endgame(t_game	*game)
{
	ft_free(game->map);
	endgame_images(game);
	ft_free(game->window);
	ft_free(game->mlx);
	ft_free(game);
	exit(0);
}