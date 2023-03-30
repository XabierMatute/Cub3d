/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_r_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:33:47 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 23:56:37 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	color_r_error(char *id)
{
	printf("❌Error: en %s hay caracteres fuera de rango\n", id);
	return (0);
}
