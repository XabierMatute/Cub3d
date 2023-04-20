/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:53:53 by jperez            #+#    #+#             */
/*   Updated: 2023/04/20 19:36:12 by jperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

double	ft_return_min(double horizontal_colision, double vertical_colision)
{
	if (vertical_colision < horizontal_colision)
		return (vertical_colision);
	else
		return (horizontal_colision);
}

double	ft_return_orientation(double horizontal_colision, double vertical_colision)
{
	if (vertical_colision < horizontal_colision)
		return (VERTICAL);
	else
		return (HORIZONTAL);
}

t_colision *ft_raycasting(double player_x, double player_y, double angle, char **map)
{
	t_colision	*colision;
	double	horizontal_colision;
	double	vertical_colision;


	colision = (t_colision *)malloc(sizeof(t_colision));
	#ifdef DEBUG
	printf("-------Horizontal-Colisions-------\n");
	#endif
	horizontal_colision = ft_horizontal_colisions(player_x, player_y, angle, map);

	#ifdef DEBUG
	printf("\n-------Vertical-Colisions-------\n");
	#endif
	vertical_colision = ft_vertical_colisions(player_x, player_y, angle, map);

	#ifdef DEBUG
	printf("\n");
	printf("Horizontal_colision: %f\n", horizontal_colision);
	printf("Vertical_colision: %f\n", vertical_colision);
	#endif

	colision->distance = ft_return_min(horizontal_colision, vertical_colision);
	colision->orientation = ft_return_orientation(horizontal_colision, vertical_colision);
	return (colision);
}
