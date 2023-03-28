/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:43:19 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/28 12:44:22 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	color_error(char *id)
{
	printf("❌Error: el color %s no tiene un formato valido\n", id);
	return (0);
}
