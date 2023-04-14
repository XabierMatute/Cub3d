/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:53:37 by jperez            #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	ft_move(t_game *game)
{
	game->player[x] += cos(game->player[angle]) * 10;
	game->player[y] += sin(game->player[angle]) * 10;
}

void	ft_rotate(t_game *game, int keycode)
{
	if (keycode == LEFT_KEY)
		game->player[angle] += ANGLE_SPEED;
	else if (keycode == RIGHT_KEY)
		game->player[angle] -= ANGLE_SPEED;

	if (game->player[angle] >= 2 * M_PI)
		game->player[angle] -= 2 * M_PI;
	else if (game->player[angle] < 0)
		game->player[angle] += 2 * M_PI;
}

int	ft_main_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	ft_lightning_gun(game->map, game->player[angle], game);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == A_KEY || keycode == S_KEY || keycode == D_KEY || keycode == W_KEY)
		ft_move(game);
	else if (keycode == LEFT_KEY || keycode == RIGHT_KEY)
		ft_rotate(game, keycode);
	ft_lightning_gun(game->map, game->player[angle], game);
	return (0);
}
