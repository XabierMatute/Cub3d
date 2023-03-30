/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_n_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:05:56 by xmatute-          #+#    #+#             */
/*   Updated: 2023/03/30 23:56:34 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	color_n_error(char *id)
{
	printf("❌Error: en %s hay caracteres no numericos\n", id);
	return (0);
}
