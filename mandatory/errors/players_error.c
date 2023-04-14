/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:44:12 by xmatute-          #+#    #+#             */
/*   Updated: 2023/04/14 19:09:55 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	players_error(size_t n)
{
	printf("❌Error: el mapa debería tener 1 único jugador en vez de %zu\n", n);
	return (0);
}
