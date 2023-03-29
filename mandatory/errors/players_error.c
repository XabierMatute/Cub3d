/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:44:12 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/29 17:46:33 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	players_error(size_t n)
{
	printf("❌Error: el mapa debería tener 1 único jugador en vez de %zu\n", n);
	return (0);
}
