/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_c_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:39:25 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 12:46:12 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	color_c_error(int c)
{
	printf("❌Error: deberia haber 3 colores R,G,B separados por comas");
	printf(", hay %i\n", c);
	return (0);
}